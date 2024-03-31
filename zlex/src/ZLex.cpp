#include "ZLex.hpp"

void ZLex::buildDFA(bool debugMode, PAVec paVec, std::string outputFileName)
{
    NFA nfa(outputFileName);
    nfa.setDebugMode(debugMode);
    nfa.buildNFA(paVec);
    if (debugMode)
    {
        nfa.printFA();
    }
    dfa = new DFA(nfa);
    if (debugMode)
    {
        // nfa.printFA(); // 这样调用输出有问题, 懒得改了)
        dfa->printFA();
    }
}

int ZLex::lexicalAnalysis(std::ostream &outputStream, std::string fileName, std::wstreampos &pos)
{
    std::wifstream file(fileName); // 使用 std::wifstream 读取文件
    if (!file.is_open())
    {
        perror("文件打开失败");
        return -1;
    }

    // 设置文件的读取位置
    file.seekg(pos);

    std::wstring line; // 使用 std::wstring 存储每一行的内容
    yylineno = 0;      // 存储行号
    int start = dfa->getStartStateID();
    while (std::getline(file, line))
    {
        yylineno++; // 更新行号
        int current = start;
        int lastMatchLinePostion = -1;
        int lastMatchedState = -1;
        std::wstring lastMatched = L"";
        for (int i = 0; i < line.size(); i++)
        {
            wchar_t c = line[i];
            current = dfa->getNext(current, c);
            if (current == -1) // 无法匹配
            {
                if (lastMatchedState != -1)
                {
                    // 回退到上一个匹配的状态
                    i = lastMatchLinePostion;
                    current = lastMatchedState;
                    pos = file.tellg() + i * sizeof(wchar_t); // 使用 sizeof(wchar_t) 计算正确的字节偏移量

                    // 运行action
                    int token = dfa->runAction(lastMatchedState);
                    if (token != 0)
                    {
                        return token;
                    }
                }
                else
                {
                    outputStream << "Error at line " << yylineno << " position " << i << std::endl;
                    pos = file.tellg() + i * sizeof(wchar_t); // 使用 sizeof(wchar_t) 计算正确的字节偏移量
                    break;
                }
            }
            else // 成功匹配, 暂存, 继续匹配
            {
                lastMatched += c;
                lastMatchedState = current;
                lastMatchLinePostion = i;
            }
        }
    }
}
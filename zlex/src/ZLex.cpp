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

int ZLex::lexicalAnalysis(std::ostream &outputStream, std::string fileName)
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
        int lastMatchedState = -1;
        std::wstring lastMatched = L"";
        // 从上一次匹配的位置(pos_i)开始, 继续读取
        for (int i = pos_i; i < line.size(); i++)
        {
            char c = line[i];
            current = dfa->getNext(current, c);
            if (current == -1) // 无法匹配
            {
                if (lastMatchedState != -1)
                {
                    // 从上一次匹配的位置(pos_i)开始, 继续读取
                    i = pos_i;
                    // 运行action
                    int token = dfa->runAction(lastMatchedState);
                    if (token != 0) // action有返回值
                    {
                        return token;
                    }
                }
                else
                {
                    outputStream << "Error at line " << yylineno << " position " << i << std::endl;
                    break;
                }
            }
            else // 成功匹配, 暂存, 继续匹配
            {
                lastMatched += c;
                lastMatchedState = current;
                pos_i = i;
            }
        }
        // 一行读取完毕, 更新pos
        // 如果错误, 则是跳到下一行
        pos = file.tellg();
        pos_i = 0;
    }
}
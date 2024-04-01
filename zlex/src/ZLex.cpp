#include "ZLex.hpp"

// ZLex.cpp
std::string yytext; // 当前识别的字符串
int yylineno;       // 当前识别的行号

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
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        perror("文件打开失败");
        return -1;
    }

    // 设置文件的读取位置
    file.seekg(pos);

    std::string line;
    yylineno = 0; // 存储行号
    int start = dfa->getStartStateID();
    while (std::getline(file, line)) // Use regular getline function
    {
        yylineno++; // 更新行号
        int current = start;
        int lastMatchedState = -1;
        std::string lastMatched = "", afterMatched = "";
        // 从上一次匹配的位置(pos_i)开始, 继续读取
        for (int i = pos_i; i < line.size(); i++)
        {
            char c = line[i];
            current = dfa->getNext(current, c);
            if (current == -1) // 无法匹配
            {
                afterMatched += c;
                if (lastMatchedState != -1) // 存在更短的匹配
                {
                    i = pos_i; // 从上一次匹配的位置(pos_i)开始, 继续读取
                    // 运行action
                    int token = dfa->runAction(lastMatchedState);
                    // 重置状态机
                    current = start;
                    lastMatchedState = -1;
                    lastMatched = "";
                    afterMatched = "";
                    if (token != 0) // action有返回值
                    {
                        return token;
                    }
                }
                else // 不存在更短的匹配
                {
                    // 重置状态机
                    outputStream << std::endl
                                 << "[ERROR] at line " << yylineno
                                 << " position " << i
                                 << ":[" << afterMatched << "]" << std::endl;
                    current = start;
                    lastMatchedState = -1;
                    lastMatched = "";
                    afterMatched = "";
                    continue;
                }
            }
            else if (dfa->states[current].isAccepting)
            {
                lastMatched += afterMatched + c;
                afterMatched = "";
                lastMatchedState = current;
                yytext = lastMatched;
                pos_i = i;
            }
            else // 成功匹配, 暂存, 尝试更长的匹配
            {
                afterMatched += c;
            }
        }
        // 一行读取完毕, 更新pos
        pos = file.tellg();
        pos_i = 0;
    }
    return 0;
}
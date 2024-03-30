#include "ZLex.hpp"

void ZLex::buildDFA(bool debugMode, PAVec paVec, std::string outputFileName)
{
    NFA nfa(outputFileName);
    nfa.buildNFA(paVec);
}

void ZLex::lexicalAnalysis(DFA &dfa, std::ostream &outputStream, std::string fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        perror("文件打开失败");
        return;
    }

    std::string line;
    int lineNumber = 0; // 存储行号
    while (std::getline(file, line))
    {
        lineNumber++; // 更新行号
        std::string token;
        for (auto &ch : line)
        {
            // 处理每个字符
        }
    }
}
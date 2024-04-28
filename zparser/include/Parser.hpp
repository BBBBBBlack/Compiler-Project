#ifndef PARSER_HPP
#define PARSER_HPP

#define BANNER                                         \
    " _________   _    ____  ____  _____ ____  \n"     \
    "|__  /  _ \\ / \\  |  _ \\/ ___|| ____|  _ \\ \n" \
    "  / /| |_) / _ \\ | |_) \\___ \\|  _| | |_) |\n"  \
    " / /_|  __/ ___ \\|  _ < ___) | |___|  _ < \n"    \
    "/____|_| /_/   \\_\\_| \\_\\____/|_____|_| \\_\\\n"

#include "ParseTab.hpp"
#include "pch.hpp"
#include "Token.hpp"

class Parser
{
public:
    Parser(ParseTab &parseTab) : parseTab(parseTab) {}
    Parser(ParseTab &parseTab, std::string outputFile) : parseTab(parseTab)
    {
        setOutputFile(outputFile);
    }

    void setOutputFile(std::string fileName);

    void grammarAnalysis(std::string tokenFile, bool needProcess, std::string processFileName);
    /**
     * @brief 语法分析 从cin读取token流
     * @deprecated 请使用grammarAnalysis(std::string tokenFile, bool needProcess, std::string processFileName)
     */
    void grammarAnalysis(bool needProcess, std::string processFileName);

    void setParseTab(ParseTab &parseTab)
    {
        this->parseTab = parseTab;
    }

private:
    std::ofstream *outputFile = nullptr; // 输出语法分析结果(语法树)
    ParseTab &parseTab;                  // 语法分析表
    std::vector<int> stateStack;
    std::vector<Token> tokenStack;
    std::list<Token> inputTokens;

    void grammarAnalysis(std::istream &tokenStream, bool needProcess, std::string processFileName);
    void writeProcess(std::ofstream &processFile, const Action &action, bool writeHeader);

    void drawTree();
};

#endif
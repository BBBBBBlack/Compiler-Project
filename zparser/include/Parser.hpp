#ifndef PARSER_HPP
#define PARSER_HPP

#include "ParseTab.hpp"
#include "pch.hpp"
#include "Token.hpp"
#include "CST.hpp"
#include "SymbolTable.hpp"
#include "ParserFun.hpp"

extern bool error_flag;
class Parser
{
public:
    Parser(ParseTab &parseTab) : parseTab(parseTab) {}
    Parser(ParseTab &parseTab, std::string outputFile) : parseTab(parseTab)
    {
        setOutputFile(outputFile);
    }

    void setOutputFile(std::string fileName);

    /**
     * @brief 语法分析
     * @param tokenFile token文件名
     * @note 不需要输出分析过程
     */
    void grammarAnalysis(std::string tokenFile, std::string codeTargetFile);
    /**
     * @brief 语法分析
     * @param tokenFile token文件名
     * @param processFileName 分析过程输出文件名
     */
    void grammarAnalysis(std::string tokenFile, std::string processFileName, std::string codeTargetFile);
    /**
     * @brief 语法分析 从cin读取token流
     * @deprecated 未测试, 不建议使用
     */
    void grammarAnalysis(bool needProcess, std::string processFileName, std::string codeTargetFile);

    void setParseTab(ParseTab &parseTab)
    {
        this->parseTab = parseTab;
    }

private:
    std::ofstream *outputFile = nullptr; // 输出语法分析结果(语法树)
    ParseTab &parseTab;                  // 语法分析表
    std::vector<int> stateStack;
    // tokenStack[i].first: CST节点编号
    // tokenStack[i].second: token
    // std::vector<std::pair<int, Token>> tokenStack;
    std::vector<Token> tokenStack;
    std::vector<std::pair<std::string, std::string>> tempToken;
    std::list<Token> inputTokens;
    bool needProcess = false;
    // bool needCST = false
    // CST cst;

    void grammarAnalysis(std::istream &tokenStream, std::string processFileName, std::string codeTargetFile);
    void writeProcess(std::ofstream &processFile, const Action &action, bool writeHeader);
};

#endif
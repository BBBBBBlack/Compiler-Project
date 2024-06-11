#ifndef PARSER_HPP
#define PARSER_HPP

#include "ParseTab.hpp"
#include "pch.hpp"
#include "Token.hpp"
#include "CST.hpp"
#include "SymbolTable.hpp"
#include "SemanticStruct.hpp"
// #include "ParserFun.hpp"
#include "Tool.hpp"

#define PROCESS_FILE_MAX_SIZE 1 * 1024 * 1024 // 1MB

extern bool error_flag;
class Parser
{
public:
    Parser() {}
    Parser(ParseTab parseTab) : parseTab(parseTab) {}
    Parser(ParseTab parseTab, std::string outputFile) : parseTab(parseTab)
    {
        setOutputFile(outputFile);
    }

    void setOutputFile(std::string fileName);
    void setParseTab(ParseTab parseTab) { this->parseTab = parseTab; }

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

    void printInstr(std::ostream &os);

    // 暴露给action, 进行封装
    int nextinstr = 0, jumpListCnt = 0;
    std::vector<Quaternion> instrVec;              // 生成的中间代码
    std::unordered_map<int, JumpList> jumpListMap; // 回填的跳转列表

    // 生成四元式 返回四元式的标号
    TokenValue gen(Quaternion::Operation op, std::string arg1, std::string arg2, std::string result);
    TokenValue gen(Quaternion::Operation op, std::string arg1, std::string arg2);
    TokenValue gen(Quaternion::Operation op, std::string arg);
    // void gen(Quaternion::Operation op); // 应该没有无参的四元式吧
    TokenValue makeList(int instrId) { return makeList(std::to_string(instrId)); }
    TokenValue makeList(TokenValue instrId);
    TokenValue mergeList(TokenValue jumpListId1, TokenValue jumpListId2);
    void backPatch(TokenValue jumpListId, int jumpTo);

private:
    std::ofstream *outputFile = nullptr; // 输出语法分析结果(语法树)
    ParseTab parseTab;                   // 语法分析表 修改为传入, 而不使用引用
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
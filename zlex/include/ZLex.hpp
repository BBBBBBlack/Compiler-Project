#include "NFA.hpp"
#include "DFA.hpp"
#include <chrono>

extern std::string yytext; // 当前识别的字符串
extern int yylineno;       // 当前识别的行号

class ZLex
{
public:
    ZLex()
    {
    }
    // int yyleng;         // 当前识别的字符串长度

protected:
    // TODO 在窗口打印outputfile位置
    std::string outputFileName;
    // 文件读入位置
    std::wstreampos pos;
    int pos_i = 0;
    DFA *dfa;
    bool debugMode = false;
    /**
     * @brief 构建DFA
     * @param debugMode 打开调试模式
     * @param PAVec pattern-action
     * @param outputFileName 文件输出位置
     * @note 调试模式: 输出FA图中的内部id与转换表
     */
    void buildDFA(bool debugMode, PAVec PAvec, std::string outputFileName);
    /**
     * @brief 使用构件好的dfa进行词法分析
     */
    int lexicalAnalysis(std::ostream &outputStream, std::string fileName);
};
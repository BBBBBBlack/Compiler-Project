#include "NFA.hpp"
#include "DFA.hpp"

class ZLex
{

protected:
    // TODO 在窗口打印outputfile位置
    std::string outputFileName;
    /**
     * @brief 构建DFA
     * @param debugMode 打开调试模式
     * @param PAVec pattern-action
     * @param outputFileName 文件输出位置
     * @note 调试模式: 输出FA图中的内部id与转换表
     */
    void buildDFA(bool debugMode, PAVec PAvec, std::string outputFileName);
    /**
     * @brief 进行词法分析
     */
    void lexicalAnalysis(DFA &dfa, std::ostream &outputStream, std::string fileName);
};
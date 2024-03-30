#ifndef NFA_HPP
#define NFA_HPP

#include "FA.hpp"
// #include "DFA.hpp"

class NFA : public FA
{
public:
    NFA(std::string outPutFileName) : FA(outPutFileName) {}
    friend class DFA;
    void buildNFA(RegexVec regexVec);

protected:
    /**
     * @brief 将一条正则表达式转换为NFA
     * @param regex 正则表达式
     * @return NFA的起始和终止状态
     */
    FAStateBlock regexToBlock(std::string regex, FAStateVec &states);

    /**
     * @brief 添加转移
     * @param inputSymbol 输入符号
     * @param escapeFlag 转义标记
     * @param block1 子NFA1
     * @param block2 子NFA2
     */
    FAStateBlock addTransition(char inputSymbol, bool escapeFlag, FAStateBlock block1, FAStateBlock block2, FAStateVec &states);
};

#endif // NFA_HPP
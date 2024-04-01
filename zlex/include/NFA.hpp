#ifndef NFA_HPP
#define NFA_HPP

#include "FA.hpp"
// #include "DFA.hpp"

class NFA : public FA
{
public:
    friend class DFA;
    NFA() : FA()
    {
        FAType = "NFA";
    }
    NFA(std::string outPutFileName) : FA(outPutFileName)
    {
        FAType = "NFA";
    }
    void buildNFA(PAVec &PAVec);

protected:
    /**
     * @brief 转换[]为(|)组合而成的正则
     */
    std::string convertSquareBrackets(std::string regex);
    /**
     * @brief 为正则表达式添加省略的"-"(Union)符号
     */
    std::string addUnion(std::string regex);
    /**
     * @brief 将中缀正则表达式转换为后缀形式
     */
    std::string infixToSufix(std::string regex);
    /**
     * @brief 将一条正则表达式转换为NFA
     * @param regex 正则表达式
     * @return NFA的起始和终止状态
     */
    FAStateBlock regexToBlock(PatternAction pa, FAStateVec &states, int priority);

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
#ifndef DFA_HPP
#define DFA_HPP

#include "FA.hpp"
#include "NFA.hpp"
#include "climits"

class DFA : public FA
{
public:
    friend class NFA;
    /**
     * @brief 从NFA构建DFA
     * @param nfa NFA
     * @note 该构造函数会调用buildDFA函数
     */
    DFA(const NFA &nfa) : FA(nfa)
    {
        FAType = "DFA";
        copyProperties(nfa);
        buildDFA(const_cast<NFA &>(nfa));
    }

    void buildDFA(NFA &nfa);

protected:
    void printDFATransTableHeader();

    void copyProperties(const NFA &nfa)
    {
        debugMode = nfa.debugMode;
        printRegexFlag = nfa.printRegexFlag;
        printAlphabetFlag = nfa.printAlphabetFlag;
        alphabet = nfa.alphabet;
        outputFile = nfa.outputFile;
    }
    /**
     * @brief 获取一个状态的epsilon闭包
     * @param stateID 状态ID
     * @param states 状态集
     */
    StateSet epsilonClosure(int stateID, FAStateVec &states)
    {
        std::unordered_map<int, bool> visited;
        return epsilonClosure(stateID, visited, states);
    }
    /**
     * @brief 获取一个状态的epsilon闭包
     * @param stateID 状态ID
     * @param visited 访问标记(用于避免重复访问)
     * @param states 状态集
     */
    StateSet epsilonClosure(int stateID, std::unordered_map<int, bool> &visited, FAStateVec &states);
    /**
     * @brief 获取一个状态集的epsilon闭包
     * @param stateSet 状态集
     * @param states 状态集
     */
    StateSet epsilonClosure(StateSet stateSet, FAStateVec &states)
    {
        std::unordered_map<int, bool> visited;
        return epsilonClosure(stateSet, visited, states);
    }
    /**
     * @brief 获取一个状态集的epsilon闭包
     * @param stateSet 状态集
     * @param visited 访问标记(用于避免重复访问)
     * @param states 状态集
     */
    StateSet epsilonClosure(StateSet stateSet, std::unordered_map<int, bool> &visited, FAStateVec &states);
    /**
     * @brief 获取一个状态集的转移闭包
     * @param stateSet 状态集
     * @param symbol 转移符号
     * @param states 状态集
     */
    StateSet move(StateSet stateSet, std::string symbol, FAStateVec &states);

    void setActionAndNote(int dfaStateID, StateSet &stateSet, FAStateVec &nfaStates);
};

#endif // DFA_HPP
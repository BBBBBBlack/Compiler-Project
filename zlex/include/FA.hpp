#ifndef FA_H
#define FA_H

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include "Symbol.hpp"

#define BANNER                   \
    "  ______              \n"   \
    " |__  / |    _____  __\n"   \
    "   / /| |   / _ \\ \\/ /\n" \
    "  / /_| |__|  __/>  < \n"   \
    " /____|_____\\___/_/\\_\\"

#define EPSILON "EPSILON"
#define EPSILON_CHAR "\u03B5"
#define DEFAULT_OUTPUT_FILE "output/FA.md"
#define EMPTY_SET "Ø"

struct FAState
{
    int stateID;
    std::map<std::string, int> trans; // 映射字符到下一个状态集合
    std::vector<int> epsilonTrans;    // 空边
    bool isAccepting;                 // 是否为终节点

    FAState(int stateID, std::map<std::string, int> trans, std::vector<int> epsilonTrans, bool isAccepting)
        : stateID(stateID), trans(trans), epsilonTrans(epsilonTrans), isAccepting(isAccepting) {}

    bool operator==(const FAState &other) const
    {
        return stateID == other.stateID && trans == other.trans && epsilonTrans == other.epsilonTrans && isAccepting == other.isAccepting;
    }
};

struct FAStateBlock
{
    int beginStateID;
    int endStateID;
};

struct StateSet
{
    bool isAccepting = false;
    int stateID;
    std::unordered_set<int> set;

    friend std::ostream &operator<<(std::ostream &os, const StateSet &stateSet)
    {
        std::string isAccepting = stateSet.isAccepting ? "T" : "F";
        os << "ID:" << stateSet.stateID << ", END:" << isAccepting << ", {";
        bool flag = false;
        for (const auto &state : stateSet.set)
        {
            if (flag)
            {
                os << ", ";
            }
            os << state;
            flag = true;
        }
        os << "}";
        return os;
    }
};

typedef std::vector<FAState> FAStateVec;
typedef std::vector<std::string> RegexVec;

struct StateSetHash
{
    std::size_t operator()(const StateSet &stateSet) const
    {
        std::size_t seed = 0;
        for (const auto &state : stateSet.set)
        {
            seed ^= std::hash<int>{}(state) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

struct StateSetEqual
{
    bool operator()(const StateSet &lhs, const StateSet &rhs) const
    {
        return lhs.set == rhs.set;
    }
};

class FA
{
public:
    RegexVec regexVec;
    FA() {}
    FA(std::string outPutFileName)
    {
        setOutputFile(outPutFileName);
    }
    ~FA() {}

    void setOutputFile(std::string fileName);

    void printNFA(std::string fileName)
    {
        setOutputFile(fileName);
        printNFA();
    }

    void printDFA(std::string fileName)
    {
        setOutputFile(fileName);
        printDFA();
    }

    void printNFA()
    {
        printFA(NFAStartStateID, NFAStates);
    }
    void printDFA()
    {
        printFA(DFAStartStateID, DFAStates);
    }

    /**
     * @brief 根据正则表达式集合构建NFA
     * @param regexVec 正则表达式集合
     */
    void buildNFA(RegexVec regexVec);

    /**
     * @brief 将states中的NFA转换为DFA
     */
    void toDFA();

    void setDebugMode(bool debugMode)
    {
        this->debugMode = debugMode;
    }

private:
    FAStateVec NFAStates;
    int NFAStartStateID;
    FAStateVec DFAStates;
    int DFAStartStateID;
    std::ofstream outFile;
    // TODO 配置到print中
    bool debugMode = false;
    bool printRegexFlag = false;

    void printFA(int startStateID, FAStateVec &states);

    /**
     * @brief 状态块
     * @note 存储构建NFA时的中间状态, 便于合并子正则表达式
     */
    std::vector<FAStateBlock> stateBlocks;
    /**
     * @brief 字母表
     * key: 符号
     * value: 是否为字母表
     * @note 在FA::addTransition中更新
     */
    std::set<std::string> alphabet;

    /**
     * @brief 为正则表达式添加省略的"-"(Union)符号
     */
    std::string addUnion(std::string regex);
    /**
     * @brief 将中缀正则表达式转换为后缀形式
     */
    std::string infixToSufix(std::string regex);

    /**
     * @brief 添加一个状态
     * @param isAccepting 是否为终态
     * @param states 状态集
     * @return 返回状态ID
     */
    int addState(bool isAccepting, FAStateVec &states);

    /**
     * @brief 在state中添加一条边
     * @param symbol 转移条件(可为空)
     */
    void addEdge(int fromStateID, int toStateID, char symbol, FAStateVec &states);
    /**
     * @brief 在state中添加一条边
     * @param fromStateID 起始状态ID
     * @param symbol 转移条件(可为空)
     * @param states 状态集
     */
    void addEdge(int fromStateID, int toStateID, std::string symbol, FAStateVec &states);

    /**
     * @brief 添加转移
     * @param inputSymbol 输入符号
     * @param escapeFlag 转义标记
     * @param block1 子NFA1
     * @param block2 子NFA2
     */
    FAStateBlock addTransition(char inputSymbol, bool escapeFlag, FAStateBlock block1, FAStateBlock block2, FAStateVec &states);

    /**
     * @brief 将一条正则表达式转换为NFA
     * @param regex 正则表达式
     * @return NFA的起始和终止状态
     */
    FAStateBlock regexToBlock(std::string regex, FAStateVec &states);

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
    StateSet
    epsilonClosure(StateSet stateSet, std::unordered_map<int, bool> &visited, FAStateVec &states);
    /**
     * @brief 获取一个状态集的转移闭包
     * @param stateSet 状态集
     * @param symbol 转移符号
     * @param states 状态集
     */
    StateSet move(StateSet stateSet, std::string symbol, FAStateVec &states);

    void printDFATransTableHeader();
};

#endif // FA_H
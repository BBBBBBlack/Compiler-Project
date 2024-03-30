#ifndef FA_H
#define FA_H

#include <algorithm>
#include <fstream>
#include <filesystem>
#include "Symbol.hpp"
#include "struct.hpp"

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

/**
 * @brief 有限自动机
 * @note 仅包含基本的FA操作, 不包含DFA和NFA的具体实现
 */
class FA
{
public:
    RegexVec regexVec;
    FA() : FAType("FA") {}
    FA(std::string outPutFileName) : FA()
    {

        if (outPutFileName.empty())
        {
            setOutputFile(DEFAULT_OUTPUT_FILE);
        }
        else
        {
            setOutputFile(outPutFileName);
        }
    }
    FA(const FA &fa) : FAType(fa.FAType)
    {
        // regexVec = fa.regexVec;
        // states = fa.states;
        // startStateID = fa.startStateID;
        alphabet = fa.alphabet;
        outputFile = fa.outputFile;
        printRegexFlag = fa.printRegexFlag;
    }
    ~FA() {}

    void setOutputFile(std::string outputFileName);

    void printFA(std::string outputFileName)
    {
        setOutputFile(outputFileName);
        printFA();
    }

    void setDebugMode(bool debugMode)
    {
        this->debugMode = debugMode;
    }

protected:
    FAStateVec states;
    int startStateID;
    std::ofstream *outputFile = nullptr;
    std::string FAType;

    // TODO 配置到print中
    bool debugMode = false;
    bool printRegexFlag = false;

    void printFA();

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

    // void printDFATransTableHeader();
};

#endif // FA_H
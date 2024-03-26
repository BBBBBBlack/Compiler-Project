#ifndef FA_H
#define FA_H

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <fstream>
#include "Symbol.hpp"

#define EPSILON "EPSILON"
#define EPSILON_CHAR "\u03B5"

struct FAState
{
    int stateID;
    std::map<std::string, int> trans; // 映射字符到下一个状态集合
    std::vector<int> epsilonTrans;    // 空边
    bool isAccepting;                 // 是否为终节点

    FAState(int stateID, std::map<std::string, int> trans, std::vector<int> epsilonTrans, bool isAccepting)
        : stateID(stateID), trans(trans), epsilonTrans(epsilonTrans), isAccepting(isAccepting) {}
};

struct FAStateBlock
{
    int beginStateID;
    int endStateID;
};

class FA
{
public:
    FA();
    ~FA();

    void printFA(FAStateBlock block);
    void printFA(FAStateBlock block, std::string fileName);

private:
    std::vector<FAState> states;
    std::vector<FAStateBlock> stateBlocks;
    int startStateID;
    // static std::map<Symbol, std::set<int>> emptyMap;

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
     * @return 返回状态ID
     */
    int addState(bool isAccepting);

    /**
     * @brief 在state中添加一条边
     * @param symbol 转移条件(可为空)
     */
    void addEdge(int fromStateID, int toStateID, std::string symbol);

    /**
     * @brief 在state中添加一条边
     * @param symbol 转移条件(可为空)
     */
    void addEdge(int fromStateID, int toStateID, char symbol);

    /**
     * @brief 添加转移
     * @param inputSymbol 输入符号
     * @param escapeFlag 转义标记
     * @param block1 子NFA1
     * @param block2 子NFA2
     */
    FAStateBlock addTransition(char inputSymbol, bool escapeFlag, FAStateBlock block1, FAStateBlock block2);

    FAStateBlock regexToBlock(std::string regex);
};

#endif // FA_H

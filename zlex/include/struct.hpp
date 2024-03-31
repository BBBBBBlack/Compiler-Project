#ifndef STRUCT_HPP
#define STRUCT_HPP

#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <iostream>
#include <any>
#include <functional>

/**
 * @brief action
 * @return token类型 (0表示无返回值)
 */
using ActionFunction = std::function<int()>;
const ActionFunction NullAction;

struct PatternAction
{
    std::string pattern;
    ActionFunction action;
    std::string note;
    PatternAction(std::string pattern, ActionFunction action) : pattern(pattern), action(action), note(pattern) {}
};

typedef PatternAction PA;
typedef std::vector<PatternAction> PAVec;

struct FAState
{
    int stateID;
    // TODO 重构为<char, int>
    std::unordered_map<std::string, int> trans; // 映射字符到下一个状态集合
    std::vector<int> epsilonTrans;              // 空边
    bool isAccepting;                           // 是否为终节点
    ActionFunction action;                      // 动作
    std::string note;                           // 备注, 可为空

    FAState(int stateID, std::unordered_map<std::string, int> trans, std::vector<int> epsilonTrans, bool isAccepting, ActionFunction action)
        : stateID(stateID), trans(trans), epsilonTrans(epsilonTrans), isAccepting(isAccepting), action(action) {}

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

#endif // STRUCT_HPP
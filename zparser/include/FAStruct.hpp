#ifndef FA_STRUCT_HPP
#define FA_STRUCT_HPP

// NOTE: 备用struct文件 方便复制, 随意修改

#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <iostream>
#include <any>
#include <functional>
#include "pch.hpp"
#include "Rule.hpp"

// 空的动作函数
inline int NullAction()
{
    return 0; // 或者根据实际情况返回其他值
}

struct PatternAction
{
    std::string pattern;
    ActionFunction action;
    std::string note;
    PatternAction(std::string pattern, ActionFunction action) : pattern(pattern), action(action), note(pattern) {}
    PatternAction(std::string pattern, ActionFunction action, std::string note) : pattern(pattern), action(action), note(note) {}
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
    int priority;                               // 优先级
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

typedef std::vector<FAState> FAStateVec;
typedef std::vector<std::string> RegexVec;
struct StateSet
{
    bool isAccepting = false;
    int stateID; // DFA中的stateID
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
    // Hash function for StateSet
    struct Hash
    {
        std::size_t operator()(const StateSet &stateSet) const
        {
            std::size_t hash = 0;
            for (const auto &state : stateSet.set)
            {
                hash ^= std::hash<int>{}(state);
            }
            return hash;
        }
    };

    // Equality comparison for StateSet
    struct Equal
    {
        bool operator()(const StateSet &lhs, const StateSet &rhs) const
        {
            return lhs.set == rhs.set;
        }
    };
};

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};
#endif // FA_STRUCT_HPP
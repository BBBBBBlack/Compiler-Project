#include "FAStruct.hpp"

// 项集规范族
// TODO 可以做一些优化
void FAState::closure(SubRuleSet &I)
{
    std::list<SubRule> temp(I.begin(), I.end());
    for (SubRule rule : temp)
    {
        int dotPos = rule.getDotPos();
        if (dotPos < rule.getRight().size() &&
            Rules::NonTermVec.find(rule.getRight()[dotPos]) != Rules::NonTermVec.end())
        {
            for (Rule r : Rules::rules)
            {
                SubRule tt(r, 0);
                if (I.count(tt) == 0 && tt.getLeft() == rule.getRight()[dotPos])
                {
                    I.insert(tt);
                    temp.push_back(tt);
                }
            }
        }
    }
}

SubRuleSet FAState::Goto(SubRuleSet &I, Symbol X)
{
    SubRuleSet J;
    for (SubRule rule : I)
    {
        int dotPos = rule.getDotPos();
        if (dotPos < rule.getRight().size() &&
            rule.getRight()[dotPos] == X)
        {
            SubRule newRule(rule, dotPos + 1);
            J.insert(newRule);
        }
    }
    closure(J);
    return J;
}

void FA::create(std::vector<Rule> rules)
{
    // 构造初始状态
    Rule start = rules[rules.size() - 1];
    SubRuleSet set;
    set.insert(SubRule(start, 0));
    FAState::closure(set);
    FAState state(0, set);
    states.push_back(state);
    for (SubRule rule : set)
    {
        rule.print();
    }

    // 循环BEGIN!!
    for (int i = 0; i < states.size(); i++)
    {
        FAState state = states[i];
        std::unordered_set<Symbol> temp;
        temp.insert(Rules::TermVec.begin(), Rules::TermVec.end());
        temp.insert(Rules::NonTermVec.begin(), Rules::NonTermVec.end());
        for (Symbol symbol : temp)
        {
            if (symbol == EPSILON)
            {
                continue;
            }
            SubRuleSet set = FAState::Goto(state.subRules, symbol);
            if (set.size() == 0)
            {
                continue;
            }
            // 判断这个state是否已经存在
            bool flag = false;
            for (FAState s : states)
            {
                if (s.subRules == set)
                {
                    flag = true;
                    // 加边
                    states[i].trans[symbol] = s.stateID;
                    break;
                }
            }
            if (!flag)
            {
                FAState newState(states.size(), set);
                states.push_back(newState);
                // 加边
                states[i].trans[symbol] = states.size() - 1;
            }
        }
    }
}
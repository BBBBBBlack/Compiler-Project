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

void FA::createFA(std::vector<Rule> rules)
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

void FA::drawFA(std::string outFileName)
{
    std::string folderPath = outFileName.substr(0, outFileName.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    std::ofstream outFile(outFileName, std::ios::trunc);
    // 输出产生式
    outFile << "## 产生式" << std::endl
            << std::endl;
    Rules::printRules(outFile);
    outFile << std::endl;

    // 输出FA图
    outFile << "## FA Graph" << std::endl
            << std::endl;
    outFile << "```mermaid" << std::endl;
    outFile << "\tgraph LR" << std::endl;
    for (int i = 0; i < states.size(); i++)
    {
        // 创建节点
        outFile << "\tnode" << i << "(\"<div>";
        outFile << "I" << i << ":<br>";
        for (SubRule rule : states[i].subRules)
        {
            rule.print(outFile);
            outFile << "<br>";
        }
        outFile << "</div>\")" << std::endl;
        // 创建边
        for (auto &pair : states[i].trans)
        {
            Symbol symbol = pair.first;
            int next_state = pair.second;
            outFile << "\tnode" << i << "--> |\"" << symbol
                    << "\"| node" << next_state << std::endl;
        }
    }
    outFile << "```" << std::endl;
    outFile.close();
}
//  创建分析表
std::vector<State> FA::createTable()
{
    std::vector<State> res;
    for (int i = 0; i < states.size(); i++)
    {
        std::unordered_map<Symbol, Action> actions;
        for (auto &pair : states[i].trans)
        {
            // std::unordered_map<Symbol, int> trans;
            Symbol symbol = pair.first;
            int next_state = pair.second;
            if (Rules::TermVec.find(symbol) != Rules::TermVec.end())
            {
                actions[symbol] = Action(ActionType::A_Shift, next_state);
            }
            else
            {
                actions[symbol] = Action(ActionType::A_Goto, next_state);
            }
        }
        for (const SubRule &sub_rule : states[i].subRules)
        {
            // 有归约项
            if (sub_rule.right.size() == sub_rule.getDotPos())
            {
                if (sub_rule.left == "START")
                {
                    actions["$"] = Action(ActionType::A_Accept);
                }
                std::unordered_set<Symbol> follow_set = Rules::Follow[sub_rule.left];
                for (Symbol symbol : follow_set)
                {
                    // if (actions.find(symbol) != actions.end() && actions[symbol].type == ActionType::A_Shift)
                    // {
                    //     printf("冲突%s  %d\n", symbol.c_str(), i);
                    // }
                    if (actions.find(symbol) == actions.end())
                    {
                        actions[symbol] = Action(ActionType::A_Reduce, sub_rule.id + 1);
                    }
                    if (actions.find(symbol) != actions.end() &&
                        actions[symbol].type == ActionType::A_Shift)
                    {
                        if ((symbol == "+" || symbol == "-") ||
                            (sub_rule.right[0] == "-" &&
                             (symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/")))
                        {
                            actions[symbol] = Action(ActionType::A_Reduce, sub_rule.id + 1);
                        }
                        if (symbol == "||" || (sub_rule.right[0] == "!" && (symbol == "||" || symbol == "&&")))
                        {
                            actions[symbol] = Action(ActionType::A_Reduce, sub_rule.id + 1);
                        }
                    }
                }
            }
        }
        res.push_back(State(actions));
    }
    return res;
}
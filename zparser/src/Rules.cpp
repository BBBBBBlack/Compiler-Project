
#include "Rules.hpp"
/**
 * @brief 产生式们
 */
std::unordered_set<Symbol> Rules::NonTermVec;
std::unordered_set<Symbol> Rules::TermVec;
std::vector<Rule> Rules::rules;
std::vector<std::list<Symbol>> Rules::Rings;
Rules::RuleMap Rules::rules_map;

// rules归类
void Rules::genRuleMap()
{
    Rules::rules_map.clear();
    for (int i = 0; i < Rules::rules.size(); i++)
    {
        Rule *rule = &Rules::rules[i];
        Symbol left = rule->left;
        if (rules_map.find(left) == rules_map.end())
        {
            std::vector<Rule *> temp;
            temp.push_back(rule);
            rules_map[left] = temp;
        }
        else
        {
            rules_map[left].push_back(rule);
        }
    }
}

void Rules::printTermVec()
{
    printf("TermVec: ");
    for (const auto &symbol : Rules::TermVec)
    {
        printf("%s ", symbol.c_str());
    }
    printf("\n");
}

void Rules::printNonTermVec()
{
    printf("NonTermVec: ");
    for (const auto &symbol : Rules::NonTermVec)
    {
        printf("%s ", symbol.c_str());
    }
    printf("\n");
}

void Rules::printRules()
{
    for (Rule &rule : Rules::rules)
    {
        rule.print();
    }
}
// 直接左递归的消除（可能有用）
void Rules::d_eliminateLeftRecursion()
{
    // 存在左递归的非终结符集
    std::unordered_set<Symbol> leftRecursion;
    for (int i = 0; i < Rules::rules.size(); i++)
    {
        Rule rule = Rules::rules[i];
        Symbol left = rule.getLeft();
        std::vector<Symbol> right = rule.getRight();

        if (leftRecursion.find(left) == leftRecursion.end() && left == right[0])
        {
            leftRecursion.insert(left);
            Symbol newNonTerm = left + "'";
            Rules::NonTermVec.insert(newNonTerm);
            Rules::rules.push_back(Rule(Rules::rules.size(), newNonTerm, {EPSILON}));
            std::vector<Rule *> same_left_rules = Rules::rules_map[left];
            for (int j = 0; j < same_left_rules.size(); j++)
            {
                Rule rule = *same_left_rules[j];
                Symbol left = rule.getLeft();
                std::vector<Symbol> right = rule.getRight();
                // E -> E + T类型
                if (left == right[0])
                {
                    // E' -> + T E'
                    rule.left = newNonTerm;
                    right.erase(right.begin());
                    right.push_back(newNonTerm);
                    rule.right = right;
                    *same_left_rules[j] = rule;
                }
                // E -> axx类型
                else
                {
                    // E -> axxE'
                    if (!rule.isEpsilon())
                    {
                        rule.addRight(newNonTerm);
                        *same_left_rules[j] = rule;
                    }
                }
            }
        }
    }
    Rules::genRuleMap();
}
// 左递归的消除（可能有用）
void Rules::eliminateLeftRecursion()
{
    // 先消除直接左递归
    d_eliminateLeftRecursion();
    std::list<Symbol> temp;
    Symbol start = Rules::rules[0].left;
    // 判环
    Rules::dfs(start, temp);
    // 消環
    for (int i = 0; i < Rules::Rings.size(); i++)
    {
        int index_i = 0;
        // 每个A_i
        for (Symbol A_i : Rules::Rings[i])
        {
            index_i++;
            int index_j = 0;
            // 每个A_j
            for (Symbol A_j : Rules::Rings[i])
            {
                index_j++;
                if (index_j == index_i)
                {
                    break;
                }
                std::vector<Rule *> A_i_rules = Rules::rules_map[A_i];
                for (int j = 0; j < A_i_rules.size(); j++)
                {
                    Rule *rule_i = A_i_rules[j];
                    if (rule_i->isEpsilon())
                    {
                        continue;
                    }
                    // 将A_i->A_j xxx替换为A_i->(yyy) xxx
                    if (rule_i->right[0] == A_j)
                    {

                        std::vector<Symbol> right = rule_i->right;
                        right.erase(right.begin());
                        int index = 0;
                        // std::vector<Rule *> A_j_rules = Rules::rules_map[A_j];
                        for (Rule *rule_j : Rules::rules_map[A_j])
                        {
                            if (rule_j->isEpsilon())
                            {
                                continue;
                            }
                            index++;
                            std::vector<Symbol> new_right(rule_j->right.begin(), rule_j->right.end());
                            new_right.insert(new_right.end(), right.begin(), right.end());
                            if (index == 1)
                            {
                                rule_i->right = new_right;
                            }
                            else
                            {
                                Rule new_rule = Rule(Rules::rules.size(), rule_i->left, new_right);
                                Rules::rules.push_back(new_rule);
                                A_i_rules.push_back(&Rules::rules[Rules::rules.size() - 1]);
                            }
                        }
                    }
                }
                Rules::rules_map[A_i] = A_i_rules;
            }
            // 消除直接左递归
            d_eliminateLeftRecursion();
        }
    }
}
void Rules::dfs(Symbol start, std::list<Symbol> &temp)
{
    std::vector<Rule *> same_left_rules = Rules::rules_map[start];
    if (same_left_rules.size() == 0)
    {
        return;
    }
    for (int i = 0; i < same_left_rules.size(); i++)
    {
        Rule rule = *same_left_rules[i];
        // 有环
        if (rule.visited)
        {
            // 加入
            Rules::Rings.push_back(temp);
            continue;
        }
        temp.push_front(rule.left);
        same_left_rules[i]->visited = true;
        Symbol right_fir = rule.right[0];
        if (Rules::NonTermVec.find(right_fir) != Rules::NonTermVec.end())
        {
            dfs(right_fir, temp);
        }
        same_left_rules[i]->visited = false;
        temp.pop_front();
    }
}

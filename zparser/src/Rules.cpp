
#include "Rules.hpp"

#define START "START"

bool compareFollowMap(Rules::SymbolSetMap originMap);
void dfs(Symbol start, std::list<Symbol> &temp);
int findIndex(std::list<Symbol> &myList, Symbol element);

/**
 * @brief 产生式们
 */
std::unordered_set<Symbol> Rules::NonTermVec;
std::unordered_set<Symbol> Rules::TermVec;
std::vector<Rule> Rules::rules;
std::vector<std::list<Symbol>> Rules::Rings;
Rules::RuleMap Rules::rules_map;
Rules::SymbolSetMap Rules::First;
Rules::SymbolSetMap Rules::Follow;

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

void Rules::printRules(std::ostream &os)
{
    for (Rule &rule : Rules::rules)
    {
        os << "- " << rule << std::endl;
    }
}

// 添加增广文法的产生式
void Rules::addStart()
{
    std::string start = Rules::rules[0].getLeft();
    Rules::rules.push_back(Rule(Rules::rules.size(), "START"));
    Rules::rules[Rules::rules.size() - 1].addRight(start);
    Rules::NonTermVec.insert("START");
}

// 修改（非）终结符
void Rules::transForAnalysisTable()
{
    Rules::NonTermVec.erase("START");
    Rules::TermVec.insert("$");
    Rules::TermVec.erase(EPSILON);
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
    // // 先消除直接左递归
    d_eliminateLeftRecursion();
    std::list<Symbol> temp;
    Symbol start = Rules::rules[0].left;
    // 判环
    dfs(start, temp);
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

// 所有first集
void Rules::getAllFirst()
{
    std::list<Symbol> temp;
    // Symbol start = Rules::rules[0].left;
    for (Symbol start : Rules::NonTermVec)
    {
        dfs(start, temp);
        temp.clear();
    }
    std::unordered_set<Symbol> temp2;
    for (Symbol symbol : Rules::NonTermVec)
    {
        if (symbol != "START" && Rules::First.find(symbol) == Rules::First.end())
        {

            Rules::getFirst(symbol, temp2);
            temp2.clear();
            // 遇到间接左递归时，环中的左部有相同的first集
            std::unordered_set<Symbol> max_set = Rules::First[symbol];
            for (int i = 0; i < Rules::Rings.size(); i++)
            {
                if (findIndex(Rules::Rings[i], symbol) != -1)
                {
                    for (Symbol s : Rules::Rings[i])
                    {
                        Rules::First[s] = max_set;
                    }
                }
            }
        }
    }
}

// first集
void Rules::getFirst(Symbol start, std::unordered_set<Symbol> &temp)
{
    bool flag = false; // 是否重复
    if (temp.find(start) == temp.end())
    {
        temp.insert(start);
    }
    else
    {
        flag = true;
    }
    std::vector<Rule *> same_left_rules = Rules::rules_map[start];
    for (int i = 0; i < same_left_rules.size(); i++)
    {
        Rule *rule = same_left_rules[i];
        if (rule->isEpsilon())
        {
            Rules::First[start].insert(EPSILON);
        }
        else
        {
            Symbol right_fir = rule->right[0];
            if (Rules::TermVec.find(right_fir) != Rules::TermVec.end())
            {
                Rules::First[start].insert(right_fir);
            }
            else
            {
                int cnt = 0;
                while (1)
                {
                    cnt++;
                    bool containEpsilon = false;
                    if (!flag)
                    {
                        Rules::getFirst(right_fir, temp);
                    }
                    for (Symbol symbol : Rules::First[right_fir])
                    {
                        if (symbol != EPSILON || cnt == rule->right.size())
                        {
                            Rules::First[start].insert(symbol);
                        }
                        else if (symbol == EPSILON)
                        {
                            containEpsilon = true;
                            right_fir = rule->right[cnt];
                        }
                    }
                    if (!containEpsilon || cnt >= rule->right.size())
                    {
                        break;
                    }
                }
            }
        }
    }
    if (!flag)
    {
        temp.erase(start);
    }
}

// follow集
void Rules::getFollow()
{
    int i = 0;
    Rules::SymbolSetMap originMap = Rules::Follow;
    while (1)
    {
        if (rules[i].left != "START")
        {
            Rule rule = Rules::rules[i];
            Symbol left = rule.left;
            if (i == 0)
            {
                Rules::Follow[left].insert("$");
            }

            std::vector<Symbol> right = rule.right;
            for (int j = 0; j < right.size(); j++)
            {
                Symbol symbol = right[j];
                // 右部的非终结符
                if (Rules::NonTermVec.find(symbol) != Rules::NonTermVec.end())
                {
                    if (j + 1 < right.size())
                    {
                        if (Rules::TermVec.find(right[j + 1]) != Rules::TermVec.end())
                        {
                            if (right[j + 1] != EPSILON)
                            {
                                Rules::Follow[symbol].insert(right[j + 1]);
                            }
                        }
                        else
                        {
                            int temp = j;
                            do
                            {
                                temp++;
                                Rules::Follow[symbol].insert(Rules::First[right[temp]].begin(),
                                                             Rules::First[right[temp]].end());
                            } while ((temp + 1 < right.size()) &&
                                     Rules::First[right[temp]].find(EPSILON) != Rules::First[right[temp]].end());
                            Rules::Follow[symbol].erase(EPSILON);
                        }
                    }

                    if (j == right.size() - 1 ||
                        Rules::First[right[j + 1]].find(EPSILON) != Rules::First[right[j + 1]].end())
                    {
                        for (Symbol s : Rules::Follow[left])
                        {
                            Rules::Follow[symbol].insert(s);
                        }
                    }
                }
            }
        }
        i++;
        i %= Rules::rules.size();
        if (i == 0)
        {
            if (compareFollowMap(originMap))
            {
                break;
            }
            originMap = Rules::Follow;
        }
    }
}

void dfs(Symbol start, std::list<Symbol> &temp)
{
    int index = findIndex(temp, start);
    // 有环
    if (temp.size() != 0 && index != -1)
    {
        // 加入
        auto end_it = std::next(temp.begin(), index);
        Rules::Rings.push_back(std::list(temp.begin(), end_it));
        return;
    }
    std::vector<Rule *> same_left_rules = Rules::rules_map[start];
    if (same_left_rules.size() == 0)
    {
        return;
    }

    for (int i = 0; i < same_left_rules.size(); i++)
    {
        Rule rule = *same_left_rules[i];
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

bool compareFollowMap(Rules::SymbolSetMap originMap)
{
    // 在某个时间点，你想要检查map是否发生了改变
    for (const auto &pair : Rules::Follow)
    {
        if (originMap.count(pair.first) == 0 || originMap[pair.first].size() != pair.second.size())
        {
            return false;
        }
    }
    return true;
}

int findIndex(std::list<Symbol> &myList, Symbol element)
{
    int index = myList.size();
    for (auto it = myList.rbegin(); it != myList.rend(); ++it)
    {
        if (*it == element)
        {
            return index; // 返回找到的元素的下标
        }
        index--;
    }
    return -1; // 如果元素未找到，则返回 -1
}
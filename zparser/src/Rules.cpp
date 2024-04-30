
#include "Rules.hpp"
/**
 * @brief 产生式们
 */
std::unordered_set<Symbol> Rules::NonTermVec;
std::unordered_set<Symbol> Rules::TermVec;
std::vector<Rule> Rules::rules;
std::vector<std::list<Symbol>> Rules::Rings;
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
            for (int j = 0; j < Rules::rules.size(); j++)
            {
                if (left == Rules::rules[j].getLeft())
                {
                    Rule rule = Rules::rules[j];
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
                        Rules::rules[j] = rule;
                    }
                    // E -> axx类型
                    else
                    {
                        // E -> axxE'
                        if (!rule.isEpsilon())
                        {
                            rule.addRight(newNonTerm);
                            Rules::rules[j] = rule;
                        }
                    }
                }
            }
        }
    }
}
// 间接左递归的消除（可能有用）
void Rules::i_eliminateLeftRecursion()
{
    std::list<Symbol> temp;
    Symbol start = Rules::rules[rules.size() - 1].right[0];
    // 判环
    Rules::dfs(start, temp);
}
void Rules::dfs(Symbol start, std::list<Symbol> &temp)
{
    for (int i = 0; i < Rules::rules.size(); i++)
    {
        if (Rules::rules[i].left == start)
        {

            // 有环
            if (Rules::rules[i].visited)
            {
                // 加入
                Rules::Rings.push_back(temp);
                break;
            }
            temp.push_back(Rules::rules[i].left);
            Rules::rules[i].visited = true;
            Symbol right_fir = Rules::rules[i].right[0];
            if (Rules::NonTermVec.find(right_fir) != Rules::NonTermVec.end())
            {
                dfs(right_fir, temp);
            }

            Rules::rules[i].visited = false;
            temp.pop_back();
        }
    }
}

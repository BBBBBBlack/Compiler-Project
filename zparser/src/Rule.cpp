#include "Rule.hpp"
#include <stdio.h>

/**
 * @brief 产生式们
 */
// 终结符
std::unordered_set<Symbol> Rules::termVec;
void Rules::printTermVec()
{
    printf("TermVec: ");
    for (const auto &symbol : Rules::termVec)
    {
        printf("%s ", symbol.c_str());
    }
    printf("\n");
}
// 非终结符
std::unordered_set<Symbol> Rules::nonTermVec;
void Rules::printNonTermVec()
{
    printf("NonTermVec: ");
    for (const auto &symbol : Rules::nonTermVec)
    {
        printf("%s ", symbol.c_str());
    }
    printf("\n");
}
// 产生式集合
std::vector<Rule> Rules::rules;
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
            Rules::nonTermVec.insert(newNonTerm);
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
void Rules::i_eliminateLeftRecursion()
{
    std::unordered_set<Symbol> temp;
    Symbol start = Rules::rules[rules.size() - 1].right[0];
    temp.insert(start);
    // 判环
    Rules::dfs(start, temp);
}
void Rules::dfs(Symbol start, std::unordered_set<Symbol> &temp)
{
    for (int i = 0; i < Rules::rules.size(); i++)
    {
        
    }
}
/**
 * @brief 产生式类
 */
Rule::Rule(int id)
{
    this->id = id;
}
Rule::Rule(int id, Symbol left)
{
    this->id = id;
    this->left = left;
}
Rule::Rule(int id, Symbol left, std::vector<Symbol> right)
{
    this->id = id;
    this->left = left;
    this->right = right;
}
int Rule::getId() const
{
    return this->id;
}
Symbol Rule::getLeft() const
{
    return this->left;
}
std::vector<Symbol> Rule::getRight() const
{
    return right;
}
void Rule::setRight(std::vector<Symbol> right)
{
    this->right = right;
}
void Rule::addRight(Symbol right)
{
    this->right.push_back(right);
}
bool Rule::isEpsilon() const
{
    return this->right.size() == 1 && this->right[0] == EPSILON;
}
void Rule::print()
{
    // 打印左部
    printf("Left: %s\n", left.c_str());

    // 打印右部
    printf("Right: ");
    for (const auto &symbol : right)
    {
        printf("%s ", symbol.c_str());
    }
    printf("\n");
}

/**
 * @brief 子产生式类（带dot）
 */
SubRule::SubRule(const Rule &rule, int dotPos) : Rule(rule.getId(), rule.getLeft(), rule.getRight())
{
    if (rule.getRight().size() == 1 && rule.getRight()[0] == EPSILON)
    {
        this->dotPos = 1;
    }
    else
    {
        this->dotPos = dotPos;
    }
}
int SubRule::getDotPos() const
{
    return this->dotPos;
}
void SubRule::print()
{
    printf("Left: %s\t", this->getLeft().c_str());
    std::vector<Symbol> right = this->getRight();
    printf("Right: ");
    for (int i = 0; i < right.size(); i++)
    {
        if (i == this->dotPos)
        {
            printf(".");
        }
        printf("%s ", right[i].c_str());
    }
    printf("\n");
}
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
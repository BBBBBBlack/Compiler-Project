#include "Rule.hpp"
#include <stdio.h>

// 终结符
std::set<Symbol> Rules::termVec;
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
std::set<Symbol> Rules::nonTermVec;
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

Rule::Rule()
{
}
Rule::Rule(Symbol left)
{
    this->left = left;
}
Symbol Rule::getLeft()
{
    return this->left;
}
void Rule::addRight(Symbol right)
{
    this->right.push_back(right);
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
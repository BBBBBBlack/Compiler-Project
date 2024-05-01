#ifndef RULES_HPP
#define RULES_HPP

#include <vector>
#include <list>
#include "Rule.hpp"

class Rules
{
public:
    static std::vector<Rule> rules;
    // 产生式的非终结符集
    static std::unordered_set<Symbol> NonTermVec;
    // 产生式的终结符集
    static std::unordered_set<Symbol> TermVec;
    // 产生式的环集
    static std::vector<std::list<Symbol>> Rings;
    static void printNonTermVec();
    static void printTermVec();
    static void printRules();

    // 直接左递归的消除（可能有用）
    static void d_eliminateLeftRecursion();
    // 间接左递归的消除（可能有用）
    static void i_eliminateLeftRecursion();

private:
    static std::unordered_set<Symbol> dfs();
    static void dfs(Symbol start, std::list<Symbol> &temp);
};

#endif // !RULES_HPP
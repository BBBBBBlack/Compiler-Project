#ifndef RULES_HPP
#define RULES_HPP
#include <map>
#include <vector>
#include <list>
#include "Rule.hpp"
namespace Rules
{
    typedef std::unordered_map<Symbol, std::vector<Rule *>> RuleMap;
    typedef std::unordered_map<Symbol, std::unordered_set<Symbol>> SymbolSetMap;
    extern std::vector<Rule> rules;
    // 产生式的非终结符集
    extern std::unordered_set<Symbol> NonTermVec;
    // 产生式的终结符集
    extern std::unordered_set<Symbol> TermVec;
    // 产生式的环集
    extern std::vector<std::list<Symbol>> Rings;
    // 相同左部产生式集合：左部：&rule
    extern RuleMap rules_map;
    // 产生式的first集
    extern SymbolSetMap First;
    // 产生式的follow集
    extern SymbolSetMap Follow;

    // rules归类
    void genRuleMap();
    void printNonTermVec();
    void printTermVec();
    void printRules();

    // 直接左递归的消除（可能有用）
    void d_eliminateLeftRecursion();
    // 左递归的消除（可能有用）
    void eliminateLeftRecursion();
    // first集
    void getAllFirst();
    void getFirst(Symbol start);
    // follow集
    void getFollow();

};

#endif // !RULES_HPP
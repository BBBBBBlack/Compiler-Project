#ifndef RULE_HPP
#define RULE_HPP

#include <vector>
#include <string>
#include <set>
#include "ParseTabStruct.hpp"

#define PRODUCTION_CONCAT "->"

// TODO 产生式动作的save和load
using ActionFunction = std::function<int(Token &leftToken, std::vector<Token> &rightTokens)>;

// 产生式类
class Rule
{
    // private:
public:
    // 产生式左部
    Symbol left;
    // 产生式右部
    std::vector<Symbol> right;
    // 产生式对应的动作
    // TODO action能否捕获left, right中对应的值
    ActionFunction action;

public:
    Rule();
    Rule(Symbol left);
    Rule(Symbol left, std::vector<Symbol> right, ActionFunction action) : left(left), right(right), action(action) {}
    Symbol getLeft();
    void addRight(Symbol right);
    void print();

    friend std::ostream &operator<<(std::ostream &os, const Rule &rule)
    {
        os << rule.left << PRODUCTION_CONCAT;
        for (auto &symbol : rule.right)
        {
            os << symbol << " ";
        }
        return os;
    }
};
namespace Rules
{
    // 终结符
    extern std::set<Symbol> termVec;
    // 非终结符
    extern std::set<Symbol> nonTermVec;
    // 产生式集合
    extern std::vector<Rule> rules;
    void printNonTermVec();
    void printTermVec();
    void printRules();

}

#endif
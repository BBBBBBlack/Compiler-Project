#ifndef RULE_HPP
#define RULE_HPP

#include <vector>
#include <string>
#include <unordered_set>
#include <stack>
#include "ParseTabStruct.hpp"
#include "Token.hpp"

#define PRODUCTION_CONCAT "->"

// TODO 产生式动作的save和load
using ActionFunction = std::function<int(Token &leftToken, std::vector<Token> &rightTokens)>;
/*
 * 产生式类
 */
class Rule
{
public:
    // 产生式编号
    int id;
    // 产生式左部
    Symbol left;
    // 产生式右部
    std::vector<Symbol> right;
    // TODO action能否捕获left, right中对应的值
    ActionFunction action;
    // 是否遍历过
    bool visited = false;

public:
    Rule(int id);
    Rule(int id, Symbol left);
    Rule(int id, Symbol left, std::vector<Symbol> right);
    Rule(Symbol left, std::vector<Symbol> right, ActionFunction action) : left(left), right(right), action(action) {}
    int getId() const;
    Symbol getLeft() const;
    std::vector<Symbol> getRight() const;
    void setRight(std::vector<Symbol> right);
    void addRight(Symbol right);
    // 判断是否为ε产生式
    bool isEpsilon() const;
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

class SubRule : public Rule
{
private:
    int dotPos;

public:
    bool operator==(const SubRule &subRule2) const
    {
        // Determine whether subRule1 is equivalent to subRule2.
        // This is just an example. You should determine the equivalence based on your actual needs.
        return getId() == subRule2.getId() && getDotPos() == subRule2.getDotPos();
    }
    SubRule(const Rule &rule, int dotPos);
    int getDotPos() const;
    void print();
};

struct SubRuleHash
{
    std::size_t operator()(const SubRule &subRule) const
    {
        std::size_t h1 = std::hash<int>()(subRule.getId());
        std::size_t h2 = std::hash<int>()(subRule.getDotPos());
        return h1 ^ (h2 << 1);
    }
};
#endif // !RULE_HPP
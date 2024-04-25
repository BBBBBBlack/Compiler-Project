#include <vector>
#include <string>
#include <set>
#include "ParseTabStruct.hpp"
// 产生式类
class Rule
{
private:
    // 产生式左部
    Symbol left;
    // 产生式右部
    std::vector<Symbol> right;

public:
    Rule();
    Rule(Symbol left);
    Symbol getLeft();
    void addRight(Symbol right);
    void print();
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

#include "Symbol.hpp"

std::map<std::string, OperatorType> Symbol::operatorMap = {
    {"|", OR},
    {"-", UNION},
    {"*", CLOSURE},
    {"+", POSITIVE_CLOSURE},
    {"?", ZERO_OR_ONE}};

std::unordered_map<char, int> Symbol::opOrder = {
    {'\\', 0},
    {'(', 999},
    {')', 1},
    {'*', 2},
    {'+', 3},
    {'?', 4},
    {'-', 5},
    {'|', 998}};

std::unordered_map<char, bool> Symbol::unaryOpMap = {
    {'*', true},
    {'+', true},
    {'?', true}};

Symbol::Symbol(std::string character, bool operatorFlag) : character(character), operatorFlag(operatorFlag),
                                                           operatorType(EPSILON) {}

Symbol::Symbol(char character, bool operatorFlag) : character(std::string(1, character)), operatorFlag(operatorFlag),
                                                    operatorType(EPSILON) {}

Symbol::Symbol(OperatorType operatorType) : character(""), operatorFlag(true), operatorType(operatorType) {}

Symbol::Symbol() : character(""), operatorFlag(false), operatorType(EPSILON) {}

Symbol::~Symbol() {}

bool Symbol::operator<(const Symbol &symbol) const
{
    if (operatorFlag != symbol.operatorFlag)
    {
        return operatorFlag < symbol.operatorFlag;
    }
    else if (operatorFlag)
    {
        // 运算符
        return operatorType < symbol.operatorType;
    }
    else
    {
        // 普通字符
        return character < symbol.character;
    }
}

std::string Symbol::getCharacter() const
{
    return character;
}

bool Symbol::getoperatorFlag() const
{
    return operatorFlag;
}

OperatorType Symbol::getOperatorType() const
{
    return operatorType;
}

Symbol Symbol::getSymbol(char character)
{
    return Symbol(character, false);
}

Symbol Symbol::getSymbol(OperatorType operatorType)
{
    return Symbol(operatorType);
}

bool Symbol::isOperator(char character)
{
    std::string regex(1, character);
    return operatorMap.find(regex) != operatorMap.end();
}

bool Symbol::isUnaryOp(char symbol)
{
    return unaryOpMap[symbol];
}
#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>

#define CHAR_UNION '_'
#define STR_UNION "_"

enum OperatorType
{
    EPSILON,          // 空
    LEFT_BRACKET,     // 左括号
    RIGHT_BRACKET,    // 右括号
    OR,               // |
    UNION,            // -
    CLOSURE,          // *
    POSITIVE_CLOSURE, // +
    ZERO_OR_ONE,      // ?
    ESCAPE            // 转义
};

/**
 * @brief 正则符号类
 */
class Symbol
{
public:
    Symbol(std::string character, bool operatorFlag);
    Symbol(char character, bool operatorFlag);
    Symbol(OperatorType operatorType);
    Symbol();
    ~Symbol();

    static std::unordered_map<char, int> opOrder;
    static std::unordered_map<char, bool> unaryOpMap;

    // 重载<运算符
    bool operator<(const Symbol &symbol) const;

    std::string getCharacter() const;
    bool getoperatorFlag() const;
    OperatorType getOperatorType() const;

    static Symbol getSymbol(char character);
    static Symbol getSymbol(OperatorType operatorType);

    /**
     * @brief 判断是否为运算符 (*,-,|,+,?)
     */
    static bool isOperator(char character);
    static bool isUnaryOp(char symbol);
    static bool needEscape(char symbol)
    {
        return needEscapeSet.find(symbol) != needEscapeSet.end();
    }

private:
    std::string character;     // 符号
    bool operatorFlag;         // 是否为运算符
    OperatorType operatorType; // 运算符类型
    static std::map<std::string, OperatorType> operatorMap;
    static std::unordered_set<char> needEscapeSet;
};

#endif // SYMBOL_HPP
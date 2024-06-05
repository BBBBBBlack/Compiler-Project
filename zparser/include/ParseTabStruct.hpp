#ifndef PARSE_TAB_STRUCT_HPP
#define PARSE_TAB_STRUCT_HPP

#include "pch.hpp"
#include "Token.hpp"

// enum class Symbol;
// std::unordered_map<Symbol, std::string> symbolToString;
// std::unordered_map<std::string, Symbol> stringToSymbol;

typedef std::string Symbol;

enum ActionType : short
{
    A_Shift = 1,
    A_Reduce,
    A_Goto,
    A_Accept,
    A_Error
};

struct Action
{
    ActionType type; // action的类型
    int data;        // action的数据 (shift: stateId, reduce: productionId)

    friend std::ostream &operator<<(std::ostream &os, Action &action)
    {
        switch (action.type)
        {
        case A_Shift:
            os << "S" << action.data;
            break;
        case A_Reduce:
            os << "R" << action.data;
            break;
        case A_Goto:
            os << "G" << action.data;
            break;
        case A_Accept:
            os << "ACC";
            break;
        case A_Error:
            os << " ";
            break;
        default:
            break;
        }

        return os;
    }
    friend std::istream &operator>>(std::istream &in, Action &action)
    {
        char ch;
        // 读取一个字符以确定操作类型
        in >> ch;

        // 根据读取的字符设置 action.type
        switch (ch)
        {
        case 'S':
            action.type = A_Shift;
            // 读取 shift 数据
            in >> action.data;
            break;
        case 'R':
            action.type = A_Reduce;
            // 读取 reduce 数据
            in >> action.data;
            break;
        case 'G':
            action.type = A_Goto;
            // 读取 goto 数据
            in >> action.data;
            break;
        case 'A':
            // 假设输入为 "ACC" 表示 A_Accept
            if (in.get() == 'C' && in.get() == 'C')
            {
                action.type = A_Accept;
            }
            else
            {
                // 格式错误，可以设置错误位
                in.setstate(std::ios::failbit);
            }
            break;
        default:
            // 如果输入的字符不是 S、R 或 A，可以将其视为 A_Error 或其他适当的错误处理
            action.type = A_Error;
            action.data = -1;
            break;
        }

        // 返回输入流的引用
        return in;
    }

    Action(ActionType type, int data) : type(type), data(data) {}
    Action(ActionType type) : type(type) {}
    Action() {}
    Action(std::string str)
    {
        std::istringstream in(str);
        in >> *this;
    }
    void printActions()
    {
        std::string actionString;
        switch (type)
        {
        case A_Shift:
            actionString = "A_Shift";
            break;
        case A_Reduce:
            actionString = "A_Reduce";
            break;
        case A_Goto:
            actionString = "A_Goto";
            break;
        case A_Accept:
            actionString = "A_Accept";
            break;
        case A_Error:
            actionString = "A_Error";
            break;
        default:
            actionString = "Unknown action";
        }
        printf("%s%d", actionString.c_str(), data);
    }
};

// // TODO 产生式动作的save和load
// using ActionFunction = std::function<int(Token &leftToken, std::vector<Token> &rightTokens)>;
// struct Production
// {
//     Symbol left;               // 产生式左部
//     std::vector<Symbol> right; // 产生式右部
//     // note: $1引用到的是产生式右部的第一个符号的值, 而非符号本身
//     // TODO 捕获left, right对应的值
//     ActionFunction action; // 产生式对应的动作

//     friend std::ostream &operator<<(std::ostream &os, const Production &production)
//     {
//         os << production.left << PRODUCTION_CONCAT;
//         for (auto &symbol : production.right)
//         {
//             os << symbol << " ";
//         }
//         return os;
//     }
// };

/**
 * @brief 分析表中状态
 */
struct State
{
    std::unordered_map<Symbol, Action> actions; // action表 (key: TermType, value: Action)

    State(const std::unordered_map<Symbol, Action> &actions)
        : actions(actions) {}
    State() {}
};

#endif // !PARSE_TAB_STRUCT_HPP
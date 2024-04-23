#ifndef PARSE_TAB_HPP
#define PARSE_TAB_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

enum ActionType : short
{
    A_Shift = 1,
    A_Reduce,
    A_Accept,
    A_Error
};

struct Action
{
    ActionType type; // action的类型
    int data;        // action的数据
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
};

struct State
{
    std::unordered_map<int, Action> actions; // action表 (key: TermType, value: Action)
    std::unordered_map<int, int> gotos;      // goto表 (key: NonTermType, value: StateId(-1:error))

    State(const std::unordered_map<int, Action> &actions, const std::unordered_map<int, int> &gotos)
        : actions(actions), gotos(gotos) {}
    State() {}
};

class ParseTab
{
public:
    ParseTab();
    ~ParseTab();
    void setStates(std::vector<State> states)
    {
        this->states = states;
    }
    void saveParseTab(const std::string &filename);
    void loadParseTab(const std::string &filename);

    void setTermVec(const std::vector<std::string> &termVec)
    {
        this->termVec = termVec;
    }
    void setNonTermVec(const std::vector<std::string> &nonTermVec)
    {
        this->nonTermVec = nonTermVec;
    }

private:
    std::vector<State> states;
    std::vector<std::string> termVec;    // 终结符类型字符串
    std::vector<std::string> nonTermVec; // 非终结符类型字符串
};

#endif // !PARSE_TAB_HPP
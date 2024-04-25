#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "pch.hpp"

struct Token
{
    std::string type;  // such as: NUM, ID, IF, ELSE, ...
    std::string value; // NUM, ID有value
    int lineno;
    int pos;

    friend std::istream &operator>>(std::istream &in, Token &token)
    {
        char ch;
        in >> ch; // 读取 '<'

        std::string line;
        std::getline(in, line, '>'); // 读取到 '>'

        std::stringstream ss(line);
        std::getline(ss >> std::ws, token.type, ',');  // 读取类型
        std::getline(ss >> std::ws, token.value, ','); // 读取值

        ss >> token.lineno; // 读取行号
        ss.ignore(1);       // 忽略 ','
        ss >> token.pos;    // 读取位置

        return in;
    }

    Token(std::string type, std::string value, int lineno, int pos)
        : type(type), value(value), lineno(lineno), pos(pos) {}
    Token() = default;
    Token(std::string type) : type(type) {}
};

#endif // TOKEN
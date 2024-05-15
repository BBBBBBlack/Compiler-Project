#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "pch.hpp"
#define EPSILON "ε"

struct Token
{
    std::string type;  // such as: NUM, ID, IF, ELSE, ...
    std::string value; // NUM, ID有value
    int lineno;
    int pos;

    friend std::istream &operator>>(std::istream &in, Token &token)
    {
        std::regex pattern("<(.*?),(.*?),(.*?),(.*?)>");
        std::smatch matches;
        std::string line;
        std::getline(in, line);

        if (std::regex_match(line, matches, pattern))
        {
            token.type = matches[1];
            token.value = matches[2];
            token.lineno = std::stoi(matches[3]);
            token.pos = std::stoi(matches[4]);
        }

        return in;
    }

    Token(std::string type, std::string value, int lineno, int pos)
        : type(type), value(value), lineno(lineno), pos(pos) {}
    Token() = default;
    Token(std::string type) : type(type) {}
    Token(std::string type, std::string value) : type(type), value(value) {}

    Token static getEpsilon()
    {
        return Token(EPSILON, EPSILON);
    }
};

#endif // TOKEN
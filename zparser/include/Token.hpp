#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "pch.hpp"
#define EPSILON "ε"

using TokenType = std::string;
using TokenValue = std::string;

struct Token
{
    TokenType type;   // such as: NUM, ID, IF, ELSE, ...
    TokenValue value; // NUM, ID有value
    // 用于存储多种属性
    std::unordered_map<TokenType, TokenValue> valMap;
    int lineno;
    int pos;

    std::string &operator[](TokenType key)
    {
        // if (valMap.find(key) == valMap.end())
        // {
        //     throw std::runtime_error("Token has no key: " + key);
        // }
        return valMap[key];
    }

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
            if (token.type == "id")
            {
                token.valMap["lexeme"] = token.value;
            }
            else if (token.type == "num")
            {
                token.valMap["val"] = token.value;
            }
        }

        return in;
    }

    Token(TokenType type, TokenValue value, int lineno, int pos)
        : type(type), value(value), lineno(lineno), pos(pos) {}
    Token(TokenType type, std::string value) : type(type), value(value) {}
    Token(TokenType type) : type(type) {}
    Token() = default;

    Token static getEpsilon()
    {
        return Token(EPSILON, EPSILON);
    }
};

#endif // !TOKEN_HPP
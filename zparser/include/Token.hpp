#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "pch.hpp"
#define EPSILON "ε"

struct Token
{
    std::string type;  // such as: NUM, ID, IF, ELSE, ...
    std::string value; // NUM, ID有value
    std::unordered_map<std::string, std::string> valMap;
    int lineno;
    int pos;

    std::string &operator[](std::string key)
    {
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

    Token(std::string type, std::string value, int lineno, int pos)
        : type(type), value(value), lineno(lineno), pos(pos) {}
    Token() = default;
    Token(std::string type) : type(type) {}
    Token(std::string type, std::string value);

    Token static getEpsilon()
    {
        return Token(EPSILON, EPSILON);
    }
};

#endif // !TOKEN_HPP
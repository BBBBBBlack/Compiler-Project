#include "Token.hpp"
Token::Token(std::string type, std::string value) : type(type), value(value)
{
    if (type == "id")
    {
        valMap["lexeme"] = value;
    }
    else if (type == "num")
    {
        valMap["val"] = value;
    }
}
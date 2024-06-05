#include "Token.hpp"
Token::Token(TokenType type, TokenValue value) : type(type), value(value)
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
#include "Token.hpp"

Token::Token(std::string character, std::ofstream &tokenOut, bool isDigit)
    : character(character), tokenOut(tokenOut), isDigit(isDigit) {}

std::map<std::string, int> Token::operatorMap = {
    {"int", T_Int},
    {"float", T_Float},
    {"double", T_Double},
    {"long", T_Long},
    {"if", T_If},
    {"else", T_Else},
    {"while", T_While},
    {"for", T_For},
    {"do", T_Do},
    {"break", T_Break},
    {"continue", T_Continue},
    {"return", T_Return},
    {"void", T_Void},
    {"main", T_Main},
    {"{", '{'},
    {"}", '}'},
    {"(", '('},
    {")", ')'},
    {"[", '['},
    {"]", ']'},
    {";", ';'},
    {",", ','},
    {"=", '='},
    {"<", '<'},
    {"<=", T_Le},
    {">", '>'},
    {">=", T_Ge},
    {"==", T_Equal},
    {"!=", T_Noequal},
    {"+", '+'},
    {"-", '-'},
    {"*", '*'},
    {"/", '/'},
    {"%", '%'},
    {"++", T_Increment},
    {"--", T_Decrement},
    {"+=", T_Add_Assignment},
    {"-=", T_Sub_Assignment},
    {"*=", T_Mul_Assignment},
    {"/=", T_Divid_Assignment},
    {"%=", T_Mode_Assignment},
    {"&&", T_And},
    {"||", T_Or},
};

void Token::print_token()
{
    if (isDigit)
    {
        tokenOut << "< num, " << character << ">" << std::endl;
    }
    else if (operatorMap.count(character))
    {
        tokenOut << "<" << character << ">" << std::endl;
    }
    else
    {
        tokenOut << "< id, " << character << ">" << std::endl;
    }
}
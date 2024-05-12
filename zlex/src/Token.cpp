#include "Token.hpp"
#include "ZLex.hpp"

std::unordered_set<std::pair<std::string, std::string>, pair_hash> SymbolTable::symbolTable;

void SymbolTable::addToSymbolTable(std::string type, std::string name)
{
    if (type != "")
    {
        symbolTable.insert(std::make_pair(type, name));
    }
}

void SymbolTable::printSymbolTable(std::ofstream &symbolOut)
{
    symbolOut << "Symbol Table" << std::endl;
    symbolOut << "Type\tName" << std::endl;
    std::vector<std::pair<std::string, std::string>> vec(SymbolTable::symbolTable.begin(), SymbolTable::symbolTable.end());

    // 对 vector 进行排序
    std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
              { return a.first < b.first; });
    for (const auto &pair : vec)
    {
        symbolOut << pair.first << "\t" << pair.second << std::endl;
    }
}

Token::Token(std::string character, std::ofstream &tokenOut, bool isDigit)
    : character(character), tokenOut(tokenOut), isDigit(isDigit) {}

std::map<std::string, int> Token::operatorMap = {
    {"int", T_Int},
    {"float", T_Float},
    {"double", T_Double},
    {"char", T_Char},
    {"long", T_Long},
    {"short", T_Short},
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
    {"id", T_Id},
    {"num", T_Num},
    {"signed", T_Signed},
    {"unsigned", T_Unsigned},
    {"static", T_Static},
    {"const", T_Const},
    {"extern", T_Extern},
    {"enum", T_Enum},
    {"goto", T_Goto},
    {"switch", T_Switch},
    {"case", T_Case},
    {"default", T_Default},
    {"struct", T_Struct},
    {"typedef", T_Typedef}};

void Token::print_token()
{
    if (isDigit)
    {
        tokenOut << "<num," << character << "," << yylineno << "," << yypos << ">" << std::endl;
    }
    else if (operatorMap.count(character))
    {
        tokenOut << "<" << character << "," << character << "," << yylineno << "," << yypos << ">" << std::endl;
    }
    else
    {
        tokenOut << "<variable," << character << "," << yylineno << "," << yypos << ">" << std::endl;
    }
}
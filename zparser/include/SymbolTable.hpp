#ifndef SYMBOLTABLE_HPP
#define SYMBOLTABLE_HPP

#include "pch.hpp"
#include "Token.hpp" // Assuming Token is defined in this file

struct Record
{
    std::string lexeme;
    std::string type;
    int offset;
};

namespace SymbolTable
{
    extern std::vector<Record> symbolTable; // Declare the variable in the header file
    void put_to_symbol_table(std::string lexeme, std::string type, int offset);
    void get_from_symbol_table(std::string lexeme, Token &token);
    void print_symbol_table();
    Token get_token_stack(std::vector<Token> &tokenStack, int re_offset);
};

#endif // !SYMBOLTABLE_HPP
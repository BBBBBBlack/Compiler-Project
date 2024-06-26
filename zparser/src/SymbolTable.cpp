#include "SymbolTable.hpp"

namespace SymbolTable
{
    std::vector<Record> symbolTable; // Define the variable in a .cpp file

    void put_to_symbol_table(std::string lexeme, std::string type, int offset, bool isTemp)
    {
        symbolTable.push_back({lexeme, type, offset, isTemp});
    }

    void get_from_symbol_table(std::string lexeme, Token &token)
    {
        for (auto &record : symbolTable)
        {
            if (record.lexeme == lexeme)
            {
                token["type"] = record.type;
                token["offset"] = std::to_string(record.offset);
                return;
            }
        }
    }

    void print_symbol_table()
    {
        std::cout << "Symbol Table" << std::endl;
        std::cout << "Lexeme\tType\tOffset" << std::endl;
        for (auto &record : symbolTable)
        {
            std::cout << record.lexeme << "\t" << record.type << "\t" << record.offset << std::endl;
        }
    }

    Token get_token_stack(std::vector<Token> &tokenStack, int re_offset)
    {
        int index = tokenStack.size() - re_offset;
        return tokenStack[index];
    }
}
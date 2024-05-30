#include "SymbolTable.hpp"

namespace SymbolTable
{
    std::list<Record> symbolTable; // Define the variable in a .cpp file

    void put_to_symbol_table(std::string lexeme, std::string type, int offset)
    {
        symbolTable.push_back({lexeme, type, offset});
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

    Token get_token_stack(std::vector<std::pair<int, Token>> &tokenStack, int re_offset)
    {
        int index = tokenStack.size() - re_offset;
        return tokenStack[index].second;
    }
}
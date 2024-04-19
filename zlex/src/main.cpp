#include <iostream>
#include "ZLex.hpp"
#include "Token.hpp"
int main()
{
    std::string tokenTableOutput="../data/zlex_out/lexicalAnalysis.md";
    std::string FAFile="../data/zlex_out/FA.md";
    std::string symbolTable="../data/zlex_out/symbolTable.txt";
    std::string sourceFile="../data/zlex_in/source_code.txt";
    bool printFA=1;
    std::string folderPath = tokenTableOutput.substr(0, tokenTableOutput.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    std::ofstream tokenFile(tokenTableOutput, std::ios::trunc);
    folderPath = tokenTableOutput.substr(0, symbolTable.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    std::ofstream symbolTableFile(symbolTable, std::ios::trunc);
    ZLex zlex;
    std::string &yytext_ref = yytext;
    PAVec paVec = {
        {"\\\t|\\\n| ", [&]() -> int
        {
            
            return 0;
        },
        ""},
        {"[0-9]+(.[0-9]+)?", [&]() -> int
        {
            Token token(yytext, tokenFile, true);token.print_token();
            return 0;
        },
        "NUMBER"},
        {"int", [&]() -> int
        {
            Token token(yytext, tokenFile, true);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"float", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"double", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"long", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"if", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"else", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"while", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"for", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"do", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"break", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"continue", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"return", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"void", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"main", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "IDENTIFIER"},
        {"{", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"}", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"\\(", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"\\)", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"\\[", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"\\]", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {";", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {",", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"=", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"<", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"<=", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {">", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {">=", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"==", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"\\!=", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"\\+", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"-", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"\\*", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"/", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"%", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"\\+\\+", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"--", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"\\+=", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"-=", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"\\*=", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"/=", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"%=", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"&&", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"\\|\\|", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"[a-zA-Z\\_]+[a-zA-Z0-9\\_]*", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "IDENTIFIER"},
    };
    zlex.buildAndAnalysis(printFA, paVec, FAFile, tokenFile, sourceFile);
    SymbolTable::printSymbolTable(symbolTableFile);
    return 0;
}

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
        {"//[ -~]*\\\n", [&]() -> int
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
        {"signed", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"unsigned", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"int", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
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
        {"char", [&]() -> int
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
        {"short", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"static", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"const", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"extern", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"enum", [&]() -> int
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
        {"goto", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"switch", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"case", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"default", [&]() -> int
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
        {"&", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"!", [&]() -> int
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
        {"struct", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"typedef", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        "KEYWORD"},
        {"\"", [&]() -> int
        {
            Token token(yytext, tokenFile, false);token.print_token();
            return 0;
        },
        ""},
        {"[0-9]+[a-zA-Z]+", [&]() -> int
        {
            tokenFile << "[ERROR] at line " << yylineno<< " position " << yypos << ":[" << "error identifier:" << yytext << "]" << std::endl;
            return 0;
        },
        ""},
    };
    zlex.buildAndAnalysis(printFA, paVec, FAFile, tokenFile, sourceFile);
    SymbolTable::printSymbolTable(symbolTableFile);
    return 0;
}

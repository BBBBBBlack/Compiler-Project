#include <iostream>
#include "ZLex.hpp"
int main()
{
    std::string tokenTableOutput = "zlex_out/lexicalAnalysis.md";
    std::string FAFile = "zlex_out/FA.md";
    std::string sourceFile = "/home/jader/course/my_compiler/zlex/resource/test/test2.txt";
    bool printFA = 1;
    std::string folderPath = tokenTableOutput.substr(0, tokenTableOutput.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    std::ofstream tokenFile(tokenTableOutput, std::ios::trunc);
    ZLex zlex;
    std::string &yytext_ref = yytext;
    PAVec paVec = {
        {"\\\t|\\\n| ", [&]() -> int
         {
             return 0;
         },
         "nothing"},
        {"[0-9]+(.[0-9]+)?", [&]() -> int
         {
             Token token(yytext, tokenFile, true);
             token.print_token();
             return 0;
         },
         "digit"},
        {"int", [&]() -> int
         {
             Token token(yytext, tokenFile, true);
             token.print_token();
             return 0;
         },
         "int"},
        {"float", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "float"},
        {"double", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "double"},
        {"long", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "long"},
        {"if", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "if"},
        {"else", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "else"},
        {"while", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "while"},
        {"for", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "for"},
        {"do", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "do"},
        {"break", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "break"},
        {"continue", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "continue"},
        {"return", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "return"},
        {"void", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "void"},
        {"main", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "main"},
        {"{", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "{"},
        {"}", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "}"},
        {"\\(", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "("},
        {"\\)", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         ")"},
        {"\\[", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "["},
        {"\\]", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "]"},
        {";", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         ";"},
        {",", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         ","},
        {"=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "="},
        {"<", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "<"},
        {"<=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "<="},
        {">", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         ">"},
        {">=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         ">="},
        {"==", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "=="},
        {"\\!=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "!="},
        {"\\+", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "+"},
        {"-", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "-"},
        {"\\*", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "*"},
        {"/", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "/"},
        {"%", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "%"},
        {"\\+\\+", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "++"},
        {"--", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "--"},
        {"\\+=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "+="},
        {"-=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "-="},
        {"\\*=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "*="},
        {"/=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "/="},
        {"%=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "%="},
        {"&&", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "&&"},
        {"\\|\\|", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "||"},
        {"[a-zA-Z\\_]+[a-zA-Z0-9\\_]*", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "identifier"},
    };
    zlex.buildAndAnalysis(printFA, paVec, FAFile, tokenFile, sourceFile);
    return 0;
}

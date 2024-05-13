#include "Parser.hpp"

#include <iostream>
#include <string>

void setRules(ParseTab &parseTab)
{
    std::vector<Rule> rules;
    rules.push_back(Rule({"S", {"program"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "A";
                              return 0;
                          }}));
    rules.push_back(Rule({"program", {"basics", "id", "(", ")", "block"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"block", {"{", "declarations", "stmts", "}"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"declarations", {"declaration", "declarations"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"declarations", {"ε"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"declaration", {"basics", "id", ";"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"declaration", {"array_declaration", ";"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"basics", {"int"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"basics", {"float"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmts", {"stmt", "stmts"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmts", {"ε"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"assignment"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"declaration"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"array_assignment"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"while_loop"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"if_stmt"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"break_stmt"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"assignment", {"id", "=", "expr", ";"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"array_declaration", {"basics", "id", "[", "num", "]"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"array_assignment", {"id", "[", "num", "]", "=", "expr", ";"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"while_loop", {"while", "(", "bool", ")", "stmt_or_block"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt_or_block", {"stmt"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt_or_block", {"block"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"if_stmt", {"if", "(", "bool", ")", "stmt_or_block", "block_tail"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"block_tail", {"ε"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"block_tail", {"else", "stmt_or_block"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"bool", "||", "join"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"join"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"join", {"join", "&&", "equality"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"join", {"equality"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"equality", {"equality", "==", "rel"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"equality", {"equality", "!=", "rel"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"equality", {"rel"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"rel", {"expr", "<", "expr"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"rel", {"expr", "<=", "expr"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"rel", {"expr", ">", "expr"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"rel", {"expr", ">=", "expr"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"rel", {"expr"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"expr", "+", "term"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"expr", "-", "term"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"term"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"term", {"term", "*", "unary"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"term", {"term", "/", "unary"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"term", {"unary"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"unary", {"!", "unary"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"unary", {"-", "unary"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"unary", {"factor"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"factor", {"(", "expr", ")"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"factor", {"id"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"factor", {"id", "[", "num", "]"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"factor", {"num"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"factor", {"true"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"factor", {"false"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    rules.push_back(Rule({"break_stmt", {"break", ";"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "B";
                              return 0;
                          }}));
    parseTab.setRules(rules);
}

static struct option long_options[] = {
    {"input", required_argument, 0, 'i'},
    {"table", optional_argument, 0, 't'},
    {"output", optional_argument, 0, 'o'},
    {"process", optional_argument, 0, 'p'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0} // 结束标志
};

int main(int argc, char *argv[])
{
    char options[] = "i:t:o:p:";

    ParseTab tab;
    std::string tokenFile;
    std::string tableFile = DEFAULT_TABLE_FILE;
    std::string outputFile = DEFAULT_OUTPUT_FILE;
    std::string processFile = DEFAULT_PROCESS_FILE;
    int opt;
    while ((opt = getopt_long(argc, argv, options, long_options, nullptr)) != -1)
    {
        switch (opt)
        {
        case 'i':
            tokenFile = optarg;
            break;
        case 't':
            tableFile = optarg;
            break;
        case 'o':
            outputFile = optarg;
            break;
        case 'p':
            processFile = optarg;
            break;
        case 'h':
        default: // 打印帮助信息
            std::cout << "Usage: " << argv[0] << std::endl;
            std::cout << " -i/--input \t<token file>" << std::endl;
            std::cout << " -t/--table \t<table file>" << std::endl;
            std::cout << " -o/--output \t<output file>" << std::endl;
            std::cout << " -p/--process \t<process file>" << std::endl;

            return 0;
            break;
        }
    }

    std::cout << "token file: " << tokenFile << std::endl;
    std::cout << "table file: " << tableFile << std::endl;
    std::cout << "output file: " << outputFile << std::endl;
    std::cout << "process file: " << processFile << std::endl;

    setRules(tab);
    tab.loadFromFile(tableFile);
    Parser parser(tab);
    parser.setOutputFile(outputFile);
    parser.grammarAnalysis(tokenFile, processFile);
    return 0;
}

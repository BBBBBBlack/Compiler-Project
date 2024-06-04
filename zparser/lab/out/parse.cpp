/*
 * This file is generated by ZTableGenerator
 * Do not modify this file
 *  _________   _    ____  ____  _____ ____  
 * |__  /  _ \ / \  |  _ \/ ___|| ____|  _ \ 
 *   / /| |_) / _ \ | |_) \___ \|  _| | |_) |
 *  / /_|  __/ ___ \|  _ < ___) | |___|  _ < 
 * /____|_| /_/   \_\_| \_\____/|_____|_| \_\
 */
#include "Parser.hpp"
#include "Tool.hpp"

#include <iostream>
#include <string>

void setRules(ParseTab &parseTab)
{
    std::vector<Rule> rules;
    rules.push_back(Rule({"program", {"A", "basic", "id", "(", ")", "block"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"A", {"ε"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              offset = 0;
                              return 0;
                          }}));
    rules.push_back(Rule({"block", {"{", "decls", "stmts", "}"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"stmts", {"ε"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"decls", {"decl", "decls"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"decls", {"ε"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"decl", {"type", "id", ";"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              std::string lexeme = rightTokens[1]["lexeme"];
                              std::string type = rightTokens[0]["type"];
                              SymbolTable::put_to_symbol_table(lexeme, type, offset);
                              offset += std::stoi(rightTokens[0]["width"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"type", {"basic", "B", "array"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              leftToken["type"] = rightTokens[2]["type"];
                              leftToken["width"] = rightTokens[2]["width"];
                              return 0;
                          }}));
    rules.push_back(Rule({"B", {"ε"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              t = SymbolTable::get_token_stack(tokenStack, 1)["type"];
                              w = std::stoi(SymbolTable::get_token_stack(tokenStack, 1)["width"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"array", {"ε"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              leftToken["type"] = t;
                              leftToken["width"] = std::to_string(w);
                              return 0;
                          }}));
    rules.push_back(Rule({"array", {"[", "num", "]", "array"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              leftToken["type"] = "array(" + rightTokens[1]["val"] + ", " + rightTokens[3]["type"] + ")";
                              leftToken["width"] = std::to_string(std::stoi(rightTokens[1]["val"]) * std::stoi(rightTokens[3]["width"]));
                              return 0;
                          }}));
    rules.push_back(Rule({"basic", {"float"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              leftToken["type"] = "float";
                              leftToken["width"] = "4";
                              return 0;
                          }}));
    rules.push_back(Rule({"basic", {"int"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              leftToken["type"] = "int";
                              leftToken["width"] = "4";
                              return 0;
                          }}));
    rules.push_back(Rule({"basic", {"real"}, [&](Token &leftToken, std::vector<Token> &rightTokens, std::vector<std::pair<int, Token>> &tokenStack, std::vector<std::pair<std::string, std::string>> &tempToken) -> int
                          {
                              leftToken["type"] = "real";
                              leftToken["width"] = "8";
                              return 0;
                          }}));
    parseTab.setRules(rules);
}

bool error_flag = false;
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
    char options[] = "i:t:o:p:h:";

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
            removeSpaces(optarg);
            tokenFile = optarg;
            break;
        case 't':
            removeSpaces(optarg);
            tableFile = optarg;
            break;
        case 'o':
            removeSpaces(optarg);
            outputFile = optarg;
            break;
        case 'p':
            removeSpaces(optarg);
            processFile = optarg;
            break;
        case 'h':
        default: // 打印帮助信息
            std::cout << "Usage: " << argv[0] << std::endl;
            std::cout << "[REQUIRED] -i/--input \t<token file>" << std::endl;
            std::cout << "[OPTIONAL] -t/--table \t<table file>" << std::endl;
            std::cout << "[OPTIONAL] -o/--output \t<output file>" << std::endl;
            std::cout << "[OPTIONAL] -p/--process \t<process file>" << std::endl;

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

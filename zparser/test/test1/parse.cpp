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
#include "ExposeFun.hpp"

void setRules(ParseTab &parseTab);
#include <iostream>
#include <string>
using namespace std;

static struct option long_options[] = {
    {"input", required_argument, 0, 'i'},
    {"table", optional_argument, 0, 't'},
    {"output", optional_argument, 0, 'o'},
    {"process", optional_argument, 0, 'p'},
    {"code", optional_argument, 0, 'c'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0} // 结束标志
};

// ParserFun.hpp中声明了 ParseTab tab; Parser parser(tab);

int main(int argc, char *argv[])
{
    char options[] = "i:t:o:p:h:c:";

    std::string tokenFile;
    std::string tableFile = DEFAULT_TABLE_FILE;
    std::string outputFile = DEFAULT_OUTPUT_FILE;
    std::string processFile = DEFAULT_PROCESS_FILE;
    std::string codeTargetFile = DEFAULT_CODE_TARGET_FILE;
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
        case 'c':
            removeSpaces(optarg);
            codeTargetFile = optarg;
            break;
        case 'h':
        default: // 打印帮助信息
            std::cout << "Usage: " << argv[0] << std::endl;
            std::cout << "[REQUIRED] -i/--input \t<token file>" << std::endl;
            std::cout << "[OPTIONAL] -t/--table \t<table file>" << std::endl;
            std::cout << "[OPTIONAL] -o/--output \t<output file>" << std::endl;
            std::cout << "[OPTIONAL] -p/--process \t<process file>" << std::endl;
            std::cout << "[OPTIONAL] -c/--code \t<code file>" << std::endl;

            return 0;
            break;
        }
    }

    std::cout << "token file: " << tokenFile << std::endl;
    std::cout << "table file: " << tableFile << std::endl;
    std::cout << "output file: " << outputFile << std::endl;
    std::cout << "process file: " << processFile << std::endl;
    std::cout << "code target file: " << codeTargetFile << std::endl;

    setRules(tab);
    tab.loadFromFile(tableFile);
    parser.setParseTab(tab);
    parser.setOutputFile(outputFile);
    parser.grammarAnalysis(tokenFile, processFile, codeTargetFile);
    return 0;
}
void setRules(ParseTab &parseTab)
{
    std::vector<Rule> rules;
    rules.push_back(Rule({"E", {"E", "+", "T"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken.value = to_string(stoi(rightTokens[0].value) + stoi(rightTokens[2].value));
                              return 0;
                          }}));
    rules.push_back(Rule({"E", {"T"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken.value = rightTokens[0].value;
                              return 0;
                          }}));
    rules.push_back(Rule({"T", {"T", "*", "F"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken.value = to_string(stoi(rightTokens[0].value) * stoi(rightTokens[2].value));
                              return 0;
                          }}));
    rules.push_back(Rule({"T", {"F"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken.value = rightTokens[0].value;
                              return 0;
                          }}));
    rules.push_back(Rule({"F", {"(", "E", ")"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken.value = rightTokens[1].value;
                              return 0;
                          }}));
    rules.push_back(Rule({"F", {"digit"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken.value = rightTokens[0].value;
                              return 0;
                          }}));
    parseTab.setRules(rules);
}


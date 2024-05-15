#include "Parser.hpp"

#include <iostream>
#include <string>

void setRules(ParseTab &parseTab)
{
    std::vector<Rule> rules;
    rules.push_back(Rule({"S", {"A"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "A";
                              return 0;
                          }}));
    rules.push_back(Rule({"A", {"B"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "A";
                              return 0;
                          }}));
    rules.push_back(Rule({"B", {"C"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "A";
                              return 0;
                          }}));
    rules.push_back(Rule({"C", {"A"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "A";
                              return 0;
                          }}));
    rules.push_back(Rule({"B", {"D"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "A";
                              return 0;
                          }}));
    rules.push_back(Rule({"D", {"B"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                          {
                              leftToken.value = "A";
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

#include "Config.hpp"
#include "FAStruct.hpp"
#include "ParseTab.hpp"

static struct option long_options[] = {
    {"config", required_argument, 0, 'c'},
    {"fa", optional_argument, 0, 'f'},
    {"table", optional_argument, 0, 't'},
    {"parse", optional_argument, 0, 'p'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0} // 结束标志
};

int main(int argc, char *argv[])
{
    char options[] = "h:f:c:t:p:";

    std::string configFile;
    std::string FAFile;
    std::string tableFile = DEFAULT_TABLE_FILE;
    std::string parseCpp = DEFAULT_PARSE_CPP;
    int opt;
    while ((opt = getopt_long(argc, argv, options, long_options, nullptr)) != -1)
    {
        switch (opt)
        {
        case 'c':
            configFile = optarg;
            break;
        case 'f':
            FAFile = optarg;
            break;
        case 't':
            tableFile = optarg;
            break;
        case 'p':
            parseCpp = optarg;
            break;
        case 'h':
        default:
            std::cout << "Usage: " << argv[0] << std::endl;
            std::cout << "[REQUIRED] -c/--config \t<config file>" << std::endl;
            std::cout << "[OPTIONAL] -f/--fa \t<fa file>" << std::endl;
            std::cout << "[OPTIONAL] -t/--table \t<table file>" << std::endl;
            std::cout << "[OPTIONAL] -p/--parse \t<parse.cpp file>" << std::endl;
            return 1;
        }
    }
    // 检测config文件是否存在
    if (access(configFile.c_str(), F_OK) == -1)
    {
        std::cerr << "Config file not found!" << std::endl;
        return 1;
    }

    Config myconfig(configFile);
    myconfig.analysis(parseCpp);
    Rules::genRuleMap();
    // Rules::addStart();
    Rules::getAllFirst();
    Rules::getFollow();

    // 构造自动机
    FA fa;
    fa.createFA(Rules::rules);
    if (!FAFile.empty())
    {
        fa.drawFA(FAFile);
    }
    std::vector<State> res = fa.createTable();
    Rules::transForAnalysisTable();
    ParseTab parseTab(res);
    parseTab.saveToFile(tableFile);

    // 打印输出文件位置
    std::cout << "Table file: " << tableFile << std::endl;
    std::cout << "Parse.cpp file: " << parseCpp << std::endl;
    if (!FAFile.empty())
    {
        std::cout << "FA file: " << FAFile << std::endl;
    }

    // TODO 编译出ZParser
    std::string command = "g++ -I ../include -o ZParser " + parseCpp + " libzparser_lib.a";
    int result = system(command.c_str());
    if (result != 0)
    {
        std::cerr << "Failed to compile ZParser" << std::endl;
        return 1;
    }
    std::cout << "ZParser compiled successfully" << std::endl;
}
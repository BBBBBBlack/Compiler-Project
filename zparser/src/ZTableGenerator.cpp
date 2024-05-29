#include "Config.hpp"
#include "FAStruct.hpp"
#include "ParseTab.hpp"
#include <limits.h>
#include <filesystem>

static struct option long_options[] = {
    {"include_path", required_argument, 0, 'i'},
    {"config", required_argument, 0, 'c'},
    {"fa", optional_argument, 0, 'f'},
    {"table", optional_argument, 0, 't'},
    {"parse", optional_argument, 0, 'p'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0} // 结束标志
};
// 去除字符串中的空格
void removeSpaces(char *str)
{
    // 将 char* 转换为 std::string
    std::string strValue = str;

    // 使用算法去除空格
    strValue.erase(std::remove_if(strValue.begin(), strValue.end(), ::isspace), strValue.end());

    // 将处理后的字符串复制回 char*
    strcpy(str, strValue.c_str());
}
int main(int argc, char *argv[])
{
    char options[] = "i:h:f:c:t:p:";

    std::string includePath;
    std::string configFile;
    std::string FAFile;
    std::string tableFile = DEFAULT_TABLE_FILE;
    std::string parseCpp = DEFAULT_PARSE_CPP;
    int opt;
    while ((opt = getopt_long(argc, argv, options, long_options, nullptr)) != -1)
    {
        switch (opt)
        {
        case 'i':
            removeSpaces(optarg);
            includePath = optarg;
            break;
        case 'c':
            removeSpaces(optarg);
            configFile = optarg;
            break;
        case 'f':
            removeSpaces(optarg);
            FAFile = optarg;
            break;
        case 't':
            removeSpaces(optarg);
            tableFile = optarg;
            break;
        case 'p':
            removeSpaces(optarg);
            parseCpp = optarg;
            break;
        case 'h':
        default:
            std::cout << "Usage: " << argv[0] << std::endl;
            std::cout << "[REQUIRED] -i/--include_path \t<include path>" << std::endl;
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
    Rules::addStart();
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

    // 获取当前可执行文件的路径
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    std::string full_path(result, (count > 0) ? count : 0);

    // 获取路径中的目录部分
    std::filesystem::path p(full_path);
    std::string directory = p.parent_path();

    // 将目录添加到 "libzparser_lib.a" 前面
    std::string lib_path = directory + "/libzparser_lib.a";

    std::string command = "g++ -I " + includePath +
                          " -o ZParser " + parseCpp + " " + lib_path +
                          " -std=c++17 -O0 -g";
    int cli_res = system(command.c_str());
    if (cli_res != 0)
    {
        std::cerr << "Failed to compile ZParser" << std::endl;
        return 1;
    }
    std::cout << "ZParser compiled successfully" << std::endl;
}
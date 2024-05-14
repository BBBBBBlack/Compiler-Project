#ifndef PCH_HPP
#define PCH_HPP

#define DEFAULT_PARSE_CPP "zparser/parse.cpp"
#define DEFAULT_TABLE_FILE "zparser/out/table.md"
#define DEFAULT_OUTPUT_FILE "zparser/out/output.md"
#define DEFAULT_PROCESS_FILE "zparser/out/process.md"

// 管理所有头文件, 避免重复include

#include <iostream>
#include <string>
#include <unistd.h>
#include <getopt.h>

// 容器库
#include <list>
#include <vector>
#include <stack>
#include <unordered_map>

// 流操作库
#include <fstream>
#include <sstream>
#include <filesystem>

// ActionFunction用到的库
#include <any>
#include <functional>

// json
#include <nlohmann/json.hpp>
using json = nlohmann::json;

// 正则表达式
#include <regex>

#define BANNER                                         \
    " _________   _    ____  ____  _____ ____  \n"     \
    "|__  /  _ \\ / \\  |  _ \\/ ___|| ____|  _ \\ \n" \
    "  / /| |_) / _ \\ | |_) \\___ \\|  _| | |_) |\n"  \
    " / /_|  __/ ___ \\|  _ < ___) | |___|  _ < \n"    \
    "/____|_| /_/   \\_\\_| \\_\\____/|_____|_| \\_\\\n"

#define BANNER_WITH_ANNOTATION_SYMBOLS                    \
    " *  _________   _    ____  ____  _____ ____  \n"     \
    " * |__  /  _ \\ / \\  |  _ \\/ ___|| ____|  _ \\ \n" \
    " *   / /| |_) / _ \\ | |_) \\___ \\|  _| | |_) |\n"  \
    " *  / /_|  __/ ___ \\|  _ < ___) | |___|  _ < \n"    \
    " * /____|_| /_/   \\_\\_| \\_\\____/|_____|_| \\_\\\n"

#define VERSION "0.1.0"

#endif // !PCH.HPP
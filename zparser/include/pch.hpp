#ifndef PCH_HPP
#define PCH_HPP

#define DEFAULT_TABLE_FILE "out/table.md"
#define DEFAULT_OUTPUT_FILE "out/output.md"
#define DEFAULT_PROCESS_FILE "out/process.md"

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

#endif // !PCH.HPP
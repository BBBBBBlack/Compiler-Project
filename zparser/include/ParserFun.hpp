#ifndef PARSER_FUN_HPP
#define PARSER_FUN_HPP

#include "pch.hpp"
#include "SemanticStruct.hpp"

extern int offset;
extern std::string t; // 暂存类型type
extern int w;         // 暂存宽度width
extern std::unordered_map<std::string, int> type_width_map;

struct Temp
{
    static int tempNum;
    static std::string newTemp();
};

/**
 * @brief 生成中间代码
 * @deprecated 请使用Parser::gen
 */
// void gen(std::string outFile, std::string contant);

/**
 * @brief 获取数组元素类型
 */
std::string get_elem(std::string s_type);

int get_width(std::string s_type);
#endif // PARSER_FUN_HPP
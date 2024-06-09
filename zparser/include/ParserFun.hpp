#ifndef PARSER_FUN_HPP
#define PARSER_FUN_HPP

#include "pch.hpp"

extern int offset;
extern std::string t; // 暂存类型type
extern int w;         // 暂存宽度width

struct Temp
{
    static int tempNum;
    static std::string newTemp();
};

/**
 * @brief 生成中间代码
 * @deprecated 请使用Parser::gen
 */
void gen(std::string outFile, std::string contant);

/**
 * @brief 获取数组元素类型
 */
std::string get_elem(std::string s_type);
#endif // PARSER_FUN_HPP
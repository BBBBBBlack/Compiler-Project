#ifndef PARSER_FUN_HPP
#define PARSER_FUN_HPP

#include "pch.hpp"

extern int offset;
extern std::string t; // 暂存类型type
extern int w;         // 暂存宽度width

/**
 * @brief 生成中间代码
 */
void gen(std::string outFile,std::string contant);

#endif // PARSER_FUN_HPP
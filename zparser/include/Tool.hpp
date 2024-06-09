#ifndef TOOL_HPP
#define TOOL_HPP

#include "pch.hpp"

void removeSpaces(char *str);

// 将|替换为\|
inline std::string escapePipe(std::string &str)
{
    return std::regex_replace(str, std::regex("\\|"), "\\|");
}
// 将\|替换为|
inline std::string unescapePipe(std::string &str)
{
    // \\\|
    return std::regex_replace(str, std::regex("\\\\\\|"), "|");
}

#endif // !TOOL_HPP
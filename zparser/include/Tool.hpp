#ifndef TOOL_HPP
#define TOOL_HPP

#include "pch.hpp"

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

#endif // !TOOL_HPP
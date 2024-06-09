#include "Tool.hpp"

void removeSpaces(char *str)
{
    std::string strValue = str;
    strValue.erase(std::remove_if(strValue.begin(), strValue.end(), ::isspace), strValue.end());
    strcpy(str, strValue.c_str());
}

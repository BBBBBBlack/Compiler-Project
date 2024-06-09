#include <ParserFun.hpp>

std::unordered_map<std::string, int> type_width_map = {
    {"int", 4},
    {"float", 4},
    {"double", 8},
    {"real", 8},
    {"char", 1}};
int Temp::tempNum = 0;
std::string Temp::newTemp()
{
    return "t" + std::to_string(tempNum++);
}
// void gen(std::string outFile, std::string contant)
// {
//     std::ofstream out(outFile, std::ios::app);
//     out << contant << std::endl;
//     out.close();
// }

std::string get_elem(std::string s_type)
{
    std::regex pattern(R"(array\((\d+),\s*(\w+|array\(.*?\))\))");
    std::smatch match;
    if (std::regex_search(s_type, match, pattern))
    {
        int size = std::stoi(match[1].str());
        std::string type = match[2].str();
        s_type = type;
    }
    return s_type;
}

int get_width(std::string s_type)
{
    int res = 1;
    std::regex pattern(R"(array\((\d+),\s*(\w+|array\(.*?\))\))");
    std::smatch match;
    while (std::regex_search(s_type, match, pattern))
    {
        int size = std::stoi(match[1].str());
        std::string type = match[2].str();
        s_type = type;
        res *= size;
    }
    res *= type_width_map[s_type];
    return res;
}
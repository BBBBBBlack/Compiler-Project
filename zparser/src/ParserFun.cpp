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
    // SymbolTable::put_to_symbol_table(newTemp(), t, offset, true);
    return "t" + std::to_string(tempNum++);
}

std::string get_type(const std::string &str)
{
    size_t pos = str.find(',');
    if (pos != std::string::npos)
    {
        return str.substr(pos + 2, str.size() - pos - 3);
    }
    return "";
}

std::string get_elem(std::string s_type)
{
    std::regex pattern(R"(array\((\d+),\s*(\w+|array\(.+?\))\))");
    std::smatch match;
    if (std::regex_search(s_type, match, pattern))
    {
        int size = std::stoi(match[1].str());
        std::string type = get_type(s_type);
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
        std::string type = get_type(s_type);
        s_type = type;
        res *= size;
    }
    res *= type_width_map[s_type];
    return res;
}

std::string widen(std::string addr, std::string type1, std::string type2, Token &leftToken)
{
    if (type1 == "int" && type2 == "float")
    {
        leftToken["type"] = "float";
        std::string temp = Temp::newTemp();
        gen(Quaternion::TYPE_TRANSFER_FLOAT, addr, temp);
        return temp;
    }

    return addr;
}

std::string narrow(std::string addr, std::string type1, std::string type2, Token &leftToken)
{
    if (type1 == "float" && type2 == "int")
    {
        leftToken["type"] = "int";
        std::string temp = Temp::newTemp();
        gen(Quaternion::TYPE_TRANSFER_INT, addr, temp);
        return temp;
    }
    return addr;
}

std::string assign(std::string addr, std::string type1, std::string type2, Token &leftToken)
{
    if (type1 == "int" && type2 == "float")
    {
        return widen(addr, type1, type2, leftToken);
    }
    else if (type1 == "float" && type2 == "int")
    {
        return narrow(addr, type1, type2, leftToken);
    }
    return addr;
}
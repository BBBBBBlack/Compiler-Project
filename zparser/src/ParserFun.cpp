#include <ParserFun.hpp>

int Temp::tempNum = 0;
std::string Temp::newTemp()
{
    return "t" + std::to_string(tempNum++);
}
void gen(std::string outFile, std::string contant)
{
    std::ofstream out(outFile, std::ios::app);
    out << contant << std::endl;
    out.close();
}
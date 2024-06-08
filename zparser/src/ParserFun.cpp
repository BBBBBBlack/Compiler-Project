#include <ParserFun.hpp>
void gen(std::string outFile,std::string contant)
{
    std::ofstream out(outFile);
    out << contant;
    out.close();
}
#ifndef CST_HPP
#define CST_HPP

#include "pch.hpp"
#include "Token.hpp"

struct CSTNode
{
    std::string type;  // 产生式符号
    std::string value; // 综合属性
    std::string inh;   // 继承属性
    int lineno;
    int pos;
    int father;
    std::vector<int> children;

    CSTNode(const Token &token) : type(token.type), value(token.value), lineno(token.lineno), pos(token.pos) {}
};

class CST
{
public:
    CST() {}
    int addNode(const Token &token);
    void addConnection(int father, std::vector<int> child);
    void printCST(std::ostream &os);

private:
    std::vector<CSTNode> nodes;
};

#endif
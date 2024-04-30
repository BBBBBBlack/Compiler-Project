#include "CST.hpp"

int CST::addNode(const Token &token)
{
    nodes.emplace_back(token);
    return nodes.size() - 1;
}

void CST::addConnection(int father, std::vector<int> child)
{
    // 语法树的父子关系不会改变, 直接赋值
    nodes[father].children = child;
}

void CST::printCST(std::ostream &os)
{
    os << "## 语法树\n";
    os << "```mermaid\n";
    os << "\tgraph TD\n";
    for (int i = 1; i < nodes.size(); i++)
    {
        os << "\t" << i << "(" << nodes[i].type << ",val=" << nodes[i].value << ")\n";
    }
    os << "\n";
    for (int i = 1; i < nodes.size(); i++)
    {
        for (int j = 0; j < nodes[i].children.size(); j++)
        {
            os << "\t" << i << " --- " << nodes[i].children[j] << "\n";
        }
    }
    os << "```\n";
    os.flush();
}
#ifndef PARSE_TAB_HPP
#define PARSE_TAB_HPP

#include "ParseTabStruct.hpp"
#include "FAStruct.hpp"

class ParseTab
{
public:
    ParseTab();
    ~ParseTab();
    void setStates(std::vector<State> states)
    {
        this->states = states;
    }
    /**
     * @brief 保存分析表到文件
     * @param filename 文件名
     */
    int saveParseTab(const std::string &filename);
    /**
     * @brief 从文件加载分析表
     * @param filename 文件名
     */
    int loadParseTab(const std::string &filename);

    Action getNextAction(int stateId, Symbol symbol);

    void setTermVec(const std::vector<Symbol> &termVec)
    {
        this->termVec = termVec;
    }
    void setNonTermVec(const std::vector<Symbol> &nonTermVec)
    {
        this->nonTermVec = nonTermVec;
    }

private:
    /**
     * @brief 分析表
     */
    std::vector<State> states;
    std::vector<Symbol> termVec;    // 终结符
    std::vector<Symbol> nonTermVec; // 非终结符
};

#endif // !PARSE_TAB_HPP
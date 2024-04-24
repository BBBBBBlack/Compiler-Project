#ifndef PARSE_TAB_HPP
#define PARSE_TAB_HPP

#include "Struct.hpp"

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

    void setTermVec(const std::vector<std::string> &termVec)
    {
        this->termVec = termVec;
    }
    void setNonTermVec(const std::vector<std::string> &nonTermVec)
    {
        this->nonTermVec = nonTermVec;
    }

private:
    /**
     * @brief 分析表
     */
    std::vector<State> states;
    std::vector<std::string> termVec;    // 终结符类型字符串
    std::vector<std::string> nonTermVec; // 非终结符类型字符串
};

#endif // !PARSE_TAB_HPP
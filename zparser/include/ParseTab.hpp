#ifndef PARSE_TAB_HPP
#define PARSE_TAB_HPP

#include "ParseTabStruct.hpp"
#include "FAStruct.hpp"

#define END_SYMBOL "$"
#define PARSE_TAB_HEADING "## Parse Table"
#define PRODUCTION_HEADING "## Productions"

class ParseTab
{
public:
    ParseTab();
    ~ParseTab();
    void setStates(std::vector<State> states)
    {
        this->states = states;
    }
    int saveToFile(const std::string &filename);
    int loadFromFile(const std::string &filename);

    Action getNextAction(int stateId, Symbol symbol);

    Production getProduction(int productionId)
    {
        return productions[productionId];
    }

    void setTermVec(const std::vector<Symbol> &termVec)
    {
        this->termVec = termVec;
    }
    void setNonTermVec(const std::vector<Symbol> &nonTermVec)
    {
        this->nonTermVec = nonTermVec;
    }
    void setProductions(std::vector<Production> productions)
    {
        this->productions = productions;
    }

private:
    std::vector<State> states;           // 状态
    std::vector<Production> productions; // 产生式
    std::vector<Symbol> termVec;         // 终结符
    std::vector<Symbol> nonTermVec;      // 非终结符

    /**
     * @brief 保存分析表到文件
     * @param filename 文件名
     * @return 0: 保存失败, 1: 保存成功
     * @note 产生式使用生成的.cpp文件来保存
     */
    int saveParseTab(std::ofstream &out);
    /**
     * @brief 从文件加载分析表
     * @param filename 文件名
     * @return 0: 加载失败, 1: 加载成功
     */
    int loadParseTab(std::ifstream &in);
    /**
     * @brief 保存产生式到文件
     * @param filename 文件名
     * @return 0: 保存失败, 1: 保存成功
     */
    int saveProduction(std::ofstream &out);
    /**
     * @brief 检查产生式是否正确
     * @return 0: 产生式错误, 1: 产生式正确
     */
    int checkProduction();
};

#endif // !PARSE_TAB_HPP
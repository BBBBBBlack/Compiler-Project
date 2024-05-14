#include <gtest/gtest.h>
#include "Config.hpp"
#include <ParseTab.hpp>
// #include <ctype.h>
#include "FAStruct.hpp"

// ./build/ZTableGenerator -c test/config.json -f test/test1/FA.md -t test/test1/parseTable.md -p test/test1/parse.cpp
TEST(FATest, test1_generateFA)
{
    std::string configFile = "test/config.json",
                outFileName = "test/test1/parse.cpp";
    Config myconfig(configFile);
    myconfig.analysis(outFileName);
    Rules::genRuleMap();
    // 增广文法
    Rules::addStart();
    Rules::getAllFirst();
    Rules::getFollow();
    // 构造自动机
    FA fa;
    fa.createFA(Rules::rules);
    fa.drawFA("test/test1/out/FA.md");
    std::vector<State> res = fa.createTable();
    Rules::transForAnalysisTable();
    ParseTab parseTab(res);
    parseTab.saveToFile("test/test1/parseTable.md");
}
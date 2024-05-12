#include <gtest/gtest.h>
#include "Config.hpp"
#include <ParseTab.hpp>
#include <stdio.h>
#include <ctype.h>
#include "pch.hpp"
#include "Rule.hpp"
#include "Rules.hpp"
#include "FAStruct.hpp"

TEST(FATest, test1_generateFA)
{
    std::string configFile = "/usr/local/my_projects/c_project/Compiler-Project/zparser/test/config.json", 
    outFileName = "test1/out/parse.cpp";
    Config myconfig(configFile);
    myconfig.analysis(outFileName);
    Rules::genRuleMap();
    // 增廣文法
    Rules::addStart();
    Rules::getAllFirst();
    Rules::getFollow();
    // 构造自动机
    FA fa;
    fa.createFA(Rules::rules);
    fa.drawFA("/usr/local/my_projects/c_project/Compiler-Project/zparser/data/FA.md");
    std::vector<State> res = fa.createTable();
    Rules::transForAnalysisTable();
    ParseTab parseTab(res);
    parseTab.saveToFile("/usr/local/my_projects/c_project/Compiler-Project/zparser/data/data.md");
}
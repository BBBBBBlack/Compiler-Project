#include <gtest/gtest.h>
#include "pch.hpp"
#include "Config.hpp"

TEST(FATest, test1_generateFA)
{
    std::string configFile = "test/config.json", outFileName = "test/test1/out/parse.cpp";
    Config myconfig(configFile);
    myconfig.analysis(outFileName);
    Rules::genRuleMap();
    // TODO 继续写测试
}
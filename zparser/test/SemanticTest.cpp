#include <gtest/gtest.h>
#include "SemanticStruct.hpp"
#include "Parser.hpp"
#include "Tool.hpp"

std::string tableFileName = "out/table.md";
std::string tokenFileName = "token.txt";
std::string processFileName = "out/process.md";
std::string codeTargetFileName = "out/code.txt";
std::string outputFileName = "out/output.txt";

void runZTableGenerator(std::string testDir, std::string testJsonName)
{
    std::system("pwd");
    std::string command = "./build/ZTableGenerator "
                          "-i ./include "
                          "-c " +
                          testDir + testJsonName + " "
                                                   "-f " +
                          testDir + "out/FA.md "
                                    "-t " +
                          testDir + "out/table.md "
                                    "-p " +
                          testDir + "out/parse.cpp";
    std::cout << command << std::endl;
    std::system(command.c_str());
}

void analyze(std::string testDir, ParseTab &tab)
{
    std::string tableFile = testDir + tableFileName;
    std::string tokenFile = testDir + tokenFileName;
    std::string processFile = testDir + processFileName;
    std::string codeTargetFile = testDir + codeTargetFileName;
    std::string outputFile = testDir + outputFileName;

    tab.loadFromFile(tableFile);
    Parser parser(tab);
    parser.setOutputFile(outputFile);
    parser.grammarAnalysis(tokenFile, processFile, codeTargetFile);
}

TEST(SemanticStructTest, 四元组toString测试)
{
    Quaternion q(Quaternion::Operation::ADD, "x", "y", "z"); // x = y + z
    std::string expected = "(+, x, y, z)";
    ASSERT_EQ(q.toString(), expected);
}

void setRules(ParseTab &parseTab)
{
    std::vector<Rule> rules;
    rules.push_back(Rule({"bool", {"true"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"false"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"bool", "||", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"bool", "&&", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"!", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"(", "bool", ")"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    parseTab.setRules(rules);
}

TEST(SemanticStructTest, 不知道叫什么的测试)
{
    runZTableGenerator("test/semantic_test/fun_test/", "config.json");
    ParseTab tab;
    setRules(tab);

    analyze("test/semantic_test/fun_test/", tab);
}
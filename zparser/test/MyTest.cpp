#include <gtest/gtest.h>
#include <iostream>
#include "ParseTab.hpp"

TEST(ParseTabTest, testSave)
{

    ParseTab parseTab;
    parseTab.setTermVec({"x", "y", "$"});
    parseTab.setNonTermVec({"S", "T"});
    std::vector<State> states;
    State state0({{"x", Action(A_Shift, 1)}, {"y", {A_Error}}, {"$", {A_Error}}, {"S", {A_Goto, 5}}, {"T", {A_Error}}});

    // 打印state0
    std::cout << "state: 0" << std::endl;
    for (auto &action : state0.actions)
    {
        std::cout << "<" << action.first << "," << action.second << "> " << std::endl;
    }

    states.push_back(state0);
    states.push_back(State({{"x", {A_Shift, 2}}, {"y", {A_Error}}, {"$", {A_Error}}, {"S", {A_Error}}, {"T", {A_Error}}}));
    states.push_back(State({{"x", {A_Error}}, {"y", {A_Shift, 3}}, {"$", {A_Error}}, {"S", {A_Error}}, {"T", {A_Goto, 4}}}));
    states.push_back(State({{"x", {A_Reduce, 2}}, {"y", {A_Reduce, 2}}, {"$", {A_Reduce, 2}}, {"S", {A_Error}}, {"T", {A_Error}}}));
    states.push_back(State({{"x", {A_Reduce, 1}}, {"y", {A_Reduce, 1}}, {"$", {A_Reduce, 1}}, {"S", {A_Error}}, {"T", {A_Error}}}));
    states.push_back(State({{"x", {A_Error}}, {"y", {A_Error}}, {"$", {A_Accept}}, {"S", {A_Error}}, {"T", {A_Error}}}));

    parseTab.setStates(states);
    parseTab.saveParseTab("test/out/testSave.md");
}

TEST(ParseTabTest, testLoad)
{
    Action action("S3");
    EXPECT_EQ(action.type, A_Shift);
    EXPECT_EQ(action.data, 3);

    ParseTab parseTab;
    parseTab.loadParseTab("test/out/testSave.md");
    parseTab.saveParseTab("test/out/testLoad.md");

    // Compare the contents of two files
    std::ifstream file1("test/out/testSave.md");
    std::ifstream file2("test/out/testLoad.md");

    std::string content1((std::istreambuf_iterator<char>(file1)), std::istreambuf_iterator<char>());
    std::string content2((std::istreambuf_iterator<char>(file2)), std::istreambuf_iterator<char>());

    EXPECT_EQ(content1, content2);
}
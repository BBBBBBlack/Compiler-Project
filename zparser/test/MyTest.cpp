#include <gtest/gtest.h>
#include <iostream>
#include "ParseTab.hpp"

TEST(ParseTabTest, testSaveAndLoad)
{
    ParseTab parseTab;
    parseTab.setTermVec({"x", "y", "$"});
    parseTab.setNonTermVec({"S", "T"});
    std::vector<State> states;
    State state0({{0, Action(A_Shift, 1)}, {1, {A_Error}}, {2, {A_Error}}}, {{0, 5}, {1, -1}});

    states.push_back(state0);
    states.push_back(State({{0, {A_Shift, 2}}, {1, {A_Error}}, {2, {A_Error}}}, {{0, -1}, {1, -1}}));
    states.push_back(State({{0, {A_Error}}, {1, {A_Shift, 3}}, {2, {A_Error}}}, {{0, -1}, {1, 4}}));
    states.push_back(State({{0, {A_Reduce, 2}}, {1, {A_Reduce, 2}}, {2, {A_Reduce, 2}}},
                           {{0, -1}, {1, -1}}));
    states.push_back(State({{0, {A_Reduce, 1}}, {1, {A_Reduce, 1}}, {2, {A_Reduce, 1}}},
                           {{0, -1}, {1, -1}}));
    states.push_back(State({{0, {A_Error}}, {1, {A_Error}}, {2, {A_Accept}}},
                           {{0, -1}, {1, -1}}));

    parseTab.setStates(states);
    parseTab.saveParseTab("test/out/testSaveAndLoad.md");
}

TEST(ParseTabTest, testLoad)
{
    Action action("S3");
    EXPECT_EQ(action.type, A_Shift);
    EXPECT_EQ(action.data, 3);

    ParseTab parseTab;
    parseTab.loadParseTab("test/out/testSaveAndLoad.md");
    parseTab.saveParseTab("test/out/testSaveAndLoad2.md");
}
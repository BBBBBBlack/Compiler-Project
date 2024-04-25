#include <gtest/gtest.h>
#include <iostream>
#include "Parser.hpp"
#include "Token.hpp"

TEST(ParseTabTest, testSave)
{

    ParseTab parseTab;
    parseTab.setTermVec({"x", "y", "$"});
    parseTab.setNonTermVec({"S", "T"});
    std::vector<State> states;
    State state0({{"x", Action(ActionType::A_Shift, 1)}, {"y", {ActionType::A_Error}}, {"$", {ActionType::A_Error}}, {"S", {ActionType::A_Goto, 5}}, {"T", {ActionType::A_Error}}});

    // 打印state0
    std::cout << "state: 0" << std::endl;
    for (auto &action : state0.actions)
    {
        std::cout << "<" << action.first << "," << action.second << "> " << std::endl;
    }

    states.push_back(state0);
    states.push_back(State({{"x", {ActionType::A_Shift, 2}}, {"y", {ActionType::A_Error}}, {"$", {ActionType::A_Error}}, {"S", {ActionType::A_Error}}, {"T", {ActionType::A_Error}}}));
    states.push_back(State({{"x", {ActionType::A_Error}}, {"y", {ActionType::A_Shift, 3}}, {"$", {ActionType::A_Error}}, {"S", {ActionType::A_Error}}, {"T", {ActionType::A_Goto, 4}}}));
    states.push_back(State({{"x", {ActionType::A_Reduce, 2}}, {"y", {ActionType::A_Reduce, 2}}, {"$", {ActionType::A_Reduce, 2}}, {"S", {ActionType::A_Error}}, {"T", {ActionType::A_Error}}}));
    states.push_back(State({{"x", {ActionType::A_Reduce, 1}}, {"y", {ActionType::A_Reduce, 1}}, {"$", {ActionType::A_Reduce, 1}}, {"S", {ActionType::A_Error}}, {"T", {ActionType::A_Error}}}));
    states.push_back(State({{"x", {ActionType::A_Error}}, {"y", {ActionType::A_Error}}, {"$", {ActionType::A_Accept}}, {"S", {ActionType::A_Error}}, {"T", {ActionType::A_Error}}}));

    parseTab.setStates(states);
    parseTab.saveToFile("test/out/testSave.md");
}

TEST(ParseTabTest, testLoad)
{
    Action action("S3");
    EXPECT_EQ(action.type, ActionType::A_Shift);
    EXPECT_EQ(action.data, 3);

    ParseTab parseTab;
    std::vector<Production> productions;
    productions.push_back(Production({"S", {"x", "x", "T"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                                      { return 0; }}));
    productions.push_back(Production({"T", {"y"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                                      { return 0; }}));
    parseTab.setProductions(productions);

    EXPECT_EQ(1, parseTab.loadFromFile("test/out/testSave.md"));
    std::remove("test/out/testLoad.md");
    EXPECT_EQ(1, parseTab.saveToFile("test/out/testLoad.md"));

    // Compare the contents of two files
    std::ifstream file1("test/out/testSave.md");
    std::ifstream file2("test/out/testLoad.md");

    std::string content1((std::istreambuf_iterator<char>(file1)), std::istreambuf_iterator<char>());
    std::string content2((std::istreambuf_iterator<char>(file2)), std::istreambuf_iterator<char>());

    EXPECT_EQ(content1, content2);
}

TEST(ParseTabTest, testTokenRead)
{
    // <NUM, 123.45, 2, 4>
    std::string tokenFile = "test/in/token.txt";
    std::ifstream tokenStream(tokenFile);
    if (!tokenStream.is_open())
    {
        perror("Token File打开失败");
    }

    std::string line;
    while (std::getline(tokenStream, line))
    {
        std::istringstream iss(line);
        Token token;
        iss >> token;
        std::cout << token.type << "," << token.value << "," << token.lineno << "," << token.pos << std::endl;
    }
}

void saveTest1(ParseTab &parseTab, std::string filename)
{
    parseTab.setTermVec({"x", "y", "$"});
    parseTab.setNonTermVec({"S", "T"});
    std::vector<State> states;
    states.push_back(State({{"x", Action(ActionType::A_Shift, 1)}, {"y", {ActionType::A_Error}}, {"$", {ActionType::A_Error}}, {"S", {ActionType::A_Goto, 5}}, {"T", {ActionType::A_Error}}}));
    states.push_back(State({{"x", {ActionType::A_Shift, 2}}, {"y", {ActionType::A_Error}}, {"$", {ActionType::A_Error}}, {"S", {ActionType::A_Error}}, {"T", {ActionType::A_Error}}}));
    states.push_back(State({{"x", {ActionType::A_Error}}, {"y", {ActionType::A_Shift, 3}}, {"$", {ActionType::A_Error}}, {"S", {ActionType::A_Error}}, {"T", {ActionType::A_Goto, 4}}}));
    states.push_back(State({{"x", {ActionType::A_Reduce, 2}}, {"y", {ActionType::A_Reduce, 2}}, {"$", {ActionType::A_Reduce, 2}}, {"S", {ActionType::A_Error}}, {"T", {ActionType::A_Error}}}));
    states.push_back(State({{"x", {ActionType::A_Reduce, 1}}, {"y", {ActionType::A_Reduce, 1}}, {"$", {ActionType::A_Reduce, 1}}, {"S", {ActionType::A_Error}}, {"T", {ActionType::A_Error}}}));
    states.push_back(State({{"x", {ActionType::A_Error}}, {"y", {ActionType::A_Error}}, {"$", {ActionType::A_Accept}}, {"S", {ActionType::A_Error}}, {"T", {ActionType::A_Error}}}));

    parseTab.setStates(states);
    parseTab.saveToFile(filename);
}

void setTest1Production(ParseTab &parseTab)
{
    std::vector<Production> productions;
    productions.push_back(Production({"S", {"x", "x", "T"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                                      { return 0; }}));
    productions.push_back(Production({"T", {"y"}, [&](Token &leftToken, std::vector<Token> &rightTokens) -> int
                                      { return 0; }}));
    parseTab.setProductions(productions);
}

void compareSaveAndLoad(const std::string &file, ParseTab &tab)
{
    std::ifstream f1(file);
    std::string file2 = "test/out/test1.md";
    tab.saveToFile(file2);
    std::ifstream f2(file2);

    std::string content1((std::istreambuf_iterator<char>(f1)), std::istreambuf_iterator<char>());
    std::string content2((std::istreambuf_iterator<char>(f2)), std::istreambuf_iterator<char>());

    EXPECT_EQ(content1, content2);
    std::remove(file2.c_str());
}

TEST(ParseTest, test1)
{
    ParseTab tab1, tab2;
    std::string tabFile = "test/out/test1.md";
    saveTest1(tab1, tabFile);

    setTest1Production(tab2);
    tab2.loadFromFile(tabFile);
    compareSaveAndLoad(tabFile, tab2);

    Parser parser(tab2);
    // parser.setOutputFile("test/out/test1_process.md");
    parser.grammarAnalysis("test/in/token.txt", true, "test/out/test1_process.md");
}
#include <gtest/gtest.h>
#include <iostream>
#include "ZLex.hpp"

TEST(FATest, testConvertSquareBrackets)
{
    NFA nfa;
    std::string test1 = "a[0-9]b", expected1 = "a(0|1|2|3|4|5|6|7|8|9)b";
    ASSERT_EQ(nfa.convertSquareBrackets(test1), expected1);
    std::string test2 = "a[0-9]b[0-9]", expected2 = "a(0|1|2|3|4|5|6|7|8|9)b(0|1|2|3|4|5|6|7|8|9)";
    ASSERT_EQ(nfa.convertSquareBrackets(test2), expected2);
    std::string test3 = "a[a-e]b", expected3 = "a(a|b|c|d|e)b";
    ASSERT_EQ(nfa.convertSquareBrackets(test3), expected3);
    std::string test4 = "a[ac-f]", expected4 = "a(a|c|d|e|f)";
    ASSERT_EQ(nfa.convertSquareBrackets(test4), expected4);
}

TEST(FATest, addUnionTest)
{
    NFA fa;
    std::string test1 = "aab\\+", expected1 = "a_a_b_\\+";
    ASSERT_EQ(fa.addUnion(test1), expected1);
    std::string test2 = "a|b", expected2 = "a|b";
    ASSERT_EQ(fa.addUnion(test2), expected2);

    // 测试括号
    std::string test3 = "(a|b)", expected3 = "(a|b)";
    ASSERT_EQ(fa.addUnion(test3), expected3);

    // 测试符号连接

    std::string test4 = "c(abc|b*)", expected4 = "c_(a_b_c|b*)";
    ASSERT_EQ(fa.addUnion(test4), expected4);
}

TEST(FATest, infixToSufixTest)
{
    NFA fa;
    std::string test1 = "a|b", expected1 = "ab|";
    ASSERT_EQ(fa.infixToSufix(test1), expected1);
    std::string test2 = "ab|c", expected2 = "ab_c|";
    ASSERT_EQ(fa.infixToSufix(fa.addUnion(test2)), expected2);
    std::string test3 = "a\\|b|c", expected3 = "a\\|_b_c|";
    ASSERT_EQ(fa.addUnion(test3), "a_\\|_b|c");
    ASSERT_EQ(fa.infixToSufix(fa.addUnion(test3)), expected3);
}

// 测试将中缀正则表达式转换为后缀形式
TEST(FATest, ConvertToSuffix)
{
    NFA fa;

    // 测试空表达式
    ASSERT_EQ(fa.infixToSufix(""), "");

    // 测试基本情况
    ASSERT_EQ(fa.infixToSufix("a"), "a");
    ASSERT_EQ(fa.infixToSufix("ab"), "ab");
    ASSERT_EQ(fa.infixToSufix("abc"), "abc");

    // 测试带有 | 运算符的情况
    ASSERT_EQ(fa.infixToSufix("a|b"), "ab|");
    ASSERT_EQ(fa.infixToSufix("a|b|c"), "ab|c|");

    // 测试带有 _ 运算符的情况
    ASSERT_EQ(fa.infixToSufix("a_b"), "ab_");
    ASSERT_EQ(fa.infixToSufix("a_b_c"), "ab_c_");

    // 测试带有 * 运算符的情况
    ASSERT_EQ(fa.infixToSufix("a*"), "a*");
    // ASSERT_EQ(fa.infixToSufix("(abc)*"), "abc*");
    ASSERT_EQ(fa.infixToSufix("(a|b)*"), "ab|*");

    // 测试带有 + 运算符的情况
    ASSERT_EQ(fa.infixToSufix("a+"), "a+");
    ASSERT_EQ(fa.infixToSufix("(a|b)+"), "ab|+");

    // 测试带有 ? 运算符的情况
    ASSERT_EQ(fa.infixToSufix("a?"), "a?");
    ASSERT_EQ(fa.infixToSufix("(a|b)?"), "ab|?");

    // (a|b)*abb
    ASSERT_EQ(fa.infixToSufix(fa.addUnion("(a|b)*abb")), "ab|*a_b_b_");
}

/**
 * @deprecated printFA已被重构, 该测试用例已经过时
 */
// TEST(FATest, testSingleRegex)
// {
//     NFA fa1, fa2, fa3, fa4, fa5, fa6;
//     FAStateBlock block = fa1.regexToBlock("a|b", fa1.NFAStates);
//     fa1.printFA("output/test/single/NFA1.md");

//     FAStateBlock block2 = fa2.regexToBlock("ab", fa2.NFAStates);
//     fa2.printFA("output/test/single/NFA2.md");

//     FAStateBlock block3 = fa3.regexToBlock("(ab)*", fa3.NFAStates);
//     fa3.printFA("output/test/single/NFA3.md");

//     FAStateBlock block5 = fa5.regexToBlock("(a|b)*abb", fa5.NFAStates);
//     fa5.printFA("output/test/single/NFA5.md");

//     NFA fa5_1;
//     FAStateBlock block5_1 = fa5_1.regexToBlock("(a|b)*", fa5_1.NFAStates);
//     fa5_1.printFA("output/test/single/NFA5_1.md");

//     // (c(abc|b*))
//     FAStateBlock block6 = fa6.regexToBlock("c(abc|b*)", fa6.NFAStates);
//     fa6.printFA("output/test/single/NFA6.md");
// }

TEST(FATest, testRegexVecToBlock)
{
    NFA nfa1("output/test/complex/FA.md");

    std::vector<PatternAction> regexVec1 = {{"ab", &NullAction}, {"a|b", &NullAction}, {"(ab)*", &NullAction}, {"a(b|c)", &NullAction}};

    nfa1.setDebugMode(true);
    nfa1.buildNFA(regexVec1);
    nfa1.printFA();
    // 这样调用输出有问题, 懒得改了
    // fa1.printFA("output/test/complex/NFA1.md");
    DFA dfa1(nfa1);
    dfa1.printFA();
}

TEST(FATest, homework)
{
    NFA fa1("output/test/homework/FA1.md");
    std::vector<PA> regexVec1 = {{"b+", &NullAction}, {"a*ba", &NullAction}};

    fa1.setDebugMode(true);
    fa1.buildNFA(regexVec1);
    fa1.printFA();

    DFA dfa1(fa1);
    dfa1.printFA();

    NFA fa2("output/test/homework/FA2.md");
    std::vector<PA> regexVec2 = {{"a*b*", &NullAction}};
    fa2.setDebugMode(true);
    fa2.buildNFA(regexVec2);
    fa2.printFA();
    DFA dfa2(fa2);
    dfa2.printFA();
}

TEST(ZLexTest, testBuildDFA)
{
    ZLex zlex;
    PAVec paVec = {{"a|b", &NullAction}, {"ab", &NullAction}, {"(ab)*", &NullAction}, {"a(b|c)", &NullAction}};
    zlex.buildDFA(true, paVec, "output/test/ZLex/FA.md");

    ZLex zlex2;
    PAVec paVec2 = {{"a[b-z]", &NullAction}, {"a*ba", &NullAction}};
    zlex2.buildDFA(true, paVec2, "output/test/ZLex/FA2.md");

    ZLex zlex3;
    PAVec paVec3 = {{"abc", &NullAction}, {"a[f-h]c", &NullAction}};
    zlex3.buildDFA(true, paVec3, "output/test/ZLex/FA3.md");
}

TEST(ZLexTest, testLexicalAnalysis)
{
    std::ofstream out("output/test/ZLex/lexicalAnalysis.md", std::ios::trunc);

    ZLex zlex;
    PAVec paVec = {
        {"[0-9]", [&]() -> int
         {
             out << "?";
             return 0;
         },
         "note1"},
        // =用于捕获yytext
        {"[a-z]", [&]() -> int
         {
             out << yytext;
             return 0;
         },
         "note2"}};
    // 测试action
    paVec[0].action();
    paVec[1].action();

    zlex.buildDFA(true, paVec, "output/test/ZLex/FA3.md");
    // 检查dfa中的action是否正确
    for (auto &state : zlex.dfa->states)
    {
        if (state.action)
        {
            state.action();
        }
    }
    zlex.lexicalAnalysis(out, "resource/test/hello.cpp");
}
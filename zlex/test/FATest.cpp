#include <gtest/gtest.h>
#include <iostream>

#include "NFA.hpp"
#include "NFA.hpp"
#include "DFA.hpp"

TEST(FATest, addUnionTest)
{
    NFA fa;
    std::string test1 = "aab\\+", expected1 = "a-a-b-\\+";
    ASSERT_EQ(fa.addUnion(test1), expected1);
    std::string test2 = "a|b", expected2 = "a|b";
    ASSERT_EQ(fa.addUnion(test2), expected2);

    // 测试括号
    std::string test3 = "(a|b)", expected3 = "(a|b)";
    ASSERT_EQ(fa.addUnion(test3), expected3);

    // 测试符号连接

    std::string test4 = "c(abc|b*)", expected4 = "c-(a-b-c|b*)";
    ASSERT_EQ(fa.addUnion(test4), expected4);
}

TEST(FATest, infixToSufixTest)
{
    NFA fa;
    std::string test1 = "a|b", expected1 = "ab|";
    ASSERT_EQ(fa.infixToSufix(test1), expected1);
    std::string test2 = "ab|c", expected2 = "ab-c|";
    ASSERT_EQ(fa.infixToSufix(fa.addUnion(test2)), expected2);
    std::string test3 = "a\\|b|c", expected3 = "a\\|-b-c|";
    ASSERT_EQ(fa.addUnion(test3), "a-\\|-b|c");
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

    // 测试带有 - 运算符的情况
    ASSERT_EQ(fa.infixToSufix("a-b"), "ab-");
    ASSERT_EQ(fa.infixToSufix("a-b-c"), "ab-c-");

    // 测试带有 * 运算符的情况
    ASSERT_EQ(fa.infixToSufix("a*"), "a*");
    ASSERT_EQ(fa.infixToSufix("(a|b)*"), "ab|*");

    // 测试带有 + 运算符的情况
    ASSERT_EQ(fa.infixToSufix("a+"), "a+");
    ASSERT_EQ(fa.infixToSufix("(a|b)+"), "ab|+");

    // 测试带有 ? 运算符的情况
    ASSERT_EQ(fa.infixToSufix("a?"), "a?");
    ASSERT_EQ(fa.infixToSufix("(a|b)?"), "ab|?");

    // (a|b)*abb
    ASSERT_EQ(fa.infixToSufix(fa.addUnion("(a|b)*abb")), "ab|*a-b-b-");
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

    std::vector<PatternAction> regexVec1 = {{"ab", NullAction}, {"a|b", NullAction}, {"(ab)*", NullAction}, {"a(b|c)", NullAction}};

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
    std::vector<PA> regexVec1 = {{"b+", NullAction}, {"a*ba", NullAction}};

    fa1.setDebugMode(true);
    fa1.buildNFA(regexVec1);
    fa1.printFA();

    DFA dfa1(fa1);
    dfa1.printFA();

    NFA fa2("output/test/homework/FA2.md");
    std::vector<PA> regexVec2 = {{"a*b*", NullAction}};
    fa2.setDebugMode(true);
    fa2.buildNFA(regexVec2);
    fa2.printFA();
    DFA dfa2(fa2);
    dfa2.printFA();
}
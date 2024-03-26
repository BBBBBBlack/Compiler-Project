#include <gtest/gtest.h>
#include <iostream>

// 用于测试私有成员函数
#define private public
#include "FA.hpp"
#undef private

TEST(FATest, addUnionTest)
{
    FA fa;
    std::string test1 = "aab\\+", expected1 = "a-a-b-\\+";
    ASSERT_EQ(fa.addUnion(test1), expected1);
    std::string test2 = "a|b", expected2 = "a|b";
    ASSERT_EQ(fa.addUnion(test2), expected2);

    // 测试括号
    std::string test3 = "(a|b)", expected3 = "(a|b)";
    ASSERT_EQ(fa.addUnion(test3), expected3);

    // 测试符号连接
}

TEST(FATest, infixToSufixTest)
{
    FA fa;
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
    FA fa;

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

TEST(FATest, testPrintFA)
{
    FA fa1, fa2, fa3, fa4, fa5, fa6;
    FAStateBlock block = fa1.regexToBlock("a|b");
    fa1.printFA(block, "build/test/FA1.md");

    FAStateBlock block2 = fa2.regexToBlock("ab");
    fa2.printFA(block2, "build/test/FA2.md");

    FAStateBlock block3 = fa3.regexToBlock("(ab)*");
    fa3.printFA(block3, "build/test/FA3.md");

    FAStateBlock block5 = fa5.regexToBlock("(a|b)*abb");
    fa5.printFA(block5, "build/test/FA5.md");

    FA fa5_1;
    FAStateBlock block5_1 = fa5_1.regexToBlock("(a|b)*");
    fa5_1.printFA(block5_1, "build/test/FA5_1.md");

    // (c(abc|b*))
    FAStateBlock block6 = fa6.regexToBlock("c(abc|b*)");
    fa6.printFA(block6, "build/test/FA6.md");
}
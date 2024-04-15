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
    std::string test5 = "a[a-c-f]", expected5 = "a(a|b|c|d|e|f)";
    ASSERT_EQ(nfa.convertSquareBrackets(test5), expected5);
    std::string test6 = "a[a-c0-3]b", expected6 = "a(a|b|c|0|1|2|3)b";
    ASSERT_EQ(nfa.convertSquareBrackets(test6), expected6);
    std::string test7 = "a[a-zA-Z]", expected7 = "a(a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z)";
    ASSERT_EQ(nfa.convertSquareBrackets(test7), expected7);

    // 转义字符
    std::string test8 = "a[\\-\\]]", expected8 = "a(\\-|\\])";
    ASSERT_EQ(nfa.convertSquareBrackets(test8), expected8);

    // 空格到~
    std::string test9 = "a[ -~]", expected9 = "a( |!|\"|#|$|%|&|'|\\(|\\)|\\*|\\+|,|-|.|/|0|1|2|3|4|5|6|7|8|9|:|;|<|=|>|\\?|@|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z|\\[|\\\\|\\]|^|\\_|`|a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|{|\\||}|~)";
    ASSERT_EQ(nfa.convertSquareBrackets(test9), expected9);
}

TEST(FATest, addUnionTest_escape)
{
    NFA fa;
    // 奇怪的测试
    std::string test4 = "[\\!\\?\\ \\.]", test4_1 = fa.convertSquareBrackets(test4), test4_2 = fa.addUnion(test4_1);
    ASSERT_TRUE(test4[1] == '\\');
    ASSERT_EQ(test4_1, "(\\!|\\?|\\ |\\.)");
    ASSERT_EQ(test4_2, "(\\!|\\?|\\ |\\.)");
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
    std::string test5 = "c(abc|b*)", expected5 = "c_(a_b_c|b*)";
    ASSERT_EQ(fa.addUnion(test5), expected5);
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

    // // 测试转义字符
    // ASSERT_EQ(fa.infixToSufix("a\\|b"), "a\\|b");
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

TEST(FATest, testBuildDFA)
{
    ZLex zlex1;
    PAVec paVec = {{"[0-2]+", &NullAction}};
    zlex1.buildDFA(true, paVec, "output/test/buildDFA/FA1.md");
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

    ZLex zlex4;
    PAVec paVec4 = {{"[0-1]+", &NullAction}, {"[a-c]*", &NullAction}};
    zlex4.buildDFA(true, paVec4, "output/test/ZLex/FA4.md");
}

TEST(ZLexTest, testLexicalAnalysis_simple)
{
    std::string fileName = "output/test/ZLex/all/lexicalAnalysis1.md";
    std::string folderPath = fileName.substr(0, fileName.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    std::ofstream out(fileName, std::ios::trunc);

    ZLex zlex;
    std::string &yytext_ref = yytext;
    PAVec paVec1 = {
        // TODO 添加"+"后无法识别, 可能是正则构造有误wd
        // 子集构造算法出错
        {"[0-2]+", [&]() -> int
         {
             out << "$" << yytext << "$";
             out.flush();
             return 0;
         },
         "note1"},
        // &用于捕获yytext和out
        {"[a-c]+", [&]() -> int
         {
             out << yytext << " ";
             out.flush();
             return 0;
         },
         "note2"}};
    // 测试action
    // paVec[0].action();
    // paVec[1].action();

    zlex.buildDFA(true, paVec1, "output/test/ZLex/all/FA1.md");
    // 检查dfa中的action是否正确
    for (auto &state : zlex.dfa->states)
    {
        if (state.action)
        {
            state.action();
        }
    }
    zlex.lexicalAnalysis(out, "resource/test/test_simple.txt");
}

TEST(ZLexTest, testLexicalAnalysis)
{
    std::string fileName = "output/test/ZLex/all/lexicalAnalysis2.md";
    std::string folderPath = fileName.substr(0, fileName.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    std::ofstream out(fileName, std::ios::trunc);

    ZLex zlex;
    std::string &yytext_ref = yytext;
    PAVec paVec1 = {
        // TODO 添加"+"后无法识别, 可能是正则构造有误wd
        // 子集构造算法出错
        {"[0-9]+", [&]() -> int
         {
             out << "$" << yytext << "$";
             out.flush();
             return 0;
         },
         "number"},
        // &用于捕获yytext和out
        {"[a-zA-Z]+", [&]() -> int
         {
             out << yytext << " ";
             out.flush();
             return 0;
         },
         "string"},
        {"[\\!\\?\\ \\.]", [&]() -> int
         {
             out << "`" << yytext << "`";
             out.flush();
             return 0;
         },
         "spcial char"},
        {"\\\n", [&]() -> int
         {
             out << std::endl;
             out.flush();
             return 0;
         },
         "newline"}};
    // 测试action
    // paVec[0].action();
    // paVec[1].action();

    zlex.buildDFA(true, paVec1, "output/test/ZLex/all/FA2.md");
    // 检查dfa中的action是否正确
    out << "## action check" << std::endl;
    for (auto &state : zlex.dfa->states)
    {
        if (state.action)
        {
            state.action();
        }
    }
    out << std::endl
        << "## lexical analysis" << std::endl;
    zlex.lexicalAnalysis(out, "resource/test/test.txt");
}

TEST(ZLexTest, testLexicalAnalysis_escape)
{
    std::string fileName = "output/test/ZLex/all/lexicalAnalysis3.md";
    std::string folderPath = fileName.substr(0, fileName.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    std::ofstream out(fileName, std::ios::trunc);

    ZLex zlex;
    std::string &yytext_ref = yytext;
    PAVec paVec1 = {
        {"[\\!\\?\\ \\.]", [&]() -> int
         {
             out << "`" << yytext << "`,";
             out.flush();
             return 0;
         },
         "spcial char"}};
    // 测试action
    // paVec[0].action();
    // paVec[1].action();

    zlex.buildDFA(true, paVec1, "output/test/ZLex/all/FA3.md");
    // 检查dfa中的action是否正确
    out << "## action check" << std::endl;
    for (auto &state : zlex.dfa->states)
    {
        if (state.action)
        {
            state.action();
        }
    }
    out << std::endl
        << "## lexical analysis" << std::endl;
    zlex.lexicalAnalysis(out, "resource/test/test_escape.txt");
}

std::ofstream createOutFile(std::string fileName)
{
    std::string folderPath = fileName.substr(0, fileName.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    std::ofstream out(fileName, std::ios::trunc);
    return out;
}

TEST(ZLexTest, test2)
{
    std::string fileName = "output/test/ZLex/all/lexicalAnalysis3.md";
    std::ofstream tokenFile = createOutFile(fileName);

    PAVec paVec = {
        {"[0-9]+.[0-9]+", [&]() -> int
         {
             Token token(yytext, tokenFile, true);
             token.print_token();
             return 0;
         },
         "digit"},
        {"int", [&]() -> int
         {
             Token token(yytext, tokenFile, true);
             token.print_token();
             return 0;
         },
         "int"},
        {"float", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "float"},
        {"double", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "double"},
        {"long", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "long"},
        {"if", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "if"},
        {"else", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "else"},
        {"while", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "while"},
        {"for", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "for"},
        {"do", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "do"},
        {"break", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "break"},
        {"continue", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "continue"},
        {"return", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "return"},
        {"void", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "void"},
        {"main", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "main"},
        {"{", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "{"},
        {"}", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "}"},
        {"\\(", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "\\("},
        {"\\)", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "\\)"},
        {"\\[", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "["},
        {"\\]", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "]"},
        {";", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         ";"},
        {",", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         ","},
        {"=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "="},
        {"<", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "<"},
        {"<=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "<="},
        {">", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         ">"},
        {">=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         ">="},
        {"==", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "=="},
        {"\\!=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "!="},
        {"\\+", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "\\+"},
        {"-", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "-"},
        {"\\*", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "\\*"},
        {"/", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "/"},
        {"%", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "%"},
        {"\\+\\+", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "++"},
        {"--", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "--"},
        {"\\+=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "+="},
        {"-=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "-="},
        {"\\*=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "*="},
        {"/=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "/="},
        {"%=", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "%="},
        {"&&", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "&&"},
        {"\\|\\|", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "||"},
        {"[a-zA-Z\\_]+[a-zA-Z0-9\\_]*", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "identifier"},
        {"[\\ \\\n]+", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "space&newline"}};

    ZLex zlex;
    zlex.buildDFA(true, paVec, "output/test/ZLex/all/FA4.md");
    zlex.lexicalAnalysis(tokenFile, "resource/test/test2.txt");
}

TEST(ZLexTest, testAnnotation)
{
    std::string fileName = "output/test/ZLex/all/lexicalAnalysis5.md";
    std::ofstream tokenFile = createOutFile(fileName);

    PAVec paVec = {
        {"//[ -~]*", [&]() -> int
         {
             Token token(yytext, tokenFile, false);
             token.print_token();
             return 0;
         },
         "spcial char"}};

    ZLex zlex;
    zlex.buildDFA(true, paVec, "output/test/ZLex/all/FA5.md");
    zlex.lexicalAnalysis(tokenFile, "resource/test/test2.txt");
}
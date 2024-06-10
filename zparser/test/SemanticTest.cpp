#include <gtest/gtest.h>
#include "SemanticStruct.hpp"
#include "Parser.hpp"

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

void analyze(std::string testDir, ParseTab &tab, Parser &parser, std::string tokenFileName = "token.txt")
{
    std::string tableFile = testDir + tableFileName;
    std::string tokenFile = testDir + tokenFileName;
    std::string processFile = testDir + processFileName;
    std::string codeTargetFile = testDir + codeTargetFileName;
    std::string outputFile = testDir + outputFileName;

    tab.loadFromFile(tableFile);
    parser.setParseTab(tab); // 现在不是引用传递了
    parser.setOutputFile(outputFile);
    parser.grammarAnalysis(tokenFile, processFile, codeTargetFile);
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

void printInstr(Parser &parser)
{
    std::cout << "===============" << std::endl;
    int cnt = 0;
    for (auto &instr : parser.instrVec)
    {
        std::cout << "[" << cnt++ << "]" << instr.toString() << std::endl;
    }
    std::cout << "===============" << std::endl;
}

TEST(SemanticStructTest, 回填测试)
{
    ParseTab tab;
    // setRules(tab);
    Parser parse(tab);

    // auto &gen = parse.gen;
    // auto &backPatch = parse.backPatch;
    // B1 -> true, B2 -> true
    Token B1("bool", "true"), B2("bool", "true");
    B1["truelist"] = parse.makeList(parse.nextinstr);
    std::cout << B1["truelist"] << std::endl;
    parse.gen(Quaternion::Operation::GOTO, "_");

    printInstr(parse);

    int M_instr = parse.nextinstr;
    B2["truelist"] = parse.makeList(parse.nextinstr);
    parse.gen(Quaternion::Operation::GOTO, "_");
    printInstr(parse);

    // B ->B1 && B2
    Token B("bool", "?");
    parse.backPatch(B1["truelist"], M_instr);
    B["truelist"] = B2["truelist"];
    B["falselist"] = parse.mergeList(B1["falselist"], B2["falselist"]);
    // 模拟B ->B1 && B2归约结束, truelist尚未回填

    // if (B) S(z=x+y)
    Token S1("stmt", "z=x+y"), S("stmt", "?");
    M_instr = parse.nextinstr;
    parse.gen(Quaternion::Quaternion::ADD, "x", "y", "z");
    parse.backPatch(B["truelist"], M_instr);
    S["nextlist"] = parse.mergeList(B["falselist"], S1["nextlist"]);

    printInstr(parse);
    // parse.backPatch(B["falselist"], parse.nextinstr);
    // printInstr(parse);
}

void setRules1(ParseTab &parseTab)
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
    rules.push_back(Rule({"bool", {"bool", "||", "M", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"bool", "&&", "M", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
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
    rules.push_back(Rule({"M", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    parseTab.setRules(rules);
}

TEST(SemanticStructTest, bool表达式action测试)
{
    runZTableGenerator("test/semantic_test/fun_test/", "config.json");
    ParseTab tab;
    setRules1(tab);

    analyze("test/semantic_test/fun_test/", tab);
}

#include "ExposeFun.hpp"
void setRules2(ParseTab &parseTab)
{
    std::vector<Rule> rules;
    rules.push_back(Rule({"bool", {"true"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["truelist"] = makeList(nextinstr);
                              gen(Quaternion::Operation::GOTO, "_");
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"false"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["falselist"] = makeList(nextinstr);
                              gen(Quaternion::Operation::GOTO, "_");
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"bool", "||", "M", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              backPatch(leftToken["falselist"], nextinstr);
                              leftToken["truelist"] = mergeList(rightTokens[0]["truelist"], rightTokens[3]["truelist"]);
                              leftToken["falselist"] = rightTokens[3]["falselist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"bool", "&&", "M", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              backPatch(leftToken["truelist"], nextinstr);
                              leftToken["truelist"] = rightTokens[3]["truelist"];
                              leftToken["falselist"] = mergeList(rightTokens[0]["falselist"], rightTokens[3]["falselist"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"!", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["truelist"] = rightTokens[1]["falselist"];
                              leftToken["falselist"] = rightTokens[1]["truelist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"(", "bool", ")"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["truelist"] = rightTokens[1]["truelist"];
                              leftToken["falselist"] = rightTokens[1]["falselist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"M", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["instr"] = nextinstr;
                              return 0;
                          }}));
    parseTab.setRules(rules);
}

TEST(SemanticStructTest, ExposeFun测试)
{
    runZTableGenerator("test/semantic_test/fun_test/", "config.json");
    setRules2(tab); // 用ExposeFun.hpp中的tab

    analyze("test/semantic_test/fun_test/", tab, parser); // 用ExposeFun.hpp中的parser
    printInstr(parser);
}

void setRules_if(ParseTab &parseTab);
TEST(SemanticStructTest, if测试)
{
    // runZTableGenerator("test/semantic_test/if_test/", "test.json");
    setRules_if(tab); // 用ExposeFun.hpp中的tab

    analyze("test/semantic_test/if_test/", tab, parser, "in/token1.txt"); // 用ExposeFun.hpp中的parser
    printInstr(parser);
}

void setRules_complete(ParseTab &parseTab);

TEST(SemanticStructTest, 完整测试_if)
{
    // runZTableGenerator("test/semantic_test/complete_test/", "test.json");
    setRules_complete(tab); // 用ExposeFun.hpp中的tab

    analyze("test/semantic_test/complete_test/", tab, parser, "in/token1.txt"); // 用ExposeFun.hpp中的parser
    printInstr(parser);
}

TEST(SemanticStructTest, 完整测试_while)
{
    // runZTableGenerator("test/semantic_test/complete_test/", "test.json");
    setRules_complete(tab); // 用ExposeFun.hpp中的tab

    analyze("test/semantic_test/complete_test/", tab, parser, "in/token2.txt"); // 用ExposeFun.hpp中的parser
    printInstr(parser);
}

void setRules_if(ParseTab &parseTab)
{
    std::vector<Rule> rules;
    rules.push_back(Rule({"program", {"A", "basic", "id", "(", ")", "block"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"A", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              offset = 0;
                              return 0;
                          }}));
    rules.push_back(Rule({"block", {"{", "decls", "stmts", "}"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // decls:1, stmts:2
                              backPatch(rightTokens[2]["nextlist"], nextinstr);
                              return 0;
                          }}));
    rules.push_back(Rule({"decls", {"decl", "decls"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"decls", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"decl", {"type", "id", ";"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              std::string lexeme = rightTokens[1]["lexeme"];
                              std::string type = rightTokens[0]["type"];
                              SymbolTable::put_to_symbol_table(lexeme, type, offset);
                              offset += std::stoi(rightTokens[0]["width"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"type", {"basic", "B", "array"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = rightTokens[2]["type"];
                              leftToken["width"] = rightTokens[2]["width"];
                              return 0;
                          }}));
    rules.push_back(Rule({"B", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              t = SymbolTable::get_token_stack(tokenStack, 1)["type"];
                              w = std::stoi(SymbolTable::get_token_stack(tokenStack, 1)["width"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"array", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = t;
                              leftToken["width"] = std::to_string(w);
                              return 0;
                          }}));
    rules.push_back(Rule({"array", {"[", "num", "]", "array"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = "array(" + rightTokens[1]["val"] + ", " + rightTokens[3]["type"] + ")";
                              leftToken["width"] = std::to_string(std::stoi(rightTokens[1]["val"]) * std::stoi(rightTokens[3]["width"]));
                              return 0;
                          }}));
    rules.push_back(Rule({"basic", {"float"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = "float";
                              leftToken["width"] = "4";
                              return 0;
                          }}));
    rules.push_back(Rule({"basic", {"int"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = "int";
                              leftToken["width"] = "4";
                              return 0;
                          }}));
    rules.push_back(Rule({"basic", {"real"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = "real";
                              leftToken["width"] = "8";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmts", {"stmt", "M", "stmts"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // stmt:0, M:1, stmts:2
                              backPatch(rightTokens[0]["nextlist"], rightTokens[1]["instr"]);
                              leftToken["nextlist"] = rightTokens[2]["nextlist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"stmts", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"id", "=", "expr", ";"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              SymbolTable::get_from_symbol_table(rightTokens[0]["lexeme"], rightTokens[0]);
                              gen(Quaternion::ASSIGN, rightTokens[2]["addr"], rightTokens[0]["lexeme"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"loc", "=", "expr", ";"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              SymbolTable::get_from_symbol_table(rightTokens[0]["lexeme"], rightTokens[0]);
                              gen(Quaternion::ARRAY_ASSIGN_YI, rightTokens[0]["addr"], rightTokens[2]["addr"], rightTokens[0]["lexeme"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"if", "(", "bool", ")", "M", "stmt"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // bool:2, M:4, stmt:5
                              backPatch(rightTokens[2]["truelist"], rightTokens[4]["instr"]);
                              leftToken["nextlist"] = mergeList(rightTokens[2]["falselist"], rightTokens[5]["nextlist"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"if", "(", "bool", ")", "M", "stmt", "N", "else", "M", "stmt"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // bool:2, M1:4, stmt1:5, N:6, M2:8, stmt2:9
                              backPatch(rightTokens[2]["truelist"], rightTokens[4]["instr"]);
                              backPatch(rightTokens[2]["falselist"], rightTokens[8]["instr"]);
                              temp = mergeList(rightTokens[5]["nextlist"], rightTokens[6]["nextlist"]);
                              leftToken["nextlist"] = mergeList(temp, rightTokens[9]["nextlist"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"while", "M", "(", "bool", ")", "M", "stmt"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // M1:1, bool:3, M2:5, stmt:6
                              backPatch(rightTokens[6]["truelist"], rightTokens[1]["instr"]);
                              backPatch(rightTokens[3]["truelist"], rightTokens[5]["instr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"do", "M", "stmt", "while", "(", "bool", ")", ";"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // M:2, stmt:3, bool:6
                              backPatch(rightTokens[6]["truelist"], rightTokens[2]["instr"]);
                              leftToken["nextlist"] = rightTokens[6]["falselist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"break", ";"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["nextlist"] = makeList(nextinstr);
                              gen(Quaternion::Operation::GOTO, "_");
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"true"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["truelist"] = makeList(nextinstr);
                              gen(Quaternion::Operation::GOTO, "_");
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"false"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["falselist"] = makeList(nextinstr);
                              gen(Quaternion::Operation::GOTO, "_");
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"bool", "||", "M", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              backPatch(leftToken["falselist"], nextinstr);
                              leftToken["truelist"] = mergeList(rightTokens[0]["truelist"], rightTokens[3]["truelist"]);
                              leftToken["falselist"] = rightTokens[3]["falselist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"bool", "&&", "M", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              backPatch(leftToken["truelist"], nextinstr);
                              leftToken["truelist"] = rightTokens[3]["truelist"];
                              leftToken["falselist"] = mergeList(rightTokens[0]["falselist"], rightTokens[3]["falselist"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"!", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["truelist"] = rightTokens[1]["falselist"];
                              leftToken["falselist"] = rightTokens[1]["truelist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"(", "bool", ")"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["truelist"] = rightTokens[1]["truelist"];
                              leftToken["falselist"] = rightTokens[1]["falselist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"M", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["instr"] = std::to_string(nextinstr);
                              return 0;
                          }}));
    rules.push_back(Rule({"N", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["nextlist"] = makeList(nextinstr);
                              gen(Quaternion::Operation::GOTO, "_");
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"expr", "+", "expr"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::ADD, rightTokens[0]["addr"], rightTokens[2]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"expr", "-", "expr"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::SUB, rightTokens[0]["addr"], rightTokens[2]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"expr", "*", "expr"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::MUL, rightTokens[0]["addr"], rightTokens[2]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"expr", "/", "expr"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::DIV, rightTokens[0]["addr"], rightTokens[2]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"-", "expr"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::SUB, "0", rightTokens[1]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"(", "expr", ")"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = rightTokens[1]["addr"];
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"loc"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::ARRAY_ASSIGN_YI, rightTokens[0]["lexeme"], rightTokens[0]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"id"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              SymbolTable::get_from_symbol_table(rightTokens[0]["lexeme"], rightTokens[0]);
                              leftToken["addr"] = rightTokens[0]["lexeme"];
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"num"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = rightTokens[0]["val"];
                              return 0;
                          }}));
    rules.push_back(Rule({"loc", {"loc", "[", "expr", "]"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["lexeme"] = rightTokens[0]["lexeme"];
                              leftToken["type"] = get_elem(rightTokens[0]["type"]);
                              std::string temo = Temp::newTemp();
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::MUL, rightTokens[2]["addr"], std::to_string(get_width(leftToken["type"])), temo);
                              gen(Quaternion::ADD, rightTokens[0]["addr"], temo, leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"loc", {"id", "[", "expr", "]"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              SymbolTable::get_from_symbol_table(rightTokens[0]["lexeme"], rightTokens[0]);
                              leftToken["lexeme"] = rightTokens[0]["lexeme"];
                              leftToken["type"] = get_elem(rightTokens[0]["type"]);
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::MUL, rightTokens[2]["addr"], std::to_string(get_width(leftToken["type"])), leftToken["addr"]);
                              return 0;
                          }}));
    parseTab.setRules(rules);
}

void setRules_complete(ParseTab &parseTab)
{
    std::vector<Rule> rules;
    rules.push_back(Rule({"program", {"A", "basic", "id", "(", ")", "block"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"A", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              offset = 0;
                              return 0;
                          }}));
    rules.push_back(Rule({"block", {"{", "decls", "stmts", "}"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // decls:1, stmts:2
                              backPatch(rightTokens[2]["nextlist"], nextinstr);
                              return 0;
                          }}));
    rules.push_back(Rule({"decls", {"decl", "decls"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"decls", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"decl", {"type", "id", ";"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              std::string lexeme = rightTokens[1]["lexeme"];
                              std::string type = rightTokens[0]["type"];
                              SymbolTable::put_to_symbol_table(lexeme, type, offset);
                              offset += std::stoi(rightTokens[0]["width"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"type", {"basic", "B", "array"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = rightTokens[2]["type"];
                              leftToken["width"] = rightTokens[2]["width"];
                              return 0;
                          }}));
    rules.push_back(Rule({"B", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              t = SymbolTable::get_token_stack(tokenStack, 1)["type"];
                              w = std::stoi(SymbolTable::get_token_stack(tokenStack, 1)["width"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"array", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = t;
                              leftToken["width"] = std::to_string(w);
                              return 0;
                          }}));
    rules.push_back(Rule({"array", {"[", "num", "]", "array"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = "array(" + rightTokens[1]["val"] + ", " + rightTokens[3]["type"] + ")";
                              leftToken["width"] = std::to_string(std::stoi(rightTokens[1]["val"]) * std::stoi(rightTokens[3]["width"]));
                              return 0;
                          }}));
    rules.push_back(Rule({"basic", {"float"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = "float";
                              leftToken["width"] = "4";
                              return 0;
                          }}));
    rules.push_back(Rule({"basic", {"int"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = "int";
                              leftToken["width"] = "4";
                              return 0;
                          }}));
    rules.push_back(Rule({"basic", {"real"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["type"] = "real";
                              leftToken["width"] = "8";
                              return 0;
                          }}));
    rules.push_back(Rule({"stmts", {"stmt", "M", "stmts"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // stmt:0, M:1, stmts:2
                              backPatch(rightTokens[0]["nextlist"], rightTokens[1]["instr"]);
                              leftToken["nextlist"] = rightTokens[2]["nextlist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"stmts", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"id", "=", "expr", ";"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              SymbolTable::get_from_symbol_table(rightTokens[0]["lexeme"], rightTokens[0]);
                              gen(Quaternion::ASSIGN, rightTokens[2]["addr"], rightTokens[0]["lexeme"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"loc", "=", "expr", ";"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              SymbolTable::get_from_symbol_table(rightTokens[0]["lexeme"], rightTokens[0]);
                              gen(Quaternion::ARRAY_ASSIGN_YI, rightTokens[0]["addr"], rightTokens[2]["addr"], rightTokens[0]["lexeme"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"if", "(", "bool", ")", "M", "stmt"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // bool:2, M:4, stmt:5
                              backPatch(rightTokens[2]["truelist"], rightTokens[4]["instr"]);
                              leftToken["nextlist"] = mergeList(rightTokens[2]["falselist"], rightTokens[5]["nextlist"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"if", "(", "bool", ")", "M", "stmt", "N", "else", "M", "stmt"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // bool:2, M1:4, stmt1:5, N:6, M2:8, stmt2:9
                              backPatch(rightTokens[2]["truelist"], rightTokens[4]["instr"]);
                              backPatch(rightTokens[2]["falselist"], rightTokens[8]["instr"]);
                              temp = mergeList(rightTokens[5]["nextlist"], rightTokens[6]["nextlist"]);
                              leftToken["nextlist"] = mergeList(temp, rightTokens[9]["nextlist"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"while", "M", "(", "bool", ")", "M", "stmt"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // M1:1, bool:3, M2:5, stmt:6
                              backPatch(rightTokens[6]["truelist"], rightTokens[1]["instr"]);
                              backPatch(rightTokens[3]["truelist"], rightTokens[5]["instr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"do", "M", "stmt", "while", "(", "bool", ")", ";"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // M:2, stmt:3, bool:6
                              backPatch(rightTokens[6]["truelist"], rightTokens[2]["instr"]);
                              leftToken["nextlist"] = rightTokens[6]["falselist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"break", ";"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["nextlist"] = makeList(nextinstr);
                              gen(Quaternion::Operation::GOTO, "_");
                              return 0;
                          }}));
    rules.push_back(Rule({"stmt", {"block"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"expr", "rel", "expr"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              // expr:0, rel:1, expr:2
                              leftToken["truelist"] = makeList(nextinstr);
                              leftToken["falselist"] = makeList(nextinstr + 1);
                              gen(Quaternion::toOp(rightTokens[1]["op"]), rightTokens[0]["addr"], rightTokens[2]["addr"], "_");
                              gen(Quaternion::Operation::GOTO, "_");
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"true"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["truelist"] = makeList(nextinstr);
                              gen(Quaternion::Operation::GOTO, "_");
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"false"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["falselist"] = makeList(nextinstr);
                              gen(Quaternion::Operation::GOTO, "_");
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"bool", "||", "M", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              backPatch(leftToken["falselist"], nextinstr);
                              leftToken["truelist"] = mergeList(rightTokens[0]["truelist"], rightTokens[3]["truelist"]);
                              leftToken["falselist"] = rightTokens[3]["falselist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"bool", "&&", "M", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              backPatch(leftToken["truelist"], nextinstr);
                              leftToken["truelist"] = rightTokens[3]["truelist"];
                              leftToken["falselist"] = mergeList(rightTokens[0]["falselist"], rightTokens[3]["falselist"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"!", "bool"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["truelist"] = rightTokens[1]["falselist"];
                              leftToken["falselist"] = rightTokens[1]["truelist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"bool", {"(", "bool", ")"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["truelist"] = rightTokens[1]["truelist"];
                              leftToken["falselist"] = rightTokens[1]["falselist"];
                              return 0;
                          }}));
    rules.push_back(Rule({"rel", {"<"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["op"] = Quaternion::toStr(Quaternion::Operation::IF_X_LT_Y_GOTO);
                              return 0;
                          }}));
    rules.push_back(Rule({"rel", {">"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["op"] = Quaternion::toStr(Quaternion::Operation::IF_X_GT_Y_GOTO);
                              return 0;
                          }}));
    rules.push_back(Rule({"rel", {"<="}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["op"] = Quaternion::toStr(Quaternion::Operation::IF_X_LE_Y_GOTO);
                              return 0;
                          }}));
    rules.push_back(Rule({"rel", {">="}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["op"] = Quaternion::toStr(Quaternion::Operation::IF_X_GE_Y_GOTO);
                              return 0;
                          }}));
    rules.push_back(Rule({"rel", {"=="}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["op"] = Quaternion::toStr(Quaternion::Operation::IF_X_EQ_Y_GOTO);
                              return 0;
                          }}));
    rules.push_back(Rule({"rel", {"!="}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["op"] = Quaternion::toStr(Quaternion::Operation::IF_X_NE_Y_GOTO);
                              return 0;
                          }}));
    rules.push_back(Rule({"M", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["instr"] = std::to_string(nextinstr);
                              return 0;
                          }}));
    rules.push_back(Rule({"N", {"ε"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["nextlist"] = makeList(nextinstr);
                              gen(Quaternion::Operation::GOTO, "_");
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"expr", "+", "expr"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::ADD, rightTokens[0]["addr"], rightTokens[2]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"expr", "-", "expr"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::SUB, rightTokens[0]["addr"], rightTokens[2]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"expr", "*", "expr"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::MUL, rightTokens[0]["addr"], rightTokens[2]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"expr", "/", "expr"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::DIV, rightTokens[0]["addr"], rightTokens[2]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"-", "expr"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::SUB, "0", rightTokens[1]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"(", "expr", ")"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = rightTokens[1]["addr"];
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"loc"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::ARRAY_ASSIGN_YI, rightTokens[0]["lexeme"], rightTokens[0]["addr"], leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"id"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              SymbolTable::get_from_symbol_table(rightTokens[0]["lexeme"], rightTokens[0]);
                              leftToken["addr"] = rightTokens[0]["lexeme"];
                              return 0;
                          }}));
    rules.push_back(Rule({"expr", {"num"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["addr"] = rightTokens[0]["val"];
                              return 0;
                          }}));
    rules.push_back(Rule({"loc", {"loc", "[", "expr", "]"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              leftToken["lexeme"] = rightTokens[0]["lexeme"];
                              leftToken["type"] = get_elem(rightTokens[0]["type"]);
                              std::string temo = Temp::newTemp();
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::MUL, rightTokens[2]["addr"], std::to_string(get_width(leftToken["type"])), temo);
                              gen(Quaternion::ADD, rightTokens[0]["addr"], temo, leftToken["addr"]);
                              return 0;
                          }}));
    rules.push_back(Rule({"loc", {"id", "[", "expr", "]"}, [&](ACTION_FUNCTION_PARAM) -> int
                          {
                              SymbolTable::get_from_symbol_table(rightTokens[0]["lexeme"], rightTokens[0]);
                              leftToken["lexeme"] = rightTokens[0]["lexeme"];
                              leftToken["type"] = get_elem(rightTokens[0]["type"]);
                              leftToken["addr"] = Temp::newTemp();
                              gen(Quaternion::MUL, rightTokens[2]["addr"], std::to_string(get_width(leftToken["type"])), leftToken["addr"]);
                              return 0;
                          }}));
    parseTab.setRules(rules);
}

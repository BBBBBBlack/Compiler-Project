#include <ParseTab.hpp>
#include <stdio.h>
#include <ctype.h>

#include "pch.hpp"
#include "Rule.hpp"
#include "Rules.hpp"
#include "FAStruct.hpp"
#include "Config.hpp"

int main(int argc, char *argv[])
{
    // if (argc != 2)
    // {
    //     std::cerr << "Usage: " << argv[0] << " <config file>" << std::endl;
    //     return 1;
    // }
    // std::string configFile = argv[1];
    // std::ifstream jfile(configFile);
    // json config = json::parse(jfile);
    // jfile.close();
    // if (config.contains("rules"))
    // {
    //     // 读入产生式
    //     json rules = config["rules"];
    //     // 重要
    //     Rules::rules.reserve(rules.size() * 50);
    //     int cnt = 0;
    //     for (const auto &item : rules)
    //     {
    //         std::string pattern = item["pattern"];
    //         // 产生式左部
    //         std::string father;
    //         int i;
    //         for (i = 0; i < pattern.size(); i++)
    //         {
    //             if (!isspace(pattern[i]) && pattern[i] != ':')
    //             {
    //                 father += pattern[i];
    //             }
    //             else if (pattern[i] == ':')
    //             {
    //                 Rules::rules.push_back(Rule(cnt++, father));
    //                 Rules::NonTermVec.insert(father);
    //                 break;
    //             }
    //         }
    //         // 产生式右部
    //         std::string temp = "";
    //         bool flag = false; // 是否为终结符
    //         for (int j = i + 1; j < pattern.size(); j++)
    //         {
    //             if (pattern[j] == '\'')
    //             {
    //                 // 读到下一个\'为止
    //                 for (int k = j + 1; k < pattern.size(); k++)
    //                 {
    //                     if (pattern[k] == '\'')
    //                     {
    //                         j = k;
    //                         break;
    //                     }
    //                     temp += pattern[k];
    //                 }
    //                 Rules::TermVec.insert(temp);
    //                 Rules::rules[Rules::rules.size() - 1].addRight(temp);
    //                 // printf("%s\n",temp.c_str());
    //                 temp = "";
    //             }
    //             else if (isspace(pattern[j]))
    //             {
    //                 if (temp != "")
    //                 {
    //                     Rules::NonTermVec.insert(temp);
    //                     Rules::rules[Rules::rules.size() - 1].addRight(temp);
    //                     // printf("%s\n",temp.c_str());
    //                     temp = "";
    //                 }
    //             }
    //             else if (pattern[j] == '|')
    //             {
    //                 Rules::rules.push_back(Rule(cnt++, father));
    //             }
    //             else
    //             {
    //                 temp += pattern[j];
    //             }
    //             if (j == pattern.size() - 1 && temp != "")
    //             {
    //                 Rules::NonTermVec.insert(temp);
    //                 Rules::rules[Rules::rules.size() - 1].addRight(temp);
    //                 // printf("%s\n",temp.c_str());
    //             }
    //         }
    //     }

    /*
    START
    */
    std::string configFile = "test/lab/config.json",
                outFileName = "test/test1/parse.cpp";
    Config myconfig(configFile);
    myconfig.analysis(outFileName);
    Rules::genRuleMap();
    // 增广文法
    Rules::addStart();
    Rules::getAllFirst();
    Rules::getFollow();
    // 构造自动机
    FA fa;
    fa.createFA(Rules::rules);
    fa.drawFA("test/test1/out/FA.md");
    std::vector<State> res = fa.createTable();
    Rules::transForAnalysisTable();
    ParseTab parseTab(res);
    parseTab.saveToFile("test/test1/parseTable.md");
    /*
    END
    */
    return 0;
}
#include <ParseTab.hpp>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <nlohmann/json.hpp>
#include <Rule.hpp>
using json = nlohmann::json;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <config file>" << std::endl;
        return 1;
    }
    std::string configFile = argv[1];
    std::ifstream jfile(configFile);

    json config = json::parse(jfile);
    jfile.close();

    if (config.contains("rules"))
    {
        // 读入产生式
        json rules = config["rules"];
        for (const auto &item : rules)
        {
            std::string pattern = item["pattern"];

            // 产生式左部
            std::string father;
            int i;
            for (i = 0; i < pattern.size(); i++)
            {
                if (isalpha(pattern[i]))
                {
                    father += pattern[i];
                }
                else if (pattern[i] == ':')
                {
                    Rules::rules.push_back(Rule(father));
                    Rules::nonTermVec.insert(father);
                    break;
                }
            }
            // 产生式右部
            std::string temp = "";
            bool flag = false; // 是否为终结符
            for (int j = i + 1; j < pattern.size(); j++)
            {
                if (pattern[j] == '\'')
                {
                    if (flag)
                    {
                        Rules::termVec.insert(temp);
                        Rules::rules[Rules::rules.size() - 1].addRight(temp);
                        // printf("%s\n",temp.c_str());
                        flag = false;
                        temp = "";
                    }
                    else
                    {
                        flag = true;
                    }
                }
                else if (isspace(pattern[j]))
                {
                    if (temp != "")
                    {
                        Rules::nonTermVec.insert(temp);
                        Rules::rules[Rules::rules.size() - 1].addRight(temp);
                        // printf("%s\n",temp.c_str());
                        temp = "";
                    }
                }
                else if (pattern[j] == '|')
                {
                    Rules::rules.push_back(Rule(father));
                }
                else
                {
                    temp += pattern[j];
                }
                if (j == pattern.size() - 1 && temp != "")
                {
                    Rules::nonTermVec.insert(temp);
                    Rules::rules[Rules::rules.size() - 1].addRight(temp);
                    // printf("%s\n",temp.c_str());
                }
            }
        }

        // 增廣文法
        std::string start = Rules::rules[0].getLeft();
        Rules::rules.push_back(Rule("S'"));
        Rules::rules[Rules::rules.size() - 1].addRight(start);
        Rules::nonTermVec.insert("S'");
        // Rules::printRules();
        // Rules::printNonTermVec();
        // Rules::printTermVec();

        // 构造自动机
        

    }
    return 0;
}
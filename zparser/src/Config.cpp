#include "Config.hpp"

void Config::analysis(std::string outFileName)
{
    std::string folderPath = outFileName.substr(0, outFileName.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    std::ofstream outFile(outFileName, std::ios::trunc);
    analysis(outFile);
    outFile.close();
}

void Config::analysis(std::ofstream &outFile)
{
    // TODO 解析config.json中的输出文件配置
    initOutFile(outFile);
    analysisCopy(outFile);
    generateMain(outFile);
    analysisRule(outFile);
}

void Config::initOutFile(std::ofstream &outFile)
{
    // 打印banner
    outFile << "/*" << std::endl;
    outFile << " * This file is generated by ZTableGenerator" << std::endl;
    outFile << " * Do not modify this file" << std::endl;
    outFile << BANNER_WITH_ANNOTATION_SYMBOLS;
    outFile << " */" << std::endl;

    outFile << "#include \"Parser.hpp\"" << std::endl;
    outFile << "#include \"ExposeFun.hpp\"" << std::endl;
    outFile << "#include \"ParserFun.hpp\"" << std::endl;
    // outFile << "#include \"Tool.hpp\"" << std::endl;
    outFile << std::endl;

    // rules设置函数声明
    outFile << "void setRules(ParseTab &parseTab);" << std::endl;
}

void Config::analysisCopy(std::ofstream &outFile)
{
    std::vector<std::string> copyVec = config[CONFIG_COPY];
    for (std::string copy : copyVec)
    {
        outFile << copy << std::endl;
    }
    outFile << std::endl;
}

void writeRule(std::ofstream &outFile, const std::string &left, const std::vector<Symbol> &rights, std::vector<std::string> actionStrVec)
{
    outFile << "    rules.push_back(Rule("
            << "{\"" << left << "\", ";
    outFile << "{";
    bool flag = false;
    for (const auto &right : rights)
    {
        if (flag)
        {
            outFile << ", ";
        }
        else
        {
            flag = true;
        }
        outFile << "\"" << right << "\"";
    }
    outFile << "}, ";
    outFile << "[&](ACTION_FUNCTION_PARAM) -> int"
            << std::endl;
    outFile << "                          {" << std::endl;
    for (const auto &actionStr : actionStrVec)
    {
        outFile << "                              " << actionStr << std::endl;
    }
    outFile << "                              return 0;" << std::endl;
    outFile << "                          }}));" << std::endl;
}

void replaceTokens(std::vector<std::string> &actionStrVec)
{
    std::regex rightRegex(RIGHT_VALUE_REGEX), leftRegex(LEFT_VALUE_REGEX);

    for (std::string &actionStr : actionStrVec)
    {
        actionStr = std::regex_replace(actionStr, rightRegex, "rightTokens[$1].value", std::regex_constants::match_default);

        actionStr = std::regex_replace(actionStr, leftRegex, "leftToken.value");
    }
}

void Config::analysisRule(std::ofstream &outFile)
{
    outFile << "void setRules(ParseTab &parseTab)" << std::endl;
    outFile << "{" << std::endl;
    outFile << "    std::vector<Rule> rules;" << std::endl;

    if (!config.contains(CONFIG_RULES))
    {
        std::cerr << "No rules in config file" << std::endl;
        return;
    }

    json rules = config[CONFIG_RULES];
    Rules::rules.reserve(rules.size() * 50);

    int cnt = 0;
    std::regex rightRegex(RIGHT_REGEX);
    std::smatch match;
    std::string::const_iterator searchStart;
    for (const auto &rule : rules)
    {
        std::string left = rule[CONFIG_LEFT];
        json rights = rule[CONFIG_RIGHTS];
        for (const auto &right : rights)
        {
            std::string rightStr = right[CONFIG_RIGHT];
            std::vector<std::string> actionStrVec = right[CONFIG_ACTION];

            Rules::rules.push_back(Rule(cnt++, left));
            Rules::NonTermVec.insert(left);

            // 解析产生式右部
            searchStart = rightStr.cbegin();
            while (std::regex_search(searchStart, rightStr.cend(), match, rightRegex))
            {
                for (size_t i = 1; i < match.size(); ++i)
                {
                    if (match[i].matched)
                    {
                        if (i == 1) // 匹配到终结符
                        {
                            Rules::TermVec.insert(match[i]);
                        }
                        else // 匹配到非终结符
                        {
                            Rules::NonTermVec.insert(match[i]);
                        }
                        Rules::rules[cnt - 1].addRight(match[i]);
                    }
                }
                searchStart = match.suffix().first;
            }

            // 进行引用替换
            replaceTokens(actionStrVec);
            // 输出rule为.cpp
            writeRule(outFile, left, Rules::rules[cnt - 1].getRight(), actionStrVec);
        }
    }

    outFile << "    parseTab.setRules(rules);" << std::endl;
    outFile << "}" << std::endl
            << std::endl;
}

void Config::generateMain(std::ofstream &outFile)
{
    // outFile << "bool error_flag = false;" << std::endl;
    // 输入参数
    outFile << "static struct option long_options[] = {" << std::endl;
    outFile << "    {\"input\", required_argument, 0, 'i'}," << std::endl;
    outFile << "    {\"table\", optional_argument, 0, 't'}," << std::endl;
    outFile << "    {\"output\", optional_argument, 0, 'o'}," << std::endl;
    outFile << "    {\"process\", optional_argument, 0, 'p'}," << std::endl;
    outFile << "    {\"code\", optional_argument, 0, 'c'}," << std::endl;
    outFile << "    {\"help\", no_argument, 0, 'h'}," << std::endl;
    outFile << "    {0, 0, 0, 0} // 结束标志" << std::endl;
    outFile << "};" << std::endl;
    outFile << std::endl;

    // 移动到ParserFun.hpp中声明
    outFile << "// ParserFun.hpp中声明了 ParseTab tab; Parser parser(tab);" << std::endl;
    // 全局声明Parsertab和Parser
    // outFile << "ParseTab tab;" << std::endl;
    // outFile << "Parser parser(tab);" << std::endl;
    // 暴露语义分析所需函数给action
    // outFile << "auto &gen = zparser.gen;" << std::endl;
    // outFile << "auto &makeList = zparser.makeList;" << std::endl;
    // outFile << "auto &mergeList = zparser.mergeList;" << std::endl;
    // outFile << "auto &backPatch = zparser.backPatch;" << std::endl;
    outFile << std::endl;

    // main函数
    outFile << "int main(int argc, char *argv[])\n";
    outFile << "{\n";
    outFile << "    char options[] = \"i:t:o:p:h:c:\";\n";
    outFile << "\n";
    // outFile << "    ParseTab tab;\n";
    outFile << "    std::string tokenFile;\n";
    outFile << "    std::string tableFile = DEFAULT_TABLE_FILE;\n";
    outFile << "    std::string outputFile = DEFAULT_OUTPUT_FILE;\n";
    outFile << "    std::string processFile = DEFAULT_PROCESS_FILE;\n";
    outFile << "    std::string codeTargetFile = DEFAULT_CODE_TARGET_FILE;\n";
    outFile << "    int opt;\n";
    outFile << "    while ((opt = getopt_long(argc, argv, options, long_options, nullptr)) != -1)\n";
    outFile << "    {\n";
    outFile << "        switch (opt)\n";
    outFile << "        {\n";
    outFile << "        case 'i':\n";
    outFile << "            removeSpaces(optarg);\n";
    outFile << "            tokenFile = optarg;\n";
    outFile << "            break;\n";
    outFile << "        case 't':\n";
    outFile << "            removeSpaces(optarg);\n";
    outFile << "            tableFile = optarg;\n";
    outFile << "            break;\n";
    outFile << "        case 'o':\n";
    outFile << "            removeSpaces(optarg);\n";
    outFile << "            outputFile = optarg;\n";
    outFile << "            break;\n";
    outFile << "        case 'p':\n";
    outFile << "            removeSpaces(optarg);\n";
    outFile << "            processFile = optarg;\n";
    outFile << "            break;\n";
    outFile << "        case 'c':\n";
    outFile << "            removeSpaces(optarg);\n";
    outFile << "            codeTargetFile = optarg;\n";
    outFile << "            break;\n";
    outFile << "        case 'h':\n";
    outFile << "        default: // 打印帮助信息\n";
    outFile << "            std::cout << \"Usage: \" << argv[0] << std::endl;\n";
    outFile << "            std::cout << \"[REQUIRED] -i/--input \\t<token file>\" << std::endl;\n";
    outFile << "            std::cout << \"[OPTIONAL] -t/--table \\t<table file>\" << std::endl;\n";
    outFile << "            std::cout << \"[OPTIONAL] -o/--output \\t<output file>\" << std::endl;\n";
    outFile << "            std::cout << \"[OPTIONAL] -p/--process \\t<process file>\" << std::endl;\n";
    outFile << "            std::cout << \"[OPTIONAL] -c/--code \\t<code file>\" << std::endl;\n";
    outFile << "\n";
    outFile << "            return 0;\n";
    outFile << "            break;\n";
    outFile << "        }\n";
    outFile << "    }\n";
    outFile << "\n";
    outFile << "    std::cout << \"token file: \" << tokenFile << std::endl;\n";
    outFile << "    std::cout << \"table file: \" << tableFile << std::endl;\n";
    outFile << "    std::cout << \"output file: \" << outputFile << std::endl;\n";
    outFile << "    std::cout << \"process file: \" << processFile << std::endl;\n";
    outFile << "    std::cout << \"code target file: \" << codeTargetFile << std::endl;\n";

    outFile << "\n";
    outFile << "    setRules(tab);\n";
    outFile << "    tab.loadFromFile(tableFile);\n";
    // outFile << "    Parser parser(tab);\n";
    outFile << "    parser.setParseTab(tab);\n";
    outFile << "    parser.setOutputFile(outputFile);\n";
    outFile << "    parser.grammarAnalysis(tokenFile, processFile, codeTargetFile);\n";
    outFile << "    printInstr(std::cout);\n";
    outFile << "    return 0;\n";
    outFile << "}\n";
}
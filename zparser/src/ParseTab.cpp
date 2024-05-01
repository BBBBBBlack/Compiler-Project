#include "ParseTab.hpp"
#include <filesystem>
#include <algorithm>

ParseTab::ParseTab() {}

ParseTab::~ParseTab() {}

int ParseTab::saveToFile(const std::string &filename)
{
    std::string folderPath = filename.substr(0, filename.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    std::ofstream out(filename, std::ios::trunc);
    if (!out.is_open())
    {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return 0;
    }

    // int returnValue = saveProduction(out) && saveParseTab(out);
    int returnValue = saveParseTab(out);
    out.close();

    return returnValue;
}

int ParseTab::loadFromFile(const std::string &filename)
{
    std::ifstream in(filename);
    if (!in.is_open())
    {
        std::cerr << "Error: 未找到分析表文件 " << filename << std::endl;
        return 0;
    }

    int returnValue = loadParseTab(in);
    in.close();
    return returnValue;
}

int ParseTab::saveParseTab(std::ofstream &out)
{
    out << PARSE_TAB_HEADING << std::endl;

    // 计数信息
    out << "- Terminal size : " << termVec.size() << std::endl;
    out << "- Non-terminal size : " << nonTermVec.size() << std::endl;
    out << "- State size : " << states.size() << std::endl;
    out << std::endl;

    // 表头action / goto
    out << "| | ";
    bool flag = true;
    for (int i = 0; i < termVec.size(); i++)
    {
        if (flag)
        {
            out << "ACT";
            flag = false;
        }
        out << " | ";
    }
    flag = true;
    for (int i = 0; i < nonTermVec.size(); i++)
    {
        if (flag)
        {
            out << "GOTO";
            flag = false;
        }
        out << " | ";
    }
    out << std::endl;

    // md表格头
    int count = 1 + termVec.size() + nonTermVec.size();
    out << "| ";
    for (int i = 0; i < count; i++)
    {
        out << "--- | ";
    }
    out << std::endl;

    // 符号行
    out << "| | ";
    for (auto &symbol : termVec)
    {
        out << symbol << " | ";
    }
    for (auto &symbol : nonTermVec)
    {
        out << symbol << " | ";
    }
    out << std::endl;

    // 状态
    int i = 0;
    for (auto &state : states)
    {
        out << "| " << i << " | ";
        for (int j = 0; j < termVec.size(); j++)
        {
            if (state.actions.find(termVec[j]) != state.actions.end())
            {
                out << state.actions[termVec[j]] << " | ";
            }
            else
            {
                out << "  | ";
            }
        }
        for (int j = 0; j < nonTermVec.size(); j++)
        {
            if (state.actions.find(nonTermVec[j]) != state.actions.end())
            {
                out << state.actions[nonTermVec[j]] << " | ";
            }
            else
            {
                out << "  | ";
            }
        }
        i++;
        out << std::endl;
    }

    out.close();
    return 1;
}

int ParseTab::loadParseTab(std::ifstream &in)
{
    std::string line;

    // 读到分析表标题
    while (std::getline(in, line))
    {
        if (line == PARSE_TAB_HEADING)
            break;
    }
    if (in.eof())
    {
        std::cerr << "[Error]: 配置文件缺少分析表" << std::endl;
    }

    // 读取计数信息
    int termCount, nonTermCount, stateCount, flag = 0;
    std::getline(in, line);
    std::sscanf(line.c_str(), "- Terminal size : %d", &termCount);
    std::getline(in, line);
    std::sscanf(line.c_str(), "- Non-terminal size : %d", &nonTermCount);
    std::getline(in, line);
    std::sscanf(line.c_str(), "- State size : %d", &stateCount);
    if (termCount == 0 || nonTermCount == 0 || stateCount == 0)
    {
        std::cerr << "[Error]: 配置文件缺少计数信息" << std::endl;
    }
    std::cout << "termCount: " << termCount << " nonTermCount: " << nonTermCount << " stateCount: " << stateCount << std::endl;

    while (std::getline(in, line) && line.empty()) // 跳过空行和Action goto行
    {
    }
    std::getline(in, line); // 跳过表头

    // 读取符号行
    std::getline(in, line);
    std::istringstream iss(line);
    std::string token;
    std::getline(iss, token, '|'); // 跳过第一个空格
    std::getline(iss, token, '|'); // 跳过第一个空表格
    flag = 0;
    int temp_count = 0;
    while (std::getline(iss, token, '|'))
    {
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        if (temp_count < termCount)
        {
            termVec.push_back(token);
        }
        else if (temp_count < termCount + nonTermCount)
        {
            nonTermVec.push_back(token);
        }
        temp_count++;
    }
    // // 打印符号行
    // std::cout << "termVec: ";
    // for (auto &symbol : termVec)
    // {
    //     std::cout << symbol << " ";
    // }
    // std::cout << std::endl;
    // std::cout << "nonTermVec: ";
    // for (auto &symbol : nonTermVec)
    // {
    //     std::cout << symbol << " ";
    // }
    // std::cout << std::endl;

    // 读取状态行
    int productionCount = 0;
    for (int i = 0; i < stateCount; i++)
    {
        std::getline(in, line);
        std::istringstream iss(line);
        std::getline(iss, token, '|'); // 跳过状态编号
        std::getline(iss, token, '|'); // 跳过状态编号
        State state;
        int j = 0; // 计数器 兼 状态编号
        while (std::getline(iss, token, '|'))
        {
            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
            if (j < termCount)
            {
                if (token == "")
                {
                    state.actions[termVec[j]] = Action(A_Error);
                }
                else
                {
                    state.actions[termVec[j]] = Action(token);
                }
            }
            else if (j < termCount + nonTermCount)
            {
                if (token == "")
                {
                    state.actions[nonTermVec[j - termCount]] = Action(A_Error);
                }
                else
                {
                    state.actions[nonTermVec[j - termCount]] = Action(token);
                }
            }
            j++;
        }
        states.push_back(state);

        // // 打印state
        // std::cout << "state: " << states.size() - 1 << std::endl;
        // for (auto &action : state.actions)
        // {
        //     std::cout << "<" << action.first << "," << action.second << "> " << std::endl;
        // }
    }

    return checkRules();
}

int ParseTab::saveRules(std::ofstream &out)
{
    out << "Productions:" << std::endl;
    int i = 0;
    for (auto &production : rules)
    {
        // 输出产生式序号
        out << "(" << i << "): ";

        out << production.left << PRODUCTION_CONCAT;
        for (auto &symbol : production.right)
        {
            out << symbol << " ";
        }
        out << std::endl;
    }
    out << std::endl;
    return 1;
}

int ParseTab::checkRules()
{
    for (auto &state : states)
    {
        for (auto &action : state.actions)
        {
            if (action.second.type == ActionType::A_Reduce)
            {
                if (!(0 < action.second.data && action.second.data <= rules.size()))
                {
                    std::cerr << "[Error]: 分析表中指定了不存在的产生式(" << action.second.data << ")" << std::endl;

                    return 0;
                }
            }
        }
    }
    return 1;
}

Action ParseTab::getNextAction(int stateId, Symbol symbol)
{
    return (0 <= stateId && stateId < states.size()) ? states[stateId].actions[symbol] : Action(A_Error);
}
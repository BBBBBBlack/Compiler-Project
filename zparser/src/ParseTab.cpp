#include "ParseTab.hpp"
#include <filesystem>
#include <algorithm>

ParseTab::ParseTab() {}

ParseTab::~ParseTab() {}

int ParseTab::saveParseTab(const std::string &filename)
{
    std::string folderPath = filename.substr(0, filename.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    std::ofstream out(filename, std::ios::trunc);
    if (!out.is_open())
    {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return;
    }

    // 表头action / goto
    out << "| |";
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
    for (auto &str : termVec)
    {
        out << str << " | ";
    }
    for (auto &str : nonTermVec)
    {
        out << str << " | ";
    }
    out << std::endl;

    int i = 0;
    for (auto &state : states)
    {
        out << "| " << i << " | ";
        for (int j = 0; j < termVec.size(); j++)
        {
            if (state.actions.find(j) != state.actions.end())
            {
                out << state.actions[j] << " | ";
            }
            else
            {
                out << "  | ";
            }
        }
        for (int j = 0; j < nonTermVec.size(); j++)
        {
            if (state.gotos.find(j) != state.gotos.end())
            {
                out << ((state.gotos[j] == -1) ? " " : std::to_string(state.gotos[j])) << " | ";
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
}

int ParseTab::loadParseTab(const std::string &filename)
{
    std::ifstream in(filename);
    try
    {
        if (!in.is_open())
        {
            std::cerr << "Error: cannot open file " << filename << std::endl;
            return -1;
        }

        std::string line;
        std::getline(in, line);
        // 计算有多少个终结符和非终结符
        int termCount = 0, nonTermCount = 0, flag = 0;
        std::istringstream iss(line);
        std::string token;
        std::getline(iss, token, '|'); // 跳过第一个空格
        std::getline(iss, token, '|'); // 跳过第一个空表格
        while (std::getline(iss, token, '|'))
        {
            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());

            if (token == "GOTO")
            {
                flag = 1;
            }
            if (flag == 0)
            {
                termCount++;
            }
            else
            {
                nonTermCount++;
            }
        }
        // 行末会多一个空格, 特殊处理一下
        nonTermCount--;

        std::cout << "termCount: " << termCount << " nonTermCount: " << nonTermCount << std::endl;

        std::getline(in, line);

        // 读取符号行
        std::getline(in, line);
        iss = std::istringstream(line);
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

        // 读取状态行
        while (std::getline(in, line))
        {
            std::istringstream iss(line);
            std::getline(iss, token, '|'); // 跳过状态编号
            std::getline(iss, token, '|'); // 跳过状态编号
            State state;
            int i = 0;
            while (std::getline(iss, token, '|'))
            {
                token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
                if (!token.empty())
                {
                    if (i < termVec.size())
                    {
                        state.actions[i] = Action(token);
                    }
                    else if (i < termVec.size() + nonTermVec.size())
                    {
                        state.gotos[i - termVec.size()] = std::stoi(token);
                    }
                }
                i++;
            }
            states.push_back(state);

            // 打印state
            std::cout << "state: " << states.size() - 1 << state.actions.size() << " " << state.gotos.size() << std::endl;
            for (auto &action : state.actions)
            {
                std::cout << "<" << action.first << "," << action.second << "> " << std::endl;
            }
            for (auto &goto_ : state.gotos)
            {
                std::cout << "<" << goto_.first << "," << goto_.second << "> " << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    finally:
    {
        in.close();
    }
    return 1;
}
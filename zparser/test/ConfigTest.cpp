#include <gtest/gtest.h>
#include "Config.hpp"

TEST(ConfigTest, regex)
{
    std::string input = "'xx' 'xxxx' TTTT";

    std::regex regex(RIGHT_REGEX);
    std::smatch match;

    std::string::const_iterator searchStart(input.cbegin());
    while (std::regex_search(searchStart, input.cend(), match, regex))
    {
        for (size_t i = 1; i < match.size(); ++i)
        {
            if (match[i].matched)
            {
                if (i == 1)
                {
                    std::cout << "Content (with single quotes): " << match[i] << std::endl;
                }
                else
                {
                    std::cout << "Content (without single quotes): " << match[i] << std::endl;
                }
            }
        }
        searchStart = match.suffix().first;
    }
}

TEST(ConfigTest, jsonlib)
{
    std::string configFile = "test/config.json";
    std::ifstream jfile(configFile);
    json config = json::parse(jfile);
    jfile.close();
    std::cout << config.dump(4) << std::endl;
    for (auto &item : config.items())
    {
        std::cout << item.key() << std::endl;
    }
}

TEST(ConfigTest, json)
{
    std::string configFile = "test/config.json", outFileName = "test/out/config/parse.cpp";
    Config myconfig(configFile);
    myconfig.analysis(outFileName);
    // config.analysis(outFileName);
}
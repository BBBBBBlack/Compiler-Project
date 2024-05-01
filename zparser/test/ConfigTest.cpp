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
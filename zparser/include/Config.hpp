#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "pch.hpp"
#include "Rules.hpp"

#define CONFIG_FILE_PARSE_TAB "parseTabFile" // parseTab配置文件
#define CONFIG_COPY "copy"                   // copy段
#define CONFIG_RULES "rules"                 // rules段
#define CONFIG_PATTERN "pattern"
#define CONFIG_LEFT "left"
#define CONFIG_RIGHTS "rights"
#define CONFIG_RIGHT "right"
#define CONFIG_ACTION "action"

#define RIGHT_REGEX "'([^']*)'|([^\\s']+)"
#define RIGHT_VALUE_REGEX "\\$(\\d+)"
#define LEFT_VALUE_REGEX "\\$\\$"

class Config
{
public:
    Config(std::string configFile)
    {
        std::ifstream jfile(configFile);

        config = json::parse(jfile);
        jfile.close();
    }
    void analysis(std::string outFileName);

private:
    json config;

    void analysis(std::ofstream &outFile);
    void initOutFile(std::ofstream &outFile);
    void analysisCopy(std::ofstream &outFile);
    /**
     * 解析config的rule, 保存rule到outFile
     * @param outFile 输出文件
     */
    void analysisRule(std::ofstream &outFile);
    void generateMain(std::ofstream &outFile);
};

#endif // !CONFIG_HPP
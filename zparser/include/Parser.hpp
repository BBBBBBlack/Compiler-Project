#ifndef PARSER_HPP
#define PARSER_HPP

#define BANNER                                         \
    " _________   _    ____  ____  _____ ____  \n"     \
    "|__  /  _ \\ / \\  |  _ \\/ ___|| ____|  _ \\ \n" \
    "  / /| |_) / _ \\ | |_) \\___ \\|  _| | |_) |\n"  \
    " / /_|  __/ ___ \\|  _ < ___) | |___|  _ < \n"    \
    "/____|_| /_/   \\_\\_| \\_\\____/|_____|_| \\_\\\n"

#include "ParseTab.hpp"
#include "pch.hpp"
#include "Token.hpp"

class Parser
{
public:
    void setOutputFile(std::string fileName);

    void grammarAnalysis(std::string tokenFile, ParseTab &parseTab);

private:
    std::ofstream *outputFile = nullptr;
    ParseTab parseTab;
};

#endif
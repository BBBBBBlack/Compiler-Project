#include "Parser.hpp"

void Parser::setOutputFile(std::string fileName)
{
    outputFile = new std::ofstream(); // 申请内存
    std::string folderPath = fileName.substr(0, fileName.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);
    outputFile->open(fileName, std::ios::trunc);
    if (!outputFile->is_open())
    {
        perror("打开文件失败");
    }

    *outputFile << "Generated by \n"
                << "```text\n"
                << BANNER
                << "\n```\n";

    // 向outFile写入当前时间
    std::time_t currentTime = std::time(nullptr);
    *outputFile << "Generate time: " << std::asctime(std::localtime(&currentTime)) << std::endl;
    outputFile->flush();
}

void readInputToken(std::list<Token> &inputTokens, std::istream &tokenStream)
{
    std::string line;

    while (std::getline(tokenStream, line))
    {
        std::stringstream ss(line);
        Token token;
        ss >> token;
        inputTokens.push_back(token);
    }
}

void Parser::writeProcess(std::ofstream &processFile, const std::vector<int> &stateStack,
                          const std::vector<Token> &tokenStack, const std::list<Token> &inputTokens,
                          const Action &action, bool writeHeader)
{
    if (writeHeader)
    {
        processFile << "## 分析过程\n";
        processFile << "| 状态栈 | 符号栈 | 输入串 | 动作 |\n";
        processFile << "| --- | --- | ---: | --- |\n";
    }
    // 状态栈
    processFile << "| ";
    for (auto &state : stateStack)
    {
        processFile << state << " ";
    }
    processFile << "| ";
    // 符号栈
    for (auto &token : tokenStack)
    {
        processFile << token.type << " ";
    }
    processFile << "| ";
    // 输入串
    for (auto &token : inputTokens)
    {
        processFile << token.type << " ";
    }
    processFile << "| ";

    // 动作
    switch (action.type)
    {
    case ActionType::A_Shift:
        processFile << "Shift " << action.data;
        break;
    case ActionType::A_Reduce:
        processFile << "Reduce " << parseTab.getRule(action.data);
        break;
    case ActionType::A_Accept:
        processFile << "Accept";
        break;
    case ActionType::A_Error:
        processFile << "Error";
        break;
    default:
        processFile << " ";
        break;
    }

    processFile << "|" << std::endl;
}

void Parser::grammarAnalysis(std::string tokenFile, bool needProcess, std::string processFileName)
{
    std::ifstream tokenStream(tokenFile);
    if (!tokenStream.is_open())
    {
        perror("打开文件失败");
    }
    grammarAnalysis(tokenStream, needProcess, processFileName);
}

void Parser::grammarAnalysis(bool needProcess, std::string processFileName)
{
    grammarAnalysis(std::cin, needProcess, processFileName);
}

void Parser::grammarAnalysis(std::istream &tokenStream, bool needProcess, std::string processFileName)
{
    std::ofstream processFile;

    std::vector<int> stateStack;
    std::vector<Token> tokenStack;
    std::list<Token> inputTokens;
    stateStack.push_back(0);
    tokenStack.push_back(Token(END_SYMBOL, "", 0, 0));

    readInputToken(inputTokens, tokenStream);
    inputTokens.push_back(Token(END_SYMBOL, "", 0, 0));

    if (needProcess)
    {
        std::string folderPath = processFileName.substr(0, processFileName.find_last_of("/\\"));
        std::filesystem::create_directories(folderPath);
        processFile.open(processFileName, std::ios::trunc);
        if (!processFile.is_open())
        {
            perror("分析过程输出文件打开失败");
        }

        writeProcess(processFile, stateStack, tokenStack, inputTokens, Action(), true); // 写入表头
        // writeProcess(processFile, stateStack, tokenStack, inputTokens, Action(), false);
    }

    while (true)
    {
        int currentState = stateStack.back();
        Token token = inputTokens.front();

        Action action = parseTab.getNextAction(currentState, token.type);
        if (action.type == ActionType::A_Shift) // 移入
        {
            stateStack.push_back(action.data);
            tokenStack.push_back(token);
            inputTokens.pop_front();
        }
        else if (action.type == ActionType::A_Reduce) // 规约
        {
            Rule rule = parseTab.getRule(action.data);
            int ruleSize = rule.right.size();
            Token leftToken(rule.left, "", -1, -1); // 产生式左部Token(未初始化行号和位置)
            std::vector<Token> rightTokens;
            for (int i = 0; i < ruleSize; i++)
            {
                stateStack.pop_back();
                Token topToken = tokenStack.back();
                rightTokens.push_back(topToken);
                if (leftToken.lineno == -1) // 用产生式右部第一个Token的lineno和pos初始化产生式左部Token
                {
                    leftToken.lineno = topToken.lineno;
                    leftToken.pos = topToken.pos;
                }
                tokenStack.pop_back();
            }
            // 执行产生式动作
            rule.action(leftToken, rightTokens);
            // 更新状态
            tokenStack.push_back(leftToken);
            stateStack.push_back(parseTab.getNextAction(stateStack.back(), leftToken.type).data);
        }
        else if (action.type == ActionType::A_Accept)
        {
            std::cout << "Accept!" << std::endl;
            writeProcess(processFile, stateStack, tokenStack, inputTokens, action, false);
            break;
        }
        else if (action.type == ActionType::A_Error)
        {
            std::cerr << "[Error]: Syntax error at <Line: " << token.lineno << ", Position: " << token.pos << ">" << std::endl;
            writeProcess(processFile, stateStack, tokenStack, inputTokens, action, false);
            break;
        }

        if (needProcess)
        {
            writeProcess(processFile, stateStack, tokenStack, inputTokens, action, false);
        }
    }
}
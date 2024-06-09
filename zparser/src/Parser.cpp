#include "Parser.hpp"

bool error_flag = false;
int offset;
std::string t;
int w;
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
    // needCST = true;
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

void Parser::writeProcess(std::ofstream &processFile, const Action &action, bool writeHeader)
{
    if (!needProcess)
    {
        return;
    }

    if (writeHeader)
    {
        processFile << "## 分析过程\n";
        processFile << "| 状态栈 | 符号栈 | 输入串 | 动作 |\n";
        processFile << "| --- | --- | ---: | --- |\n";
    }
    // 如果processFile>10MB, 可能出错, 打印错误信息
    if (processFile.tellp() > PROCESS_FILE_MAX_SIZE)
    {
        std::cout << "[ERROR] 分析过程文件过大, 可能出错" << std::endl;
        return;
    }

    // 状态栈
    processFile << "| ";
    for (auto &state : stateStack)
    {
        processFile << '`' << state << "` ";
    }
    processFile << "| ";
    // 符号栈
    for (auto &token : tokenStack)
    {
        processFile << '`' << token.type << "` ";
    }
    processFile << "| ";
    // 输入串
    for (auto &token : inputTokens)
    {
        processFile << '`' << token.type << "` ";
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

void Parser::grammarAnalysis(std::string tokenFile, std::string codeTargetFile)
{
    std::ifstream tokenStream(tokenFile);
    if (!tokenStream.is_open())
    {
        perror("打开文件失败");
    }
    grammarAnalysis(tokenStream, "", codeTargetFile);
}

void Parser::grammarAnalysis(std::string tokenFile, std::string processFileName, std::string codeTargetFile)
{
    std::ifstream tokenStream(tokenFile);
    if (!tokenStream.is_open())
    {
        fprintf(stderr, "[ERROR] Token文件(%s)读入失败\n", tokenFile.c_str());
        perror("打开文件失败");
        return;
    }
    if (processFileName != "")
    {
        this->needProcess = true;
    }
    grammarAnalysis(tokenStream, processFileName, codeTargetFile);
}

void Parser::grammarAnalysis(bool needProcess, std::string processFileName, std::string codeTargetFile)
{
    this->needProcess = needProcess;
    grammarAnalysis(std::cin, processFileName, codeTargetFile);
}

void Parser::grammarAnalysis(std::istream &tokenStream, std::string processFileName, std::string codeTargetFile)
{
    std::ofstream processFile;

    stateStack.push_back(0);
    Token token0(END_SYMBOL, "", 0, 0);
    tokenStack.push_back(token0);
    // 所有token流
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

        writeProcess(processFile, Action(), true); // 写入表头
        // writeProcess(processFile, stateStack, tokenStack, inputTokens, Action(), false);
    }

    while (true)
    {
        int currentState = stateStack.back();
        Token token = inputTokens.front();

        Action action = parseTab.getNextAction(currentState, token.type);
        writeProcess(processFile, action, false);
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
            // std::vector<int> rightIndexs; // deprecated, 用于CST

            if (rule.right[0] == EPSILON) // ε产生式特判, 插入一个空Token
            {
                stateStack.push_back(-1);
                tokenStack.push_back(Token::getEpsilon());
            }

            // 产生式右部出栈
            for (int i = 0; i < ruleSize; i++)
            {
                stateStack.pop_back();
                Token topToken = tokenStack.back();
                rightTokens.push_back(topToken);
                // rightIndexs.push_back(tokenStack.back().first);
                if (leftToken.lineno == -1) // 用产生式右部第一个Token的lineno和pos初始化产生式左部Token
                {
                    leftToken.lineno = topToken.lineno;
                    leftToken.pos = topToken.pos;
                }
                tokenStack.pop_back();
            }
            // 执行产生式动作
            // TODO: 因为入栈顺序是反的, 所以这里的rightTokens是反的, 是否需要reverse?
            std::reverse(rightTokens.begin(), rightTokens.end());
            rule.action(leftToken, rightTokens, tokenStack, tempToken, codeTargetFile);

            // 更新状态
            // int leftIndex = cst.addNode(leftToken);
            tokenStack.push_back(leftToken);
            // cst.addConnection(leftIndex, rightIndexs);
            // note: 如果是Error, 则会push -1
            stateStack.push_back(parseTab.getNextAction(stateStack.back(), leftToken.type).data);
        }
        else if (action.type == ActionType::A_Goto) // Goto
        {
            stateStack.push_back(action.data);
        }
        else if (action.type == ActionType::A_Accept)
        {
            if (!error_flag)
            {
                std::cout << "Accept!" << std::endl;
            }
            break;
        }
        else if (action.type == ActionType::A_Error)
        {
            std::cerr << "[Error]: Syntax error at <Line: " << token.lineno << ", Position: " << token.pos << ">" << std::endl;
            break;
        }
    }
    SymbolTable::print_symbol_table();
    // if (needCST)
    // {
    //     cst.printCST(*outputFile);
    // }
    // cst.printCST(std::cout);
}

TokenValue Parser::gen(Quaternion::Operation op, std::string arg1, std::string arg2, std::string result)
{
    Quaternion q(op, arg1, arg2, result);
    instrVec.push_back(q);
    return std::to_string(nextinstr++);
}

TokenValue Parser::gen(Quaternion::Operation op, std::string arg1, std::string arg2)
{
    Quaternion q(op, arg1, arg2);
    instrVec.push_back(q);
    return std::to_string(nextinstr++);
}

TokenValue Parser::gen(Quaternion::Operation op, std::string arg)
{
    Quaternion q(op, arg);
    instrVec.push_back(q);
    return std::to_string(nextinstr++);
}

TokenValue Parser::makeList(TokenValue instrId)
{
    JumpList jumpList;
    jumpList.push_back(std::stoi(instrId));
    jumpListMap[jumpListCnt] = jumpList;
    return std::to_string(jumpListCnt++);
}

TokenValue Parser::mergeList(TokenValue jumpListId1, TokenValue jumpListId2)
{
    // NOTE: 如果是true 没有falseList, 如果是false 没有trueList, 这是正常的, 不需要报错
    if (jumpListId1.length() == 0)
    {
        return jumpListId2;
    }
    if (jumpListId2.length() == 0)
    {
        return jumpListId1;
    }
    if (jumpListId1.length() == 0 && jumpListId2.length() == 0)
    {
        return "";
    }

    // 检查jumpListId1和jumpListId2是否存在
    if (jumpListMap.find(std::stoi(jumpListId1)) == jumpListMap.end())
    {
        throw std::runtime_error("JumpList[id=" + jumpListId1 + "] not found");
    }
    if (jumpListMap.find(std::stoi(jumpListId2)) == jumpListMap.end())
    {
        throw std::runtime_error("JumpList[id=" + jumpListId2 + "] not found");
    }

    JumpList &jumpList1 = jumpListMap[std::stoi(jumpListId1)];
    JumpList &jumpList2 = jumpListMap[std::stoi(jumpListId2)];
    jumpList1.insert(jumpList1.end(), jumpList2.begin(), jumpList2.end());
    jumpListMap.erase(std::stoi(jumpListId2));

    return jumpListId1;
}

void Parser::backPatch(TokenValue jumpListId, int jumpTo)
{
    JumpList &jumpList = jumpListMap[std::stoi(jumpListId)];
    for (auto &instrId : jumpList)
    {
        instrVec[instrId].result = std::to_string(jumpTo);
    }
    jumpListMap.erase(std::stoi(jumpListId));
}
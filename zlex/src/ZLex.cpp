#include "ZLex.hpp"

// ZLex.cpp
std::string yytext; // 当前识别的字符串
int yylineno;       // 当前识别的行号
// TODO
int yypos; // 当前识别的位置

int ZLex::buildAndAnalysis(bool debugMode, PAVec PAvec, std::string outputFAFile,
                           std::ostream &outputStream, std::string sourceFile)
{
    buildDFA(debugMode, PAvec, outputFAFile);
    return lexicalAnalysis(outputStream, sourceFile);
}

void ZLex::buildDFA(bool debugMode, PAVec paVec, std::string outputFileName)
{
    // TODO 将debugMode重构到构造函数中
    this->debugMode = debugMode;
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Building DFA..." << std::endl;

    NFA nfa(outputFileName);
    nfa.setDebugMode(debugMode);
    nfa.buildNFA(paVec);
    if (debugMode)
    {
        nfa.printFA();
        auto endNFA = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedNFA = endNFA - start;
        std::cout << "NFA built in " << elapsedNFA.count() << "s" << std::endl;
    }
    dfa = new DFA(nfa);
    if (debugMode)
    {
        // nfa.printFA(); // 这样调用输出有问题, 懒得改了)
        dfa->printFA();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "DFA built finished in " << elapsed.count() << "s" << std::endl;
}

int ZLex::lexicalAnalysis(std::ostream &outputStream, std::string fileName)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Lexical Analysis..." << std::endl;

    std::ifstream file(fileName);
    if (!file.is_open())
    {
        perror("文件打开失败");
        return -1;
    }

    // 设置文件的读取位置
    file.seekg(pos);

    std::string line;
    yylineno = 0; // 存储行号
    int startStateID = dfa->getStartStateID();
    while (std::getline(file, line)) // Use regular getline function
    {
        line += "\n"; // 补充行末尾的换行符
        yylineno++;   // 更新行号
        int currentStateID = startStateID;
        int lastMatchedState = -1;
        std::string lastMatched = "", afterMatched = "";
        // 从上一次匹配的位置(pos_i)开始, 继续读取
        for (int i = pos_i; i < line.size(); i++)
        {
            char c = line[i];
            currentStateID = dfa->getNext(currentStateID, c);
            if (currentStateID == -1) // 无法匹配
            {
                afterMatched += c;
                if (lastMatchedState != -1) // 存在更短的匹配
                {
                    i = pos_i; // 从上一次匹配的位置(pos_i)开始, 继续读取
                    // 运行action
                    int token = dfa->runAction(lastMatchedState);
                    // 加入符号表？？
                    dfa->addToSymbolTable(lastMatchedState, yytext);
                    // 重置状态机
                    currentStateID = startStateID;
                    lastMatchedState = -1;
                    lastMatched = "";
                    afterMatched = "";
                    if (token != 0) // action有返回值
                    {
                        return token;
                    }
                }
                else // 不存在更短的匹配
                {
                    // 重置状态机
                    outputStream << std::endl
                                 << "[ERROR] at line " << yylineno
                                 << " position " << i
                                 << ":[" << afterMatched << "]" << std::endl;
                    currentStateID = startStateID;
                    lastMatchedState = -1;
                    lastMatched = "";
                    afterMatched = "";
                    continue;
                }
            }
            else if (dfa->states[currentStateID].isAccepting)
            {
                lastMatched += afterMatched + c;
                afterMatched = "";
                lastMatchedState = currentStateID;
                yytext = lastMatched;
                pos_i = i;
            }
            else // 成功匹配, 暂存, 尝试更长的匹配
            {
                afterMatched += c;
            }
        }
        // 处理行末尾, 未匹配状态
        if (lastMatchedState != -1) // 存在更短的匹配
        {
            // 运行action
            int token = dfa->runAction(lastMatchedState);
            // 重置状态机
            currentStateID = startStateID;
            lastMatchedState = -1;
            lastMatched = "";
            afterMatched = "";
            if (token != 0) // action有返回值
            {
                return token;
            }
        }
        // 一行读取完毕, 更新pos
        pos = file.tellg();
        pos_i = 0;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "Lexical Analysis finished in " << elapsed.count() << "s" << std::endl;

    return 0;
}
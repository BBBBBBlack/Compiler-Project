#include "FA.hpp"

FA::FA() {}

FA::~FA() {}

void FA::printFA(int startStateID, std::string fileName, FAStateVec &states)
{
    std::string folderPath = fileName.substr(0, fileName.find_last_of("/\\"));
    std::filesystem::create_directories(folderPath);

    std::ofstream outFile(fileName, std::ios::trunc);
    if (!outFile.is_open())
    {
        perror("打开文件失败");
    }
    // 向outFile写入当前时间
    std::time_t currentTime = std::time(nullptr);
    outFile << "Generate time: " << std::asctime(std::localtime(&currentTime));

    outFile << "## 正则表达式集合" << std::endl;
    for (auto &regex : regexVec)
    {
        outFile << "- " << regex << std::endl;
    }

    outFile << "## 状态图" << std::endl;
    outFile << "```mermaid" << std::endl;
    outFile << "graph LR" << std::endl;

    std::stack<int> stateStack;
    std::unordered_map<int, bool> visited;
    stateStack.push(startStateID);
    // dfs 打印状态
    int i = 1;
    while (!stateStack.empty())
    {
        int stateID = stateStack.top();
        stateStack.pop();
        visited[stateID] = true;

        // print节点
        if (states[stateID].isAccepting)
        {
            outFile << stateID << "((END))" << std::endl;
        }
        else if (stateID == startStateID)
        {
            outFile << stateID << "((START))" << std::endl;
        }
        else
        {
            outFile << stateID << "((" << i++ << "))" << std::endl;
        }

        // print符号边
        for (auto &trans : states[stateID].trans)
        {
            outFile << "--" << trans.first << "-->" << trans.second << std::endl;
            if (visited.find(trans.second) == visited.end())
            {
                stateStack.push(trans.second);
                visited[trans.second] = true;
            }
        }

        // print空边
        for (auto &epsilonTrans : states[stateID].epsilonTrans)
        {
            outFile << stateID << "--" << EPSILON_CHAR << "-->" << epsilonTrans << std::endl;
            if (visited.find(epsilonTrans) == visited.end())
            {
                stateStack.push(epsilonTrans);
                visited[epsilonTrans] = true;
            }
        }
        outFile << std::endl;
    }

    outFile << "```" << std::endl;
}

int FA::addState(bool isAccepting, FAStateVec &states)
{
    FAState faState(states.size(), {}, {}, isAccepting);
    states.push_back(faState);
    return states.size() - 1;
}

void FA::addEdge(int fromStateID, int toStateID, char symbol, FAStateVec &states)
{
    std::string str_sym(1, symbol);
    states[fromStateID].trans[str_sym] = toStateID;
}

void FA::addEdge(int fromStateID, int toStateID, std::string symbol, FAStateVec &states)
{
    if (symbol == EPSILON) // 空边
    {
        states[fromStateID].epsilonTrans.push_back(toStateID);
    }
    else // 转移条件
    {
        states[fromStateID].trans[symbol] = toStateID;
    }
}

FAStateBlock FA::addTransition(char inputSymbol, bool escapeFlag, FAStateBlock block1, FAStateBlock block2, FAStateVec &states)
{
    FAStateBlock resultBlock{block1.beginStateID, block2.endStateID};
    // 问就是不爱用switch
    if (escapeFlag)
    {
        symbolTable[inputSymbol + ""] = true;
        int s1 = addState(0, states), s2 = addState(1, states);
        addEdge(s1, s2, inputSymbol, states);
        resultBlock = {s1, s2};
    }
    else if (inputSymbol == '-') // union
    {
        states[block1.endStateID].isAccepting = 0; // block1的终态取消
        addEdge(block1.endStateID, block2.beginStateID, EPSILON, states);
    }
    else if (inputSymbol == '|') // or
    {
        // block1,2的终态取消
        states[block1.endStateID].isAccepting = 0;
        states[block2.endStateID].isAccepting = 0;

        int orBegin = addState(0, states), orEnd = addState(1, states);
        addEdge(orBegin, block1.beginStateID, EPSILON, states);
        addEdge(orBegin, block2.beginStateID, EPSILON, states);
        addEdge(block1.endStateID, orEnd, EPSILON, states);
        addEdge(block2.endStateID, orEnd, EPSILON, states);
        resultBlock = {orBegin, orEnd};
    }
    else if (inputSymbol == '*') // 闭包
    {
        states[block1.endStateID].isAccepting = 0;
        int closureBegin = addState(0, states), closureEnd = addState(1, states);
        addEdge(closureBegin, block1.beginStateID, EPSILON, states);
        addEdge(block1.endStateID, closureEnd, EPSILON, states);
        addEdge(closureBegin, closureEnd, EPSILON, states);
        addEdge(block1.endStateID, block1.beginStateID, EPSILON, states);
        resultBlock = {closureBegin, closureEnd};
    }
    else if (inputSymbol == '+') // 正闭包
    {
        int closureBegin = addState(0, states), closureEnd = addState(1, states);
        addEdge(closureBegin, block1.beginStateID, EPSILON, states);
        addEdge(block1.endStateID, closureEnd, EPSILON, states);
        addEdge(block1.endStateID, block1.beginStateID, EPSILON, states);
        resultBlock = {closureBegin, closureEnd};
    }
    else if (inputSymbol == '?') // 零次或一次
    {
        int closureBegin = addState(0, states), closureEnd = addState(1, states);
        addEdge(closureBegin, block1.beginStateID, EPSILON, states);
        addEdge(block1.endStateID, closureEnd, EPSILON, states);
        addEdge(closureBegin, closureEnd, EPSILON, states);
        resultBlock = {closureBegin, closureEnd};
    }
    else // 普通字符
    {
        symbolTable[inputSymbol + ""] = true;
        int s1 = addState(0, states), s2 = addState(1, states);
        addEdge(s1, s2, inputSymbol, states);
        resultBlock = {s1, s2};
    }
    return resultBlock;
}

std::string FA::addUnion(std::string regex)
{
    std::string result;
    for (int i = 0; i < regex.size(); i++)
    {
        if (regex[i] == '\\' && !Symbol::isOperator(regex[i + 2]) && (i + 2) != regex.size())
        {
            // 转义字符
            result += regex[i++];
            result += regex[i];
            result += '-';
        }
        // else if ((!Symbol::isOperator(regex[i])) && !Symbol::isOperator(regex[i + 1]) && (i + 1) != regex.size())
        // TODO 好丑陋的if 改了它!
        else if ((regex[i] != '|' && regex[i] != '(') && (!Symbol::isOperator(regex[i + 1]) || regex[i + 1] == '(') && (i + 1) != regex.size())
        {
            result += regex[i];
            result += '-';
        }
        else
        {
            result += regex[i];
        }
    }
    return result;
}

std::string FA::infixToSufix(std::string regex)
{
    std::stack<char> opStack;
    std::string res;

    for (int i = 0; i < regex.size(); i++)
    {
        // 转义字符
        if (regex[i] == '\\')
        {
            res += '\\';
            res += regex[++i];
        }
        else if (regex[i] == '(')
        {
            opStack.push(regex[i]);
        }
        else if (regex[i] == ')')
        {
            while (opStack.top() != '(')
            {
                res += opStack.top();
                opStack.pop();
            }
            // 弹出左括号
            opStack.pop();
        }
        else if (Symbol::isOperator(regex[i]))
        {
            while (!opStack.empty() && Symbol::opOrder[opStack.top()] <= Symbol::opOrder[regex[i]])
            {
                res += opStack.top();
                opStack.pop();
            }
            opStack.push(regex[i]);
        }
        else // 普通字符
        {
            res += regex[i];
        }
    }
    while (!opStack.empty())
    {
        res += opStack.top();
        opStack.pop();
    }

    return res;
}

FAStateBlock FA::regexToBlock(std::string regex, FAStateVec &states)
{
    std::string regexWithUnion = addUnion(regex);
    std::string regexWithSuffix = infixToSufix(regexWithUnion);

    std::stack<FAStateBlock> blockStack;
    for (int i = 0; i < regexWithSuffix.size(); i++)
    {
        FAStateBlock block1, block2;
        if (regexWithSuffix[i] == '\\')
        {
            if (i + 1 > regexWithSuffix.size())
            {
                perror("无效的转义字符");
            }
            blockStack.push(addTransition(regexWithSuffix[i + 1], 1, {}, {}, states));
        }
        else if (Symbol::isOperator(regexWithSuffix[i]))
        {

            block2 = blockStack.top();
            // 正则操作符对象可能只有一个
            if (!Symbol::isUnaryOp(regexWithSuffix[i]))
            {
                blockStack.pop();
            }
            block1 = blockStack.top();
            blockStack.pop();
            blockStack.push(addTransition(regexWithSuffix[i], 0, block1, block2, states));
        }
        else
        {
            blockStack.push({addState(0, states), addState(1, states)});
            addEdge(blockStack.top().beginStateID, blockStack.top().endStateID, regexWithSuffix[i], states);
        }
    }
    return blockStack.top();
}

void FA::buildNFA(RegexVec regexVec)
{
    this->regexVec = regexVec;
    int allBegin = addState(0, NFAStates);
    for (auto &regex : regexVec)
    {
        FAStateBlock block = regexToBlock(regex, NFAStates);
        addEdge(allBegin, block.beginStateID, EPSILON, NFAStates);
    }
    NFAStartStateID = allBegin;
}

/**
 * @brief 获取一个状态的epsilon闭包
 * @param stateID 状态ID
 */
StateSet FA::epsilonClosure(int stateID, FAStateVec &states)
{
    std::unordered_map<int, bool> visited;
    return epsilonClosure(stateID, visited, states);
}

/**
 * @brief 获取一个状态的epsilon闭包
 * @param stateID 状态ID
 * @param visited 访问标记(用于避免重复访问)
 */
StateSet FA::epsilonClosure(int stateID, std::unordered_map<int, bool> &visited, FAStateVec &states)
{
    std::stack<int> stateStack;
    stateStack.push(stateID);
    StateSet result;
    while (!stateStack.empty())
    {
        int stateID = stateStack.top();
        stateStack.pop();
        result.insert(stateID);
        visited[stateID] = true;
        for (auto &epsilonTrans : states[stateID].epsilonTrans)
        {
            if (visited.find(epsilonTrans) == visited.end())
            {
                stateStack.push(epsilonTrans);
                visited[epsilonTrans] = true;
            }
        }
    }
    return result;
}
/**
 * @brief 获取一个状态集的epsilon闭包
 * @param stateSet 状态集
 */
StateSet FA::epsilonClosure(StateSet stateSet, FAStateVec &states)
{
    std::unordered_map<int, bool> visited;
    return epsilonClosure(stateSet, visited, states);
}

/**
 * @brief 获取一个状态集的epsilon闭包
 * @param stateSet 状态集
 * @param visited 访问标记(用于避免重复访问)
 */
StateSet FA::epsilonClosure(StateSet stateSet, std::unordered_map<int, bool> &visited, FAStateVec &states)
{
    StateSet result;
    for (auto &stateID : stateSet)
    {
        StateSet closure = epsilonClosure(stateID, visited, NFAStates);
        result.insert(closure.begin(), closure.end());
    }
    return result;
}

/**
 * @brief 获取一个状态集的转移闭包
 * @param stateSet 状态集
 * @param symbol 转移条件
 */
StateSet FA::move(StateSet stateSet, std::string symbol, FAStateVec &states)
{
    StateSet result;
    for (auto &stateID : stateSet)
    {
        if (states[stateID].trans.find(symbol) != states[stateID].trans.end())
        {
            result.insert(states[stateID].trans[symbol]);
        }
    }
    return result;
}

/**
 * @brief 将states中的NFA转换为DFA
 */
void FA::toDFA()
{
    std::unordered_set<StateSet, StateSetHash> visitedSet;
    std::queue<StateSet> stateSetQueue;
    FAStateVec dfaStates;

    StateSet startStateSet = epsilonClosure(NFAStartStateID, NFAStates);

    stateSetQueue.push(startStateSet);
    while (!stateSetQueue.empty())
    {
        StateSet currentStateSet = stateSetQueue.front();
        stateSetQueue.pop();

        if (visitedSet.find(currentStateSet) == visitedSet.end())
        {
            visitedSet.insert(currentStateSet);
        }
        else
        {
            continue; // 跳过已访问的状态集
        }
        for (auto &symbol : symbolTable)
        {
            StateSet nextStateSet = epsilonClosure(move(currentStateSet, symbol.first, NFAStates), NFAStates);
            if (nextStateSet.size() == 0)
            {
                continue;
            }
            if (visitedSet.find(nextStateSet) == visitedSet.end())
            {
                visitedSet.insert(nextStateSet);
                stateSetQueue.push(nextStateSet);
            }
            // 添加状态转移
        }
    }
}
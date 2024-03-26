#include "FA.hpp"

FA::FA() {}

FA::~FA() {}

void FA::printFA(FAStateBlock block)
{
    printFA(block, "FA.md");
}

void FA::printFA(FAStateBlock block, std::string fileName)
{
    std::ofstream outFile(fileName, std::ios::trunc);
    outFile << "## 状态图" << std::endl;
    outFile << "```mermaid" << std::endl;
    outFile << "graph LR" << std::endl;

    std::stack<int> stateStack;
    std::unordered_map<int, bool> visited;
    stateStack.push(block.beginStateID);
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
        else if (stateID == block.beginStateID)
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

int FA::addState(bool isAccepting)
{
    FAState faState(states.size(), {}, {}, isAccepting);
    states.push_back(faState);
    return states.size() - 1;
}

void FA::addEdge(int fromStateID, int toStateID, char symbol)
{
    std::string str_sym(1, symbol);
    states[fromStateID].trans[str_sym] = toStateID;
}

void FA::addEdge(int fromStateID, int toStateID, std::string symbol)
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

FAStateBlock FA::addTransition(char inputSymbol, bool escapeFlag, FAStateBlock block1, FAStateBlock block2)
{
    FAStateBlock resultBlock{block1.beginStateID, block2.endStateID};
    // 问就是不爱用switch
    if (escapeFlag)
    {
        int s1 = addState(0), s2 = addState(1);
        addEdge(s1, s2, inputSymbol);
        resultBlock = {s1, s2};
    }
    else if (inputSymbol == '-') // union
    {
        states[block1.endStateID].isAccepting = 0; // block1的终态取消
        addEdge(block1.endStateID, block2.beginStateID, EPSILON);
    }
    else if (inputSymbol == '|') // or
    {
        // block1,2的终态取消
        states[block1.endStateID].isAccepting = 0;
        states[block2.endStateID].isAccepting = 0;

        int orBegin = addState(0), orEnd = addState(1);
        addEdge(orBegin, block1.beginStateID, EPSILON);
        addEdge(orBegin, block2.beginStateID, EPSILON);
        addEdge(block1.endStateID, orEnd, EPSILON);
        addEdge(block2.endStateID, orEnd, EPSILON);
        resultBlock = {orBegin, orEnd};
    }
    else if (inputSymbol == '*') // 闭包
    {
        states[block1.endStateID].isAccepting = 0;
        int closureBegin = addState(0), closureEnd = addState(1);
        addEdge(closureBegin, block1.beginStateID, EPSILON);
        addEdge(block1.endStateID, closureEnd, EPSILON);
        addEdge(closureBegin, closureEnd, EPSILON);
        addEdge(block1.endStateID, block1.beginStateID, EPSILON);
        resultBlock = {closureBegin, closureEnd};
    }
    else if (inputSymbol == '+') // 正闭包
    {
        int closureBegin = addState(0), closureEnd = addState(1);
        addEdge(closureBegin, block1.beginStateID, EPSILON);
        addEdge(block1.endStateID, closureEnd, EPSILON);
        addEdge(block1.endStateID, block1.beginStateID, EPSILON);
        resultBlock = {closureBegin, closureEnd};
    }
    else if (inputSymbol == '?') // 零次或一次
    {
        int closureBegin = addState(0), closureEnd = addState(1);
        addEdge(closureBegin, block1.beginStateID, EPSILON);
        addEdge(block1.endStateID, closureEnd, EPSILON);
        addEdge(closureBegin, closureEnd, EPSILON);
        resultBlock = {closureBegin, closureEnd};
    }
    else // 普通字符
    {
        int s1 = addState(0), s2 = addState(1);
        addEdge(s1, s2, inputSymbol);
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
        else if ((regex[i] != '|' && regex[i] != '(') && !Symbol::isOperator(regex[i + 1]) && (i + 1) != regex.size())
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

FAStateBlock FA::regexToBlock(std::string regex)
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
            blockStack.push(addTransition(regexWithSuffix[i + 1], 1, {}, {}));
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
            blockStack.push(addTransition(regexWithSuffix[i], 0, block1, block2));
        }
        else
        {
            blockStack.push({addState(0), addState(1)});
            addEdge(blockStack.top().beginStateID, blockStack.top().endStateID, regexWithSuffix[i]);
        }
    }
    return blockStack.top();
}
#include "NFA.hpp"

std::string NFA::addUnion(std::string regex)
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
        // else if (regex[i] == '-')
        // {
        //     result += '\\';
        //     result += regex[i];
        // }
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

std::string NFA::infixToSufix(std::string regex)
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

FAStateBlock NFA::regexToBlock(PatternAction pa, FAStateVec &states)
{
    std::string regexWithUnion = addUnion(pa.pattern);
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
            // 直连
            // alphabet.insert(regexWithSuffix[i] + "");
            alphabet.insert(std::string(1, regexWithSuffix[i]));
            // symbolTable[regexWithSuffix[i] + ""] = true; // 记录符号
            blockStack.push({addState(0, NullAction, states), addState(1, pa.action, states)});
            addEdge(blockStack.top().beginStateID, blockStack.top().endStateID, regexWithSuffix[i], states);
        }
    }
    if (blockStack.size() != 1)
    {
        std::cerr << "ERROR: \"" << pa.pattern << "\" 正则有误" << std::endl;
    }
    // 添加action
    states[blockStack.top().endStateID].action = pa.action;
    return blockStack.top();
}

void NFA::buildNFA(PAVec &paVec)
{
    this->paVec = &paVec;
    int allBegin = addState(0, NullAction, states);
    for (auto &pa : paVec)
    {
        FAStateBlock block = regexToBlock(pa, states);
        addEdge(allBegin, block.beginStateID, EPSILON, states);
    }
    startStateID = allBegin;

    if (debugMode)
    {
        *outputFile << std::endl
                    << "## 字母表" << std::endl;
        for (auto &letter : alphabet)
        {
            *outputFile << letter << " ";
        }
        *outputFile << std::endl;
    }
}

// TODO 部分代码功能被regexToBlock替代 待重构
FAStateBlock NFA::addTransition(char inputSymbol, bool escapeFlag, FAStateBlock block1, FAStateBlock block2, FAStateVec &states)
{
    FAStateBlock resultBlock{block1.beginStateID, block2.endStateID};
    // 问就是不爱用switch
    if (escapeFlag)
    {
        alphabet.insert(std::string(1, inputSymbol));
        int s1 = addState(0, NullAction, states), s2 = addState(1, states);
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

        int orBegin = addState(0, NullAction, states), orEnd = addState(1, states);
        addEdge(orBegin, block1.beginStateID, EPSILON, states);
        addEdge(orBegin, block2.beginStateID, EPSILON, states);
        addEdge(block1.endStateID, orEnd, EPSILON, states);
        addEdge(block2.endStateID, orEnd, EPSILON, states);
        resultBlock = {orBegin, orEnd};
    }
    else if (inputSymbol == '*') // 闭包
    {
        states[block1.endStateID].isAccepting = 0;
        int closureBegin = addState(0, NullAction, states), closureEnd = addState(1, states);
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
    return resultBlock;
}
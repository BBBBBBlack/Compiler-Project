#include "NFA.hpp"

FAStateBlock NFA::regexToBlock(std::string regex, FAStateVec &states)
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
            // 直连
            // alphabet.insert(regexWithSuffix[i] + "");
            alphabet.insert(std::string(1, regexWithSuffix[i]));
            // symbolTable[regexWithSuffix[i] + ""] = true; // 记录符号
            blockStack.push({addState(0, states), addState(1, states)});
            addEdge(blockStack.top().beginStateID, blockStack.top().endStateID, regexWithSuffix[i], states);
        }
    }
    return blockStack.top();
}

void NFA::buildNFA(RegexVec regexVec)
{
    this->regexVec = regexVec;
    int allBegin = addState(0, states);
    for (auto &regex : regexVec)
    {
        FAStateBlock block = regexToBlock(regex, states);
        addEdge(allBegin, block.beginStateID, EPSILON, states);
    }
    startStateID = allBegin;

    if (debugMode)
    {
        *outFile << std::endl
                 << "## 字母表" << std::endl;
        for (auto &letter : alphabet)
        {
            *outFile << letter << " ";
        }
        *outFile << std::endl;
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
        alphabet.insert(inputSymbol + "");
        int s1 = addState(0, states), s2 = addState(1, states);
        addEdge(s1, s2, inputSymbol, states);
        resultBlock = {s1, s2};
    }
    return resultBlock;
}
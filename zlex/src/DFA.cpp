#include "DFA.hpp"
#include "struct.hpp"

/**
 * @brief 获取一个状态的epsilon闭包
 * @param stateID 状态ID
 * @param visited 访问标记(用于避免重复访问)
 */
StateSet DFA::epsilonClosure(int stateID, std::unordered_map<int, bool> &visited, FAStateVec &states)
{
    std::stack<int> stateStack;
    stateStack.push(stateID);
    StateSet result;
    while (!stateStack.empty())
    {
        int stateID = stateStack.top();
        stateStack.pop();
        result.set.insert(stateID);
        visited[stateID] = true;
        for (auto &epsilonTrans : states[stateID].epsilonTrans)
        {
            if (visited.find(epsilonTrans) == visited.end())
            {
                stateStack.push(epsilonTrans);
                result.isAccepting = result.isAccepting || states[epsilonTrans].isAccepting;
                visited[epsilonTrans] = true;
            }
        }
    }
    return result;
}

/**
 * @brief 获取一个状态集的epsilon闭包
 * @param stateSet 状态集
 * @param visited 访问标记(用于避免重复访问)
 */
StateSet DFA::epsilonClosure(StateSet stateSet, std::unordered_map<int, bool> &visited, FAStateVec &states)
{
    // TODO 空闭包是否需要加入自身?
    StateSet result = stateSet;
    for (auto &stateID : stateSet.set)
    {
        StateSet closure = epsilonClosure(stateID, visited, states);
        result.set.insert(closure.set.begin(), closure.set.end());
        result.isAccepting = result.isAccepting || closure.isAccepting;
    }
    return result;
}

/**
 * @brief 获取一个状态集的转移闭包
 * @param stateSet 状态集
 * @param symbol 转移条件
 */
StateSet DFA::move(StateSet stateSet, std::string symbol, FAStateVec &states)
{
    StateSet result;
    // 遍历状态集
    for (auto &stateID : stateSet.set)
    {
        // 查看当前状态是否有symbol转移
        if (states[stateID].trans.find(symbol) != states[stateID].trans.end())
        {
            int nextStateID = states[stateID].trans[symbol];
            result.set.insert(nextStateID);
            result.isAccepting = result.isAccepting || states[nextStateID].isAccepting;
        }
    }
    return result;
}

void DFA::printDFATransTableHeader()
{
    *outputFile << std::endl
                << "## NFA->DFA(子集构造)" << std::endl;
    *outputFile << "|原NFA集合|";
    for (auto &symbol : alphabet)
    {
        *outputFile << symbol << "|";
    }
    *outputFile << std::endl;
    // 打印分隔线
    *outputFile << "|---|";
    for (auto &symbol : alphabet)
    {
        *outputFile << "---|";
    }
    *outputFile << std::endl;
    outputFile->flush();
}

/**
 * @brief 将states中的NFA转换为DFA
 */
void DFA::buildDFA(NFA &nfa)
{
    if (debugMode)
        printDFATransTableHeader();

    std::unordered_set<StateSet, StateSetHash, StateSetEqual> visitedSet;
    std::queue<StateSet> stateSetQueue;

    StateSet startStateSet = epsilonClosure(nfa.startStateID, nfa.states);
    // 初始NFA状态集->DFA状态
    startStateSet.stateID = addState(startStateSet.isAccepting, states);
    startStateID = startStateSet.stateID;

    // 开始递归 生成DFA
    stateSetQueue.push(startStateSet);
    while (!stateSetQueue.empty())
    {
        // 获取当前状态集
        StateSet currentStateSet = stateSetQueue.front();
        stateSetQueue.pop();

        // 跳过已访问的状态集
        if (visitedSet.find(currentStateSet) != visitedSet.end())
            continue;

        visitedSet.insert(currentStateSet);

        if (debugMode)
        {
            *outputFile << "|" << currentStateSet << "|";
        }

        for (auto &symbol : alphabet)
        {
            // TODO 生成的nextStateSet的StateID从何而来
            StateSet nextStateSet = epsilonClosure(move(currentStateSet, symbol, nfa.states), nfa.states);
            // 跳过空集
            if (nextStateSet.set.size() == 0)
            {
                if (debugMode)
                    *outputFile << EMPTY_SET << "|";
                continue;
            }

            // 检查是否为新生成的集合(DFA状态)
            if (visitedSet.find(nextStateSet) == visitedSet.end())
            {
                // visitedSet.insert(nextStateSet);
                nextStateSet.stateID = addState(nextStateSet.isAccepting, states);
                stateSetQueue.push(nextStateSet);
            }
            else
            {
                // 重复状态集
                // NOTE: 否则StateID会因为epsilonClosure生成出错
                nextStateSet = *visitedSet.find(nextStateSet);
            }

            if (debugMode)
            {
                *outputFile << nextStateSet << "|";
            }
            // 为新生成的状态集(DFA状态)添加转移(边)
            addEdge(currentStateSet.stateID, nextStateSet.stateID, symbol, states);
        }

        if (debugMode)
            *outputFile << std::endl;
    }
}
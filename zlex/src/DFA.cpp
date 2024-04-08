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
    // std::chrono::duration<double> epsilonClosureTime;

    StateSet::Hash hasher;
    if (debugMode)
    {
        printDFATransTableHeader();
    }

    std::unordered_set<StateSet, StateSet::Hash, StateSet::Equal> visitedSet;
    std::unordered_set<StateSet, StateSet::Hash, StateSet::Equal> createdSet;
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
        // std::cout << visitedSet.size() << std::endl;

        if (debugMode)
        {
            *outputFile << "|" << currentStateSet << "|";
        }

        for (auto &symbol : alphabet)
        {
            // auto start = std::chrono::high_resolution_clock::now();
            // TODO 生成的nextStateSet的StateID从何而来
            // TODO 每次都要重新计算epsilonClosure, 有没有更好的办法?
            StateSet nextStateSet = epsilonClosure(move(currentStateSet, symbol, nfa.states), nfa.states);

            // auto end = std::chrono::high_resolution_clock::now();
            // epsilonClosureTime += end - start;

            // 跳过空集
            if (nextStateSet.set.size() == 0)
            {
                if (debugMode)
                    *outputFile << EMPTY_SET << "|";
                continue;
            }

            // 检查是否为新生成的集合(DFA状态)
            // error: nextStateSet只有当它从queue中取出后, 才会被加入visitedSet
            // if (visitedSet.find(nextStateSet) == visitedSet.end())
            if (createdSet.find(nextStateSet) == createdSet.end())
            {
                // visitedSet.insert(nextStateSet);
                nextStateSet.stateID = addState(nextStateSet.isAccepting, states);
                // 设置action和note
                setActionAndNote(nextStateSet.stateID, nextStateSet, nfa.states);
                createdSet.insert(nextStateSet);
                stateSetQueue.push(nextStateSet);
            }
            else
            {
                nextStateSet = *createdSet.find(nextStateSet);
            }

            if (debugMode)
            {
                // bool visited = (visitedSet.find(nextStateSet) != visitedSet.end());
                // *outputFile << "HASH:" << hasher(nextStateSet) << ","
                //             << "visited:" << visited << ", "
                //             << "size:" << visitedSet.size()
                //             << "<br>";
                *outputFile << nextStateSet << "|";
            }
            // 为新生成的状态集(DFA状态)添加转移(边)
            addEdge(currentStateSet.stateID, nextStateSet.stateID, symbol, states);
        }

        if (debugMode)
            *outputFile << std::endl;
    }

    // std::cout << "epsilonClosureTime: " << epsilonClosureTime.count() << "s" << std::endl;
}

void DFA::setActionAndNote(int dfaStateID, StateSet &stateSet, FAStateVec &nfaStates)
{
    if (!stateSet.isAccepting)
        return;

    // 查找NFA中priority最小的状态
    int minPriority = INT_MAX;
    int minPriorityStateID = -1;
    for (auto &stateID : stateSet.set)
    {
        if (!nfaStates[stateID].isAccepting) // 跳过非终态
            continue;
        if (nfaStates[stateID].priority < minPriority)
        {
            minPriority = nfaStates[stateID].priority;
            minPriorityStateID = stateID;
        }
    }

    // 设置action和note
    states[dfaStateID].action = nfaStates[minPriorityStateID].action;
    states[dfaStateID].priority = nfaStates[minPriorityStateID].priority;
    states[dfaStateID].note = nfaStates[minPriorityStateID].note;
}
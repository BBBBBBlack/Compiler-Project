#ifndef SEMANTIC_STRUCT_HPP
#define SEMANTIC_STRUCT_HPP

#include "pch.hpp"

class Instruction
{
};

/**
 * @brief 回填中用到的控制流指令跳转列表
 */
class JumpList
{
public:
    static JumpList *merge(JumpList *list1, JumpList *list2);
    void backpatch(int jumpTo);

private:
    int jumpTo;
    std::vector<Instruction> instructionVec;
};

#endif // !SEMANTIC_STRUCT_HPP
#include "SemanticStruct.hpp"

JumpList *JumpList::makeList(int jumpTo, Quaternion instruction)
{
    JumpList *list = new JumpList();
    list->instructionVec.push_back(instruction);
    list->jumpTo = jumpTo;
    return list;
}

JumpList *JumpList::merge(JumpList *list1, JumpList *list2)
{
    JumpList *list = new JumpList();
    list->instructionVec.insert(list->instructionVec.end(), list1->instructionVec.begin(), list1->instructionVec.end());
    list->instructionVec.insert(list->instructionVec.end(), list2->instructionVec.begin(), list2->instructionVec.end());
    return list;
}

void JumpList::backpatch(int jumpTo)
{
    for (auto &i : instructionVec)
    {
        i.result = jumpTo;
    }
}
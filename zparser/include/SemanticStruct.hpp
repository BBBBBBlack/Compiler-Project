#ifndef SEMANTIC_STRUCT_HPP
#define SEMANTIC_STRUCT_HPP

#include "pch.hpp"

class Quaternion
{
public:
    enum Operation
    {
        ASSIGN, // x = y
        ADD,    // x = y + z
        SUB,    // x = y - z
        MUL,    // x = y * z
        DIV,    // x = y / z
        // TODO: 一元运算符
        UNARY_OP,         // x = op y
        ARRAY_ASSIGN_YI,  // x = y[i]
        ARRAY_ASSIGN_XI,  // x[i] = y
        ADDRESS_ASSIGN,   // x = &y
        POINTER_ASSIGN_Y, // x = *y
        POINTER_ASSIGN_X, // *x = y
        GOTO,             // goto L
        IF_X_GOTO,        // if x goto L
        IF_FALSE_X_GOTO,  // if false x goto L
        IF_X_LT_Y_GOTO,   // if x < y goto L (Less Than)
        IF_X_LE_Y_GOTO,   // if x <= y goto L
        IF_X_EQ_Y_GOTO,   // if x == y goto L
        IF_X_NE_Y_GOTO,   // if x != y goto L
        IF_X_GT_Y_GOTO,   // if x > y goto L
        IF_X_GE_Y_GOTO,   // if x >= y goto L
        PARAM,            // param x
        PROC_CALL,        // call p, n
        FUNC_CALL         // y = call p, n
    };

    std::unordered_map<Operation, std::string> opMap = {
        {ASSIGN, "="},
        {ADD, "+"},
        {SUB, "-"},
        {MUL, "*"},
        {DIV, "/"},
        {UNARY_OP, "op"},
        {ARRAY_ASSIGN_YI, "= *"},
        {ARRAY_ASSIGN_XI, "* ="},
        {ADDRESS_ASSIGN, "= &"},
        {POINTER_ASSIGN_Y, "= *"},
        {POINTER_ASSIGN_X, "* ="},
        {GOTO, "goto"},
        {IF_X_GOTO, "if"},
        {IF_FALSE_X_GOTO, "if_false"},
        {IF_X_LT_Y_GOTO, "if_lt"},
        {IF_X_LE_Y_GOTO, "if_le"},
        {IF_X_EQ_Y_GOTO, "if_eq"},
        {IF_X_NE_Y_GOTO, "if_ne"},
        {IF_X_GT_Y_GOTO, "if_gt"},
        {IF_X_GE_Y_GOTO, "if_ge"},
        {PARAM, "param"},
        {PROC_CALL, "call"},
        {FUNC_CALL, "=call"}};

    Quaternion(Operation op, std::string arg1, std::string arg2, std::string result) : op(op), arg1(arg1), arg2(arg2), result(result)
    {
    }

    Operation op;
    std::string arg1;
    std::string arg2;
    std::string result;

    std::string toString()
    {
        return "(" + opMap.at(op) + ", " + arg1 + ", " + arg2 + ", " + result + ")";
    }
};

/**
 * @brief 回填中用到的控制流指令跳转列表
 */
class JumpList
{
public:
    static JumpList *makeList(int jumpTo, Quaternion instruction);
    static JumpList *merge(JumpList *list1, JumpList *list2);
    void backpatch(int jumpTo);

private:
    int jumpTo;
    std::vector<Quaternion> instructionVec;
};

#endif // !SEMANTIC_STRUCT_HPP
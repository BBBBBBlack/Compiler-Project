#include "SemanticStruct.hpp"

std::unordered_map<std::string, Quaternion::Operation> Quaternion::strOpMap = {
    {"=", ASSIGN},
    {"+", ADD},
    {"-", SUB},
    {"*", MUL},
    {"/", DIV},
    {"op", UNARY_OP},
    {"=[]", ARRAY_ASSIGN_YI},
    {"[]=", ARRAY_ASSIGN_XI},
    {"= &", ADDRESS_ASSIGN},
    {"=*", POINTER_ASSIGN_Y},
    {"*=", POINTER_ASSIGN_X},
    {"goto", GOTO},
    {"if", IF_X_GOTO},
    {"if_false", IF_FALSE_X_GOTO},
    {"if_lt", IF_X_LT_Y_GOTO},
    {"if_le", IF_X_LE_Y_GOTO},
    {"if_eq", IF_X_EQ_Y_GOTO},
    {"if_ne", IF_X_NE_Y_GOTO},
    {"if_gt", IF_X_GT_Y_GOTO},
    {"if_ge", IF_X_GE_Y_GOTO},
    {"param", PARAM},
    {"call", PROC_CALL},
    {"=call", FUNC_CALL},
    {"(int)", TYPE_TRANSFER_INT},
    {"(float)", TYPE_TRANSFER_FLOAT}

};

std::unordered_map<Quaternion::Operation, std::string> Quaternion::opStrMap = {
    {ASSIGN, "="},
    {ADD, "+"},
    {SUB, "-"},
    {MUL, "*"},
    {DIV, "/"},
    {UNARY_OP, "op"},
    {ARRAY_ASSIGN_YI, "=[]"},
    {ARRAY_ASSIGN_XI, "[]="},
    {ADDRESS_ASSIGN, "= &"},
    {POINTER_ASSIGN_Y, "=*"},
    {POINTER_ASSIGN_X, "*="},
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
    {FUNC_CALL, "=call"},
    {TYPE_TRANSFER_INT, "(int)"},
    {TYPE_TRANSFER_FLOAT, "(float)"}};
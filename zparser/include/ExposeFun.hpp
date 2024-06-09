#ifndef EXPOSE_FUN_HPP
#define EXPOSE_FUN_HPP

#include "pch.hpp"
#include "Parser.hpp"

ParseTab tab;
Parser parser(tab);

int nextinstr = parser.nextinstr;
// 生成四元式 返回四元式的标号
TokenType gen(Quaternion::Operation op, std::string arg1, std::string arg2, std::string result)
{
    return parser.gen(op, arg1, arg2, result);
}
TokenType gen(Quaternion::Operation op, std::string arg1, std::string arg2)
{
    return parser.gen(op, arg1, arg2);
}
TokenType gen(Quaternion::Operation op, std::string arg)
{
    return parser.gen(op, arg);
}
TokenType makeList(int instrId)
{
    return parser.makeList(instrId);
}
TokenType makeList(TokenType instrId)
{
    return parser.makeList(instrId);
}
TokenType mergeList(TokenType jumpListId1, TokenType jumpListId2)
{
    return parser.mergeList(jumpListId1, jumpListId2);
}
void backPatch(TokenType jumpListId, int jumpTo)
{
    parser.backPatch(jumpListId, jumpTo);
}

#endif // EXPOSE_FUN_HPP
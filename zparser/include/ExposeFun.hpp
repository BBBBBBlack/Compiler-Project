#ifndef EXPOSE_FUN_HPP
#define EXPOSE_FUN_HPP

#include "pch.hpp"
#include "Parser.hpp"

extern ParseTab tab;
extern Parser parser;
extern int &nextinstr;

// 生成四元式 返回四元式的标号
TokenType gen(Quaternion::Operation op, std::string arg1, std::string arg2, std::string result);
TokenType gen(Quaternion::Operation op, std::string arg1, std::string arg2);
TokenType gen(Quaternion::Operation op, std::string arg);
TokenType makeList(int instrId);
TokenType makeList(TokenType instrId);
TokenType mergeList(TokenType jumpListId1, TokenType jumpListId2);

void backPatch(TokenType jumpListId, std::string jumpTo);
void backPatch(TokenType jumpListId, int jumpTo);

#endif // EXPOSE_FUN_HPP
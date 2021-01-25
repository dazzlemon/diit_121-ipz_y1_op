#ifndef __INFIXPARSER_H__
#define __INFIXPARSER_H__

#include <vector>
#include "BigInt.h"

//tokens separated by whitespaces//coverts infix token vector to postfix
std::vector<std::string> infixToRPN(const std::vector<std::string>& infix);

//evaluates postfix token vector
BigInt RPNevaluation(const std::vector<std::string>& RPNtokenStack);

//converts infix string to vector of tokens in order
std::vector<std::string> infixStrToInfixVec(std::string infixStr);

//returns true if input is good, else - false,result contains result of evaluation or commentary about bad input
bool parse(const std::string& infix, std::string& result);

void calculator();

#endif
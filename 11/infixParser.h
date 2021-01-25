#ifndef __INFIXPARSER_H__
#define __INFIXPARSER_H__

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <map>
#include <regex>
#include "BigInt.h"

//tokens separated by whitespace
std::vector<std::string> infixToRPN(const std::vector<std::string>& infix) {
    std::map<std::string, int> operatorPrecendence{
        {"+", 2},
        {"-", 2},
        {"/", 3},
        {"*", 3}
    };
    std::vector<std::string> operatorStack;
    std::string token;
    std::vector<std::string> RPN;

    std::regex integer("^([+-]?[0-9]|([1-9][0-9]*))$");//^0$|^[1-9][0-9]*$

    enum state {expectOperator, expectOperand}currentState = expectOperand;
    bool continue_ = true;

    for (int i = 0; i < infix.size() &&  continue_; i++) {//while there are tokens to be read
        token = infix[i];//read a token
        if (std::regex_match(token, integer)) {//token is integer
            if (currentState != expectOperand) {
                RPN.clear();
                RPN.push_back(" syntax error");
                continue_ = false;//return error
            }
            else {
                RPN.push_back(token);
                currentState = expectOperator;
            }
        }
        else if (operatorPrecendence.count(token)) {//token is operator
            if (currentState != expectOperator) {
                RPN.clear();
                RPN.push_back(" syntax error");
                continue_ = false;//return error
            }
            else {
                //operator with bigger precendence on top of the operator stack, or operator on top of the stack is not "("
                while ((operatorStack.size() > 0) && operatorStack.back() != "(" && (operatorPrecendence.at(token) <= operatorPrecendence.at(operatorStack.back()))) {
                    RPN.push_back(operatorStack.back()); operatorStack.pop_back();
                }
                operatorStack.push_back(token);
                currentState = expectOperand;
            }
        }
        else if (token == "(")
            if (currentState != expectOperand) {
                RPN.clear();
                RPN.push_back(" syntax error");
                continue_ = false;//return error
            }
            else {
                operatorStack.push_back(token);
                //state remains the same
            }
        else if (token == ")") {
            if (currentState != expectOperator) {
                RPN.clear();
                RPN.push_back(" syntax error");
                continue_ = false;//return error
            }
            else {
                while (operatorStack.size() > 0 && operatorStack.back() != "(") {//check if can find "("
                    RPN.push_back(operatorStack.back()); operatorStack.pop_back();
                }
                if (operatorStack.size() > 0)//just in case
                    operatorStack.pop_back();//discarding "("
                else {
                    RPN.clear();
                    RPN.push_back("error, mismatched parenthesis");
                    continue_ = false;//return error
                }
                //state remains the same
            }
        }
    }
    while (operatorStack.size() > 0 && continue_) {
        if (operatorStack.back() == "(" || operatorStack.back() == ")") {
            RPN.clear();
            RPN.push_back("error, mismatched parenthesis");
            continue_ = false;//return error
        }
        else
            RPN.push_back(operatorStack.back()); operatorStack.pop_back();
    }
    return RPN;
}

BigInt RPNevaluation(const std::vector<std::string>& RPNtokenStack) {//make pre validation
    std::vector<BigInt> operandStack;
    std::string token;

    std::regex integer("^([+-]?[0-9]|([1-9][0-9]*))$");//^0$|^[1-9][0-9]*$

    for (int i = 0; i < RPNtokenStack.size(); i++) {//while tokens available
        token = RPNtokenStack[i];
        if (std::regex_match(token, integer))//std::stringstream(token) >> integerToken)//token is integer
            operandStack.push_back(token);
        else {//token is operator
            BigInt operand1 = operandStack.back(); operandStack.pop_back();
            BigInt operand2 = operandStack.back(); operandStack.pop_back();
            if (token == "*")
                operandStack.push_back(operand2 * operand1);
            else if (token == "/")
                operandStack.push_back(operand2 / operand1);
            else if (token == "-")
                operandStack.push_back(operand2 - operand1);
            else if (token == "+")
                operandStack.push_back(operand2 + operand1);
        }
    }
    return operandStack.back();
}

std::vector<std::string> infixStrToInfixVec(std::string infixStr) {
    std::map<std::string, int> operatorPrecendence{
        {"+", 2},
        {"-", 2},
        {"/", 3},
        {"*", 3},
        {"(", 0},
        {")", 0}
    };

    std::stringstream tokenBuffer;
    std::vector<std::string> tokenStack;

    std::regex integer("^([+-]?[0-9]|([1-9][0-9]*))$");//^0$|^[1-9][0-9]*$ make perfect regex

    bool continue_= true;

    for (int i = 0; i < infixStr.size() && continue_; i++) {
        if (infixStr[i] == ' ') {
            tokenStack.push_back(tokenBuffer.str());
            tokenBuffer.str("");
            if (!(std::regex_match(tokenStack.back(), integer) || operatorPrecendence.count(tokenStack.back()))) {//if token isnt operator or integer
                std::string tmp;
                if (tokenStack.back() == " " || tokenStack.back().empty())
                    tmp = " too many spaces";
                else
                    tmp = " " + tokenStack.back() + " is bad token";//to know which one is bad
                tokenStack.clear();
                tokenStack.push_back(tmp);
                continue_ = false;
            }
        }
        else {
                tokenBuffer << infixStr[i];
        }
    }
    if (!tokenBuffer.str().empty() && continue_) {
        tokenStack.push_back(tokenBuffer.str());
        tokenBuffer.str("");
        if (!(std::regex_match(tokenStack.back(), integer) || operatorPrecendence.count(tokenStack.back()))) {//if token isnt operator or integer
            std::string tmp;
            if (tokenStack.back() == " " || tokenStack.back().empty())
                tmp = " too many spaces";
            else
                tmp = " " + tokenStack.back() + " is bad token";//to know which one is bad
            tokenStack.clear();
            tokenStack.push_back(tmp);
            continue_ = false;
        }
    }
    return tokenStack;
}

//returns true if input is good, else - false,result contains result of evaluation or commentary about bad input
bool parse(const std::string& infix, std::string& result) {//true if good input
    std::regex integer("^([+-]?[0-9]|([1-9][0-9]*))$");
    bool ret;
    if (infix.empty()) {
        result = "empty string";
        ret = false;
    }
    else {
        std::vector<std::string> infixVec;// { "6", "*", "(", "12", "+", "18", ")", "-", "(", "52", "+", "7", ")", "/", "(", "9", "+", "13", ")" };
        infixVec = infixStrToInfixVec(infix);//infix string to infix vector of tokens
        if (infixVec.size() == 1) {
            result = infixVec[0];
            if (std::regex_match(infixVec[0], integer))
                ret = true;
            else
                ret = false;
        }
        else if (!infixVec.empty()) {
            std::vector<std::string> postfix = infixToRPN(infixVec);//infix vector of tokens to postfix vetor of tokens
            if (postfix.size() == 1) {
                result = postfix[0];
                if (std::regex_match(postfix[0], integer))
                    ret = true;
                else
                    ret = false;
            }
            else if (!postfix.empty()) {
                result = BigIntToStr(RPNevaluation(postfix));//std::cout << " = " << BigIntToStr(RPNevaluation(postfix)) << std::endl;//evaluate postfix
                ret = true;
            }
            else
                ret = false;
        }
        else
            ret = false;
    }
    return ret;
}

#endif
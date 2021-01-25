#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <map>

std::string infixToRPN(const std::string& infix) {
    std::map<std::string, int> operatorPrecendence{
        {"+", 2},
        {"-", 2},
        {"/", 3},
        {"*", 3},
        {"%", 3}
    };
    std::stringstream infixStream(infix);
    std::vector<std::string> operatorStack;
    std::string token;
    std::stringstream RPN;
    while (infixStream >> token) {//token queue !empty ->> read token
        int integerToken;
        if (std::stringstream(token) >> integerToken)//token is integer
            RPN << integerToken << ' ';
        if (operatorPrecendence.count(token)) {//token is operator
            while ((operatorStack.size() > 0) && operatorStack.back() != "(" && (operatorPrecendence.at(token) < operatorPrecendence.at(operatorStack.back()))) {
                RPN << operatorStack.back() << ' '; operatorStack.pop_back();
            }
            operatorStack.push_back(token);
        }
        if (token == "(")
            operatorStack.push_back(token);
        if (token == ")") {
            while (operatorStack.size() > 0 && operatorStack.back() != "(") {//check if can find "("
                RPN << operatorStack.back() << ' '; operatorStack.pop_back();
            }
            if(operatorStack.size() > 0)//just in case
                operatorStack.pop_back();//discarding "("
        }
    }
    while (operatorStack.size() > 0) {
        RPN << operatorStack.back() << ' '; operatorStack.pop_back();
    }
    return RPN.str();
}

int RPNevaluation(const std::string& RPN) {//make pre validation
    std::stringstream RPNstream(RPN);
    std::vector<int> operandStack;
    std::string token;
    while (RPNstream >> token) {
        int integerToken;
        if (std::stringstream(token) >> integerToken)//token is integer
            operandStack.push_back(integerToken);
        else {//token is operator
            int operand1 = operandStack.back(); operandStack.pop_back();
            int operand2 = operandStack.back(); operandStack.pop_back();
            if (token == "*")
                operandStack.push_back(operand2 * operand1);
            else if (token == "/")
                operandStack.push_back(operand2 / operand1);
            else if (token == "-")
                operandStack.push_back(operand2 - operand1);
            else if (token == "+")
                operandStack.push_back(operand2 + operand1);
            else if (token == "%")
                operandStack.push_back(operand2 % operand1);
        }
    }
    return operandStack.back();
}

std::string insertSpaces(std::string& str) {//to convert abc to a b c("eg [9+13/(17-1)] to [9 + 13 / 9 ( 17 - 1 )]")
    std::map<std::string, int> operatorPrecendence{//make better
        {"+", 2},
        {"-", 2},
        {"/", 3},
        {"*", 3},
        {"%", 3},
        {"(", 0},
        {")", 0}
    };
    std::stringstream newStr;
    for (auto i : str) {
        std::string temp(1, i);
        if (operatorPrecendence.count(temp))
            newStr << ' ' << i << ' ';
        else
            newStr << i;
    }
    return newStr.str();
}

int main() {
    std::string infix;// = "6*(12+18)-(52+7)/(9+13)";
    std::cout << "input math expression:" << std::endl;
    std::getline(std::cin, infix);
    //delete spaces
    infix = insertSpaces(infix);
    std::cout << " = " << RPNevaluation(infixToRPN(infix)) << std::endl;
    return 0;
}
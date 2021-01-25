//This app is basic arbitrary precision integer only calculator
//input is infix expression with tokens separated by single whitespace
//tokens are:
//  operators:
//    + addition
//    - substraction
//    * multiplication
//    / division
//    unary + - are allowed but only for constants(eg -101, +0, etc)
//  operands:
//    optional +-, can start from 0 if its the only digit, base10

#include "infixParser.h"
#include "tests.h"

int main() {
    //operatorPlusTest();
    //operatorMinusTest();
    //operatorMultiplyTest();
    //operatorDivisionTest();
    //parserTest();

    calculator();

    return 0;
}
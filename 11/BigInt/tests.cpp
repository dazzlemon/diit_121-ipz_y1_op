#include "tests.h"
#include "BigInt.h"
#include "infixParser.h"
#include <iostream>

void operatorPlusTest() {

    std::cout << "OPERATOR+" << std::endl;
    BigInt arbitraryNumber1, arbitraryNumber2;

    std::cout << "+ + |a|>|b| :\t";
    arbitraryNumber1 = "6945292007472";
    arbitraryNumber2 = "987654321";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "+ + |a|<|b| :\t";
    arbitraryNumber1 = "987654321";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "+ - |a|>|b| :\t";
    arbitraryNumber1 = "6945292007472";
    arbitraryNumber2 = "-987654321";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "+ - |a|<|b| :\t";
    arbitraryNumber1 = "987654321";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "+ +0 :\t\t";
    arbitraryNumber1 = "987654321";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "+ -0 :\t\t";
    arbitraryNumber1 = "987654321";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    //

    std::cout << "- + |a|>|b| :\t";
    arbitraryNumber1 = "-6945292007472";
    arbitraryNumber2 = "987654321";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "- + |a|<|b| :\t";
    arbitraryNumber1 = "-987654321";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "- - |a|>|b| :\t";
    arbitraryNumber1 = "-6945292007472";
    arbitraryNumber2 = "-987654321";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "- - |a|<|b| :\t";
    arbitraryNumber1 = "-987654321";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "- +0 :\t\t";
    arbitraryNumber1 = "-987654321";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "- -0 :\t\t";
    arbitraryNumber1 = "-987654321";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t + \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    //
    std::cout << "+0 + :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "+0 - :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "+0 +0 :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t + \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "+0 -0 :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t + \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    //

    std::cout << "-0 + :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "-0 - :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t + \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "-0 +0 :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t + \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "-0 -0 :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t + \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;

    std::cout << "single NaN test:";
    BigInt NaN;
    arbitraryNumber1 = NaN;
    arbitraryNumber2 = "987";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t + \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 + arbitraryNumber2) << std::endl;
}

void operatorMinusTest() {
    std::cout << "OPERATOR-" << std::endl;

    BigInt arbitraryNumber1, arbitraryNumber2;

    std::cout << "+ + |a|>|b| :\t";
    arbitraryNumber1 = "6945292007472";
    arbitraryNumber2 = "987654321";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "+ + |a|<|b| :\t";
    arbitraryNumber1 = "987654321";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "+ - |a|>|b| :\t";
    arbitraryNumber1 = "6945292007472";
    arbitraryNumber2 = "-987654321";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "+ - |a|<|b| :\t";
    arbitraryNumber1 = "987654321";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "+ +0 :\t\t";
    arbitraryNumber1 = "987654321";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "+ -0 :\t\t";
    arbitraryNumber1 = "987654321";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    //

    std::cout << "- + |a|>|b| :\t";
    arbitraryNumber1 = "-6945292007472";
    arbitraryNumber2 = "987654321";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "- + |a|<|b| :\t";
    arbitraryNumber1 = "-987654321";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "- - |a|>|b| :\t";
    arbitraryNumber1 = "-6945292007472";
    arbitraryNumber2 = "-987654321";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "- - |a|<|b| :\t";
    arbitraryNumber1 = "-987654321";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "- +0 :\t\t";
    arbitraryNumber1 = "-987654321";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "- -0 :\t\t";
    arbitraryNumber1 = "-987654321";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t - \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    //
    std::cout << "+0 + :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "+0 - :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "+0 +0 :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t - \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "+0 -0 :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t - \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    //

    std::cout << "-0 + :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "-0 - :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t - \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "-0 +0 :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t - \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "-0 -0 :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t - \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "single NaN test:";
    BigInt NaN;
    arbitraryNumber1 = NaN;
    arbitraryNumber2 = "987";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t - \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;

    std::cout << "a = b:\t\t";
    arbitraryNumber1 = arbitraryNumber2;
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t - \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 - arbitraryNumber2) << std::endl;
}

void operatorMultiplyTest() {
    std::cout << "OPERATOR*" << std::endl;

    BigInt arbitraryNumber1, arbitraryNumber2;

    std::cout << "+ + |a|>|b| :\t";
    arbitraryNumber1 = "6945292007472";
    arbitraryNumber2 = "987";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "+ + |a|<|b| :\t";
    arbitraryNumber1 = "987";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "+ - |a|>|b| :\t";
    arbitraryNumber1 = "6945292007472";
    arbitraryNumber2 = "-987";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "+ - |a|<|b| :\t";
    arbitraryNumber1 = "987";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "+ +0 :\t\t";
    arbitraryNumber1 = "987";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "+ -0 :\t\t";
    arbitraryNumber1 = "987";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    //

    std::cout << "- + |a|>|b| :\t";
    arbitraryNumber1 = "-6945292007472";
    arbitraryNumber2 = "987";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "- + |a|<|b| :\t";
    arbitraryNumber1 = "-987";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "- - |a|>|b| :\t";
    arbitraryNumber1 = "-6945292007472";
    arbitraryNumber2 = "-987";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "- - |a|<|b| :\t";
    arbitraryNumber1 = "-987";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "- +0 :\t\t";
    arbitraryNumber1 = "-987";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "- -0 :\t\t";
    arbitraryNumber1 = "-987";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    //
    std::cout << "+0 + :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "+0 - :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "+0 +0 :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "+0 -0 :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    //

    std::cout << "-0 + :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "-0 - :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "-0 +0 :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "-0 -0 :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;

    std::cout << "single NaN test:";
    BigInt NaN;
    arbitraryNumber1 = NaN;
    arbitraryNumber2 = "987";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t * \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 * arbitraryNumber2) << std::endl;
}

void operatorDivisionTest() {
    std::cout << "OPERATOR/" << std::endl;

    BigInt arbitraryNumber1, arbitraryNumber2;

    std::cout << "+ + |a|>|b| :\t";
    arbitraryNumber1 = "6945292007472";
    arbitraryNumber2 = "694529200";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "+ + |a|<|b| :\t";
    arbitraryNumber1 = "694529200";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "+ - |a|>|b| :\t";
    arbitraryNumber1 = "6945292007472";
    arbitraryNumber2 = "-694529200";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "+ - |a|<|b| :\t";
    arbitraryNumber1 = "694529200";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "+ +0 :\t\t";
    arbitraryNumber1 = "694529200";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "+ -0 :\t\t";
    arbitraryNumber1 = "694529200";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    //

    std::cout << "- + |a|>|b| :\t";
    arbitraryNumber1 = "-6945292007472";
    arbitraryNumber2 = "694529200";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "- + |a|<|b| :\t";
    arbitraryNumber1 = "-694529200";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "- - |a|>|b| :\t";
    arbitraryNumber1 = "-6945292007472";
    arbitraryNumber2 = "-694529200";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "- - |a|<|b| :\t";
    arbitraryNumber1 = "-694529200";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "- +0 :\t\t";
    arbitraryNumber1 = "-694529200";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "- -0 :\t\t";
    arbitraryNumber1 = "-694529200";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t / \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    //
    std::cout << "+0 + :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "+0 - :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "+0 +0 :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t / \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "+0 -0 :\t\t";
    arbitraryNumber1 = "0";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t / \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    //

    std::cout << "-0 + :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "-0 - :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "-6945292007472";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t / \t" << BigIntToStr(arbitraryNumber2) << "\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "-0 +0 :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t / \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "-0 -0 :\t\t";
    arbitraryNumber1 = "-0";
    arbitraryNumber2 = "-0";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t / \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;

    std::cout << "single NaN test:";
    BigInt NaN;
    arbitraryNumber1 = NaN;
    arbitraryNumber2 = "987";
    std::cout << BigIntToStr(arbitraryNumber1) << "\t\t / \t" << BigIntToStr(arbitraryNumber2) << "\t\t = \t" << BigIntToStr(arbitraryNumber1 / arbitraryNumber2) << std::endl;
}

void parserTest() {
    std::vector<std::string> tests{
    "2 + 3",
    "2 * 3",
    "89",
    "",
    "12  - 4",
    "12-4",
    "2 * 3 - 4 * 5 + 6 / 3",
    "6 + c",
    "1 - abc",
    "5 + + 6",
    "5 / 0",
    "( 2 )",
    "5 + 2 * 3 - 1 + 7 * 8",
    "( ( ( 4 ) ) )",
    "( ( 4 )",
    "( 4 ) )"
    };
    for (auto expression : tests) {
        std::string result;
        bool goodResult = parse(expression, result);
        std::cout << expression;
        if (goodResult)
            std::cout << " = " << result << std::endl;
        else
            std::cout << result << std::endl;
    }
}
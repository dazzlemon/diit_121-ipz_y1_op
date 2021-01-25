#ifndef __COMPUTING_H__
#define __COMPUTING_H__

#include <cmath>

// -1 < x < 1
double funcNormal(double x);
double funcIterative(double x, double epsilon);
double funcRecursive(double x, double epsilon, int n = 1);
double funcRecursiveTail(double x, double epsilon, int n = 1, double subResult = 0);

//x^n, just positive integer power
double myPowIterative(double x, int n);
double myPowRecursive(double x, int n);
double myPowRecursiveTail(double x, int n, double subResult = 1);

#endif

#ifndef __COMPUTING_H__
#define __COMPUTING_H__

// -1 < x < 1
double funcNormal(double x);
double funcIterative(double x, double epsilon);
double funcRecursive(double x, double epsilon, int n = 2, double newElement = 1);
double funcRecursiveTail(double x, double epsilon, int n = 2, double newElement = 1, double subResult = 0);
#endif
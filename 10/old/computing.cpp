#include "computing.h"

double funcNormal(double x) {
	return (1 / ((1 + x) * (1 + x)));
}

double funcIterative(double x, double epsilon) {
	double sum = 0, newElement = INT_MAX;
	for (int n = 1; abs(newElement) > epsilon; n++) {
		newElement = n * myPowIterative(-x, n - 1);
		sum += newElement;
	}
	return sum;
}

double funcRecursive(double x, double epsilon, int n) {
	double newElement = n * myPowRecursive(-x, n - 1);
	if(abs(newElement) < epsilon)
		return newElement;
	return newElement + funcRecursive(x, epsilon, n + 1);
}

double funcRecursiveTail(double x, double epsilon, int n, double subResult) {
	double newElement = n * myPowRecursiveTail(-x, n - 1);
	if (abs(newElement) < epsilon)
		return subResult + newElement;
	return funcRecursiveTail(x, epsilon, n + 1, subResult + newElement);
}

double myPowIterative(double x, int n) {
	double POW = 1;
	for (n; n > 0; n--)
		POW *= x;
	return POW;
}

double myPowRecursive(double x, int n) {
	if (n == 0)
		return 1;
	return x * myPowRecursive(x, n - 1);
}

double myPowRecursiveTail(double x, int n, double subResult) {
	if (n == 0)
		return subResult;
	return myPowRecursiveTail(x, n - 1, subResult * x);
}
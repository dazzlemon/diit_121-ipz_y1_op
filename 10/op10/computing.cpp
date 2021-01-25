#include "computing.h"
#include <cmath>

double funcNormal(double x) {
	return (1 / ((1 + x) * (1 + x)));
}

//n < 3000 to avoid stack overflow and/or infinite loop

double funcIterative(double x, double epsilon) {
	double sum = 0, oldElement = 0, newElement = 1;
	for (int n = 2; abs(oldElement - newElement) > epsilon && n < 3000; n++) {
		oldElement = newElement;
		sum += oldElement;
		newElement = oldElement * (-n * x / (n - 1.0));
	}
	return sum;
}

double funcRecursive(double x, double epsilon, int n, double newElement) {
	double oldElement = newElement;
	newElement *= (-n * x / (n - 1.0));
	if (abs(oldElement - newElement) <= epsilon || n > 3000)
		return oldElement;
	return oldElement + funcRecursive(x, epsilon, n + 1, newElement);
}

double funcRecursiveTail(double x, double epsilon, int n, double newElement, double subResult) {
	double oldElement = newElement;
	newElement *= (-n * x / (n - 1.0));
	if (abs(oldElement - newElement) <= epsilon || n > 3000)
		return subResult + oldElement;
	return funcRecursiveTail(x, epsilon, n + 1, newElement, subResult + oldElement);
}
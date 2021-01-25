#include <iostream>
#include "computing.h"

int main() {
    double x = 0.349, epsilon = 0.1;
    std::cout << "1/(1+x)^2, x = " << x << " epsilon = " << epsilon <<std::endl;
    
    std::cout << "cmath \t\t" << funcNormal(x) << std::endl;
    std::cout << "iterative \t" << funcIterative(x, epsilon) << std::endl;
    std::cout << "recursive \t" << funcRecursive(x, epsilon) << std::endl;
    std::cout << "recursive tail \t" << funcRecursiveTail(x, epsilon) << std::endl;

    return 0;
}

#include <iostream>
#include <iomanip>
#include "computing.h"
#include "inp_val7.h"
#include <cmath>

int main() {
    std::cout << "this app calculates (x+1)^-2 for x in range (-1; 1) using cmath header, iterative function, recursive function and tail recursive function" << std::endl;
    std::cout << std::fixed << std::setprecision(100);
    bool exit;
    do {
        double x , epsilon;
        x = cinum("input x in range (-1; 1): ", "wrong input, try again", 1, 0, std::nextafter(-1.0, 0.0), std::nextafter(1.0, 0.0));
        epsilon = cinum("input epsilon in range (0; 1): ", "wrong input, try again", 1, 0, std::nextafter(0.0, 1.0), std::nextafter(1.0, 0.0));

        std::cout << "1/(1+x)^2, x = \t" << x << std::endl;
        std::cout << "epsilon = \t" << epsilon << std::endl << std::endl;

        std::cout << "cmath \t\t" << funcNormal(x) << std::endl;
        std::cout << "iterative \t" << funcIterative(x, epsilon) << std::endl;
        std::cout << "recursive \t" << funcRecursive(x, epsilon) << std::endl;
        std::cout << "recursive tail \t" << funcRecursiveTail(x, epsilon) << std::endl << std::endl;

        char chExit;
        std::cout << "Do you want to exit the programm?(Y/N): ";
        std::cin >> chExit;
        while ((chExit != 'Y' && chExit != 'y' && chExit != 'N' && chExit != 'n') || (std::cin.peek() != '\n')) {//until correct input
            while (std::cin.get() != '\n');//clear istream
            std::cout << "wrong input, try again." << std::endl;
            std::cout << "Do you want to exit the programm?(Y/N): ";
            std::cin >> chExit;
        }
        if (chExit == 'Y' || chExit == 'y')
            exit = true;
        else
            exit = false;
        std::cin.get();//enter
    } while (!exit);

    return 0;
}
#include <iostream>
#include "conditionals.h"

int hackerrank::conditionals()
{
    int n = -1;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // This is an exercise specifically about the use of if/else but it
    // should be noted that a switch would be preferrable here and
    // the use of an array to map int indecies to strings would be
    // both more elegant and more efficient.

    if (n > 9) {
        std::cout << "Greater than 9";
    }
    else if (n == 1) {
        std::cout << "one";
    }
    else if (n == 2) {
        std::cout << "two";
    }
    else if (n == 3) {
        std::cout << "three";
    }
    else if (n == 4) {
        std::cout << "four";
    }
    else if (n == 5) {
        std::cout << "five";
    }
    else if (n == 6) {
        std::cout << "six";
    }
    else if (n == 7) {
        std::cout << "seven";
    }
    else if (n == 8) {
        std::cout << "eight";
    }
    else if (n == 9) {
        std::cout << "nine";
    }
    else {
        std::cout << "Less than 1";
    }
    std::cout << std::endl;
    return 0;
}

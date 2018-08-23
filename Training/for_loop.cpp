#include <iostream>
#include "for_loop.h"

int hackerrank::for_loop ()
{
    const char * const digit_names[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int a = -1, b = -1;
    std::cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (i > 9) {
            std::cout << (i % 2 ? "odd" : "even");
        }
        else if (i < 0) {
            std::cout << "Less than zero";
        }
        else {
            std::cout << digit_names[i];
        }
        std::cout << std::endl;
    }
    return 0;
}

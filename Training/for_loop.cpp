#include <iostream>
#include "for_loop.h"

int hackerrank::for_loop() {
    int a, b;
    std::cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (i > 9) {
            if (i % 2 == 1) {
                std::cout << "odd";
            }
            else {
                std::cout << "even";
            }
        }
        else if (i == 1) {
            std::cout << "one";
        }
        else if (i == 2) {
            std::cout << "two";
        }
        else if (i == 3) {
            std::cout << "three";
        }
        else if (i == 4) {
            std::cout << "four";
        }
        else if (i == 5) {
            std::cout << "five";
        }
        else if (i == 6) {
            std::cout << "six";
        }
        else if (i == 7) {
            std::cout << "seven";
        }
        else if (i == 8) {
            std::cout << "eight";
        }
        else if (i == 9) {
            std::cout << "nine";
        }
        else {
            std::cout << "Less than 1";
        }
        std::cout << std::endl;
    }
    return 0;
}
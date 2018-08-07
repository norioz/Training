#include <iostream>
#include "for_loop.h"

//Es- Consider a switch statement:
const char * digit_to_string(int i) {
    switch(i) {
        case  0: return "zero";       
        case  1: return "one";
        case  2: return "two";
        case  3: return "three";
        case  4: return "four";
        case  5: return "five";
        case  6: return "six";
        case  7: return "seven";
        case  8: return "eight";
        case  9: return "nine";
        default: return "Not a digit.";
    }    
}

//Es- Or more elegantly, an array.
 static const char * const digit_names[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int hackerrank::for_loop()
{
    int a, b;
    std::cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (i > 9) {
            std::cout << (i % 2 ? "odd" : "even"); //Es- Note: can inline w/a ternary here.
        }
        else if (i < 0) {
            std::cout << "Less than 1";            
        }
        else {
            std::cout << digit_to_string(i);
            // OR
            std::cout << digit_names[i];
        }
        std::cout << std::endl;
    }
    return 0;
}

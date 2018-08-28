#include <iostream>
#include <stdexcept>
#include "exception_handling.h"

// START HACKERRANK LOCKED CODE
using namespace std;

int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n / 2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}
// END HACKERRANK LOCKED CODE

void process_input (int n)
{
    try {
        int d = largest_proper_divisor(n);
        cout << "result=" << d << endl;
    }
    catch (invalid_argument e) {
        cout << e.what() << endl;
    }
    cout << "returning control flow to caller";
}

// START HACKERRANK LOCKED CODE
int hackerrank::exception_handling ()
{
    int n;
    cin >> n;
    process_input(n);
    return 0;
}
// END HACKERRANK LOCKED CODE

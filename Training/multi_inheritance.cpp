#include <iostream>
#include "multi_inheritance.h"

using namespace std;

// START HACKERRANK GIVEN CODE
class Triangle {
public:
    void triangle() {
        cout << "I am a triangle\n";
    }
};

class Isosceles : public Triangle {
public:
    void isosceles() {
        cout << "I am an isosceles triangle\n";
    }
};
// END HACKERRANK GIVEN CODE

class Equilateral : public Isosceles {
public:
    void equilateral() {
        cout << "I am an equilateral triangle\n";
    }
};

// START HACKERRANK GIVEN CODE
int hackerrank::multi_inheritance() {

    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
// END HACKERRANK GIVEN CODE

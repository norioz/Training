#include <iostream>
#include "inheritance.h"

// START HACKERRANK GIVEN CODE
using namespace std;

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
// END HACKERRANK GIVEN CODE
    void description()
    {
        cout << "In an isosceles triangle two sides are equal" << endl;
    }
};

int hackerrank::inheritance() 
{
    // START HACKERRANK GIVEN CODE
    Isosceles isc;
    isc.isosceles();
    isc.description();
    isc.triangle();
    return 0;
    // END HACKERRANK GIVEN CODE
}

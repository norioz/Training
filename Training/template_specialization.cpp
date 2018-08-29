#include <iostream>
#include "template_specialization.h"

using namespace std;

// START HACKERRANK LOCKED CODE
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;
// END HACKERRANK LOCKED CODE

const char * fruit_names[3] = { "apple", "orange", "pear" };
const char * color_names[3] = { "red", "green", "orange" };

template <>
class Traits <Fruit> {
public:
    static const char * name (unsigned int i)
    {
        return (i > 2 ? "unknown" : fruit_names[i]);
    }
};

template <>
class Traits <Color> {
public:
    static const char * name (unsigned int i) 
    { 
        return (i > 2 ? "unknown" : color_names[i]); 
    }
};

int hackerrank::template_specialization ()
{
    // START HACKERRANK LOCKED CODE
    int t = 0; std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
    // END HACKERRANK LOCKED CODE
    return 0;
}

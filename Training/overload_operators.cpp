#include <iostream>
#include <string>
#include "overload_operators.h"

using namespace std;

class Complex
{
public:
    int a = -1, b = -1;
    void input (string s)
    {
        int v1 = 0;
        unsigned int i = 0;
        while (s[i] != '+')
        {
            v1 = v1 * 10 + s[i] - '0';
            ++i;
        }
        while (s[i] == ' ' || s[i] == '+' || s[i] == 'i')
        {
            ++i;
        }
        int v2 = 0;
        while (i < s.length())
        {
            v2 = v2 * 10 + s[i] - '0';
            i++;
        }
        a = v1;
        b = v2;
    }
};

Complex operator+ (const Complex& c1, const Complex& c2)
{
    Complex result;
    result.a = c1.a + c2.a;
    result.b = c1.b + c2.b;
    return result;
}

ostream& operator<< (ostream& os, const Complex& c)
{
    os << c.a << "+i" << c.b;
    return os;
}

int hackerrank::overload_operators()
{
    // START HACKERRANK BOILER PLATE
    Complex x, y;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    cout << z << endl;
    return 0;
    // END HACKERRANK BOILER PLATE
}

#include <iostream>
#include "box_it.h"

using namespace std;

class Box {
private:
    int m_l = 0;  // length
    int m_b = 0;  // breadth
    int m_h = 0;  // height
public:
    Box () {}
    Box (int length, int breadth, int height) : m_l (length), m_b (breadth), m_h (height) {}
    Box (const Box & b) : Box (b.m_l, b.m_b, b.m_h) {}
    int getLength () const { return m_l; }
    int getBreadth () const { return m_b; }
    int getHeight () const { return m_h; }
    long long CalculateVolume () { return ((long long)m_l * m_b) * m_h; }
};

// Overload the operator < for the class Box. Box A < Box B if:
// A.l < B.l
// A.b < B.b and A.l == B.l
// A.h < B.h and A.b == B.b and A.l == B.l
bool operator< (const Box & a, const Box & b)
{
    int al = a.getLength(), bl = b.getLength(),
        ab = a.getBreadth(), bb = b.getBreadth(),
        ah = a.getHeight(), bh = b.getHeight();
    return al < bl
        || al == bl && ab < bb
        || al == bl && ab == bb && ah < bh;
}

// Overload operator << for the class Box().
// If B is an object of class Box :
// cout << B should print B.l, B.b, and B.h on a single line separated by
// spaces.
ostream & operator<< (ostream & os, Box & b)
{
    os << b.getLength() << " " << b.getBreadth() << " " << b.getHeight();
    return os;
}

int hackerrank::box_it () {
    // START HACKERRANK BOILER PLATE
    int n;
    cin >> n;
    Box temp;
    for (int i = 0;i<n;i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox<temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
    // END HACKERRANK BOILER PLATE
    return 0;
}

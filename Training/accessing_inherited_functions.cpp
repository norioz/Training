#include <iostream>
#include "accessing_inherited_functions.h"

using namespace std;

// START HACKERRANK LOCKED CODE
class A
{
public:
    A() {
        callA = 0;
    }
private:
    int callA;
    void inc() {
        callA++;
    }

protected:
    void func(int & a)
    {
        a = a * 2;
        inc();
    }
public:
    int getA() {
        return callA;
    }
};

class B
{
public:
    B() {
        callB = 0;
    }
private:
    int callB;
    void inc() {
        callB++;
    }
protected:
    void func(int & a)
    {
        a = a * 3;
        inc();
    }
public:
    int getB() {
        return callB;
    }
};

class C
{
public:
    C() {
        callC = 0;
    }
private:
    int callC;
    void inc() {
        callC++;
    }
protected:
    void func(int & a)
    {
        a = a * 5;
        inc();
    }
public:
    int getC() {
        return callC;
    }
};
// END HACKERRANK LOCKED CODE

class D : public A, public B, public C
{
    int val;
public:
    //Initially val is 1
    D () : val(1) {}

    //Implement this function
    void update_val (int new_val)
    {
        int reducer = new_val;
        while (new_val != val) {
            if (reducer % 5 == 0) {
                C::func(val);
                reducer = reducer / 5;
            }
            else if (reducer % 3 == 0) {
                B::func(val);
                reducer = reducer / 3;
            }
            else if (reducer % 2 == 0) {
                A::func(val);
                reducer = reducer / 2;
            }
        }
    }

    //For Checking Purpose
    void check (int); //Do not delete this line.
};

// START HACKERRANK LOCKED CODE
void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int hackerrank::accessing_inherited()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);
    return 0;
}
// END HACKERRANK LOCKED CODE

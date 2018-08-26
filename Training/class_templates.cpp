#include <iostream>
#include <string>
#include "class_templates.h"

using namespace std;

template <class T>
class AddElements {
private:
    T m_element;
public:
    AddElements (T element) : m_element(element) {}
    T add (T other) { return m_element + other;  }
};

template <>
class AddElements <string> {
private:
    string m_element;
public:
    AddElements (string element) : m_element(element) {}
    string concatenate (string other) { return m_element + other; }
};

int hackerrank::class_templates () {
    // START HACKERRANK GIVEN CODE
    int n, i;
    cin >> n;
    for (i = 0;i < n;i++) {
        string type;
        cin >> type;
        if (type == "float") {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat (element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint (element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring (element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
    // END HACKERRANK GIVEN CODE
}

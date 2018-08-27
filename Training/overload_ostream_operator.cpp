#include <iostream>
#include <string>
#include "overload_ostream_operator.h"

// START HACKERRANK LOCKED CODE
using namespace std;

class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const string& get_first_name() const {
        return first_name_;
    }
    const string& get_last_name() const {
        return last_name_;
    }
private:
    string first_name_;
    string last_name_;
};
// END HACKERRANK LOCKED CODE

ostream & operator<< (ostream & os, const Person & p)
{
    os << "first_name=" << p.get_first_name() << ","
        << "last_name=" << p.get_last_name();
    return os;
}

// START HACKERRANK LOCKED CODE
int hackerrank::overload_ostream ()
{
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}
// END HACKERRANK LOCKED CODE

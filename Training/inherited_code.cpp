#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include "inherited_code.h"

using namespace std;

class BadLengthException : public exception {
private:
    string m_n = "UNSET";
public:
    BadLengthException (int n)
    {
        m_n = to_string(n);
    }
    virtual const char* what() const throw()
    {
        return m_n.c_str();
    }
};

// START HACKERRANK BOILERPLATE
bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
    if (n < 5) {
        throw BadLengthException(n);
    }
    for (int i = 0; i < n - 1; i++) {
        if (username[i] == 'w' && username[i + 1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}
int hackerrank::inherited_code() {
    int T; cin >> T;
    while (T--) {
        string username;
        cin >> username;
        try {
            bool isValid = checkUsername(username);
            if (isValid) {
                cout << "Valid" << '\n';
            }
            else {
                cout << "Invalid" << '\n';
            }
        }
        catch (BadLengthException e) {
            cout << "Too short: " << e.what() << '\n';
        }
    }
    return 0;
}
// END HACKERRANK BOILERPLATE

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include "inherited_code.h"

using namespace std;

class BadLengthException : public exception {
private:
    char m_n[16] = "";
public:
    BadLengthException (int n)
    {
        sprintf(m_n, "%d", n);
    }
    virtual const char * what () const throw () override
    {
        return m_n;
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

#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include "inherited_code.h"

using namespace std;

class BadLengthException : public exception {
private:
	///Es-Notes: Exceptions probably shouldn't perform heap allocations,
	///Though I don't really know- I'd just recommend against it.
	char m_n[16];

public:
	BadLengthException (int n) {
		_itoa_s(n, m_n, 16, 10);
	}

	virtual const char * what () const throw () override {
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

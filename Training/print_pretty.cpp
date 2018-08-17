#include <iostream>
#include <iomanip>
#include <math.h>
#include "print_pretty.h"

using namespace std;

int hackerrank::print_pretty()
{
    // START HACKERRANK GIVEN CODE
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;
    // END HACKERRANK GIVEN CODE

        // The hackerrank given code manipulates the standard output stream.
        // Respect the current changes and store/restore them.
        ios state(NULL);
        state.copyfmt(cout);

        // Print A as hex with showing base indicator.
        cout << resetiosflags(ios::uppercase);
        cout << hex << setiosflags(ios_base::showbase) << left;
        cout << (long long)A << endl;
        cout << resetiosflags(ios_base::showbase);

        // Print B as a fixed double with precision 2 and positivity indicator.
        // Set the field width to 15 and fill to the left with underscores.
        cout << showpos << setfill('_') << setw(15);
        cout << fixed << showpoint << setprecision(2) << right;
        cout << B << endl;

        // Print C in scientific notion with a precision of 9
        // and a capitol exponential indicator.
        cout << noshowpos << setiosflags(ios::uppercase);
        cout << setprecision(9) << scientific;
        cout << C << endl;

        // Restore the manipulator state on the standard output stream.
        cout.copyfmt(state);
    }

    return 0;
}

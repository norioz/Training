#include <iostream>
#include <set>
#include "stl_sets.h"

using namespace std;

int hackerrank::stl_sets()
{
    int q = -1;  // the number of queries
    cin >> q;

    set<int> s;
    for (int i = 0; i < q; ++i) {
        int y = -1, x = -1;
        cin >> y >> x;
        switch (y) {
        case 1:              // add x to the set
            s.insert(x);
            break;
        case 2:              // erase x from the set
            s.erase(x);
            break;
        case 3:              // find x in the set
            set<int>::iterator itr = s.find(x);
            (itr == s.end()) ? cout << "No" : cout << "Yes";
            cout << endl;
            break;
        }
    }
    return 0;
}
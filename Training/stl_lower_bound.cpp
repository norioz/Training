#include <algorithm>
#include <iostream>
#include <vector>
#include "stl_lower_bound.h"

using namespace std;

// Read N ints into vector v.
void read_array (vector<int>& v, int n)
{
    int tmp = -1;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v.push_back(tmp);
    }
}

int hackerrank::stl_lower_bound ()
{
    int n = -1; // the number of elements
    cin >> n;

    vector<int> v;
    v.reserve(n);
    read_array(v, n);
    
    int q = -1; // the number of queries
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int x = -1;  // the query value
        cin >> x;
        vector<int>::iterator low = lower_bound(v.begin(), v.end(), x);
        int idx = low - v.begin();
        (v[idx] == x) ? cout << "Yes " : cout << "No ";
        cout << (idx + 1) << endl;
    }
    return 0;
}

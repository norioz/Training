#include <vector>
#include <algorithm>
#include <iostream>
#include "stl_vector_sort.h"

using namespace std;

int hackerrank::stl_vector_sort()
{
    int n = -1;
    cin >> n;
    vector<int> v;
    int num = -1;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cout << v[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << v[i];
    }
    cout << endl;
    return 0;
}

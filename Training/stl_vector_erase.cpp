#include <iostream>
#include <vector>
#include "stl_vector_erase.h"

using namespace std;

// Prints all ins in vector v.
void print_vector (const vector<int>& v)
{
    if (v.size() > 0) {
        cout << v[0];
    }
    for (unsigned int i = 1; i < v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

// Reads n ints into vector v, starting at
// index 0.
void read_vector (int n, vector<int>& v)
{
    int tmp = -1;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v.push_back(tmp);
    }
}
int hackerrank::stl_vector_erase ()
{
    int n = -1;  // number of ints to read
    cin >> n;
    vector<int> v;
    read_vector(n, v);
    
    // Read in an element number(x).
    // Remove the element at that number.
    int x = -1;
    cin >> x;
    v.erase(v.begin() + (x - 1));

    // Read in a start and end for a range [a, b).
    // Remove elements in the range.
    int a = -1, b = -1;
    cin >> a >> b;
    v.erase(v.begin() + (a - 1), v.begin() + (b - 1));

    // print the size of the vector
    cout << v.size() << endl;

    // print the elements of the vector
    print_vector(v);
    
    return 0;
}

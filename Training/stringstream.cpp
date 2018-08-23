#include <cstdio>
#include <vector>
#include <sstream>
#include <iostream>
#include "stringstream.h";

using namespace std;

vector<int> parseInts (string str)
{
    stringstream ss(str);
    vector<int> result;
    int current = -1;
    char delim = '\0';
    while (ss >> current) {
        ss >> delim; // should probably check to see if the delimeter is a ,
        result.push_back(current);
    }
    return result;
}

int hackerrank::stringstream ()
{
    string str = "INVALID";
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    return 0;
}

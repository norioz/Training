#include <iostream>
#include <string>
#include <map>
#include "stl_maps.h"

using namespace std;

int hackerrank::stl_maps()
{
    int q = -1; // the number of queries
    cin >> q;

    map<string, int> m;

    for (int i = 0; i < q; ++i) {
        int type = 0;
        cin >> type;
        string name = "UNSET";
        cin >> name;
        switch (type) {
        case 1: {               // insert or update score
            int score = -1;
            cin >> score;
            map<string, int>::iterator iter = m.find(name);
            if (iter == m.end()) {
                m[name] = score;
            }
            else {
                m[name] = m[name] + score;
            }
            break;
        }
        case 2:                  // errase a student
            m.erase(name);
            break;
        case 3:                  // print current total
            cout << m[name] << endl;
            break;
        }
    }
    return 0;
}
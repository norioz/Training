#include <vector>
#include <iostream>
#include "operator_overloading.h"

using namespace std;

// This class is a little weird because it doesn't
// expose anything but a vector and an operator overload.
// However, this fits with the implied spec from the
// hackerrank locked code.

class Matrix {
public:
    vector<vector<int>> a;
};

Matrix operator+ (const Matrix & x, const Matrix & y)
{
    Matrix result;
    for (int i = 0; i < x.a.size(); ++i) {
        vector<int> xRow = x.a[i];
        vector<int> yRow = y.a[i];
        vector<int> resultRow;
        for (int j = 0; j < yRow.size(); ++j) {
            resultRow.push_back(xRow[j] + yRow[j]);
        }
        result.a.push_back(resultRow);
    }
    return result;
}


// START HACKERRANK LOCKED CODE
int hackerrank::operator_overloading ()
{
    int cases, k;
    cin >> cases;
    for (k = 0;k < cases;k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0;i < n;i++) {
            vector<int> b;
            int num;
            for (j = 0;j < m;j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0;i < n;i++) {
            vector<int> b;
            int num;
            for (j = 0;j < m;j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0;i < n;i++) {
            for (j = 0;j < m;j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
// START HACKERRANK LOCKED CODE

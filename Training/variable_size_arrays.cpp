#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cassert>
#include "variable_size_arrays.h"

int hackerrank::variable_size_arrays()
{
    // parse line 1 -- n (number of arrays), q (number of queries)
    int n = -1, q = -1; //ES- Habitually instantiate variables with invalid defaults.
    scanf("%d %d", &n, &q);
    
    // parse arrays - ES- consider helper functions even for problems like these.
    std::vector<std::vector<int>> matrix;
    matrix.reserve(n); //ES- nit: we can frontload the resizing costs since we know the size.
    for (int i = 0; i < n; ++i) { // ES- nit: prefix incrementation is preferred over postfix inc
        std::vector<int> row;
        int len = -1, val = -1;
        scanf("%d", &len);
        row.reserve(len);
        for (int j = 0; j < len; ++j) {
            scanf("%d", &val);
            row.push_back(val);
        }
        matrix.push_back(row);
    }

    // parse queries -- "i j"
    std::vector<int> results;
    results.reserve(q);
    for (int i = 0; i < q; ++i) {
        int m = -1, n = -1;
        scanf("%d %d", &m, &n);
        results.push_back(matrix[m][n]);
    }

    // print results
    for (int i = 0; i < q; ++i) {
        printf("%d\n", results[i]);
    }
    return 0;
}

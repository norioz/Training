#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "functions.h"

int max_of_four (int a, int b, int c, int d)
{
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    if (d > max) {
        max = d;
    }
    return max;
}

int hackerrank::functions ()
{
    int a = -1, b = -1, c = -1, d = -1;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d\n", ans);
    return 0;
}

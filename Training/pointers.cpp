#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "pointers.h"

void update(int *a, int *b)
{
    int sum = *a + *b;
    int diff = *a - *b;
    *a = sum;
    if (diff < 0) {
        *b = -diff;
    }
    else {
        *b = diff;
    }
}

int hackerrank::pointers()
{
    int a = -1, b = -1;
    int *pa = &a, *pb = &b;
    
    // This statement could be
    // scanf("%d %d", &a, &b)
    // but & could be overloaded and, thus, surprisingly costly.
    // We want to avoid this where a simpler transfer is available.
    scanf("%d %d", pa, pb);
    update(pa, pb);
    printf("%d\n%d\n", a, b);

    return 0;
}

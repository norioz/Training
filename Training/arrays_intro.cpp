#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "arrays_intro.h"

int hackerrank::arrays_intro()
{
    int n;
    int arr[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int idx = n - 1;
    while (idx > 0) {
        printf("%d ", arr[idx]);
        idx--;
    }
    printf("%d\n", arr[0]);
    return 0;
}
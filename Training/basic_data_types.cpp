#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include "basic_data_types.h"

// Input
// Input consists of the following space-separated values: int, long, char, 
// float, and double, respectively.
//
// Output Format
// Print each element on a new line in the same order it was received as input.
// Note that the floating point value should be correct up to 3 decimal places
// and the double to 9 decimal places.

int hackerrank::basic_data_types ()
{
    int a = -1;
    long b = -1L;
    char c = '\0';
    float d = 0.0F;
    double e = 0.0;

    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
    printf("%d\n%ld\n%c\n%f\n%lf\n", a, b, c, d, e);
    return 0;
}

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "functions.h"

int max_of_four(int a, int b, int c, int d)
{
    //ES- Note: This is just for the thought experiment.
    // The instantiation of l and r is parallel and branchless.
        // Parallel because there aren't competing assignments to the same variable,
        // allowing for vectorized math optimizations to occur automatically.
        // Obviously this doesn't apply for the return statement.
            
    int l = (a > b) * a + (a <= b) * b;
    int r = (c > d) * c + (c <= d) * d;
    return  (l > r) * l + (l <= r) * r;
    
    // Overall there are more math operations here and we can't predict how the platform
    // will optimize small if-blocks, so this could be worse! You would only consider something
    // like this in real-time loop critical code that gets repeated 10000x in a row.    
}

int hackerrank::functions()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d\n", ans);
    return 0;
}

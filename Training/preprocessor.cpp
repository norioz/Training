#include <limits>
#include <iostream>
#include <vector>
#include "preprocessor.h"

#define INF numeric_limits<int>::max()
#define toStr(r) #r
#define foreach(v, i) for(unsigned int i = 0; i < v.size(); ++i)
#define io(v) cin >> v
#define minimum(e, v) e = (e < v) ? e : v;
#define maximum(e, v) e = (e > v) ? e : v;
#define FUNCTION(name, op)

// START HACKERRANK GIVEN CODE
#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

using namespace std;

FUNCTION(minimum, < )
FUNCTION(maximum, > )

int hackerrank::preprocessor ()
{
    int n; cin >> n;
    vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    cout << toStr(Result = ) << ' ' << ans;
    return 0;
}
// END HACKERRANK GIVEN CODE

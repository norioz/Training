#include <iostream>
#include <deque>
#include "stl_deque.h"

using namespace std;

// Returns the index of the max value in the delque.
// Requires that all values in dq are >= 0.
int findMax (deque<int> & dq)
{
    int maxVal = 0;
    int maxIdx = -1;
    for (int i = 0; i < dq.size(); ++i) {
        if (dq[i] >= maxVal) {
            maxVal = dq[i];
            maxIdx = i;
        }
    }
    return maxIdx;
}

void printKMax (int arr[], int n, int k)
{
    deque<int> dq;
    int nextIdx = k;
    int maxIdx = -1;

    // Prefill the deque.
    for (int i = 0; i < k; ++i) {
        dq.push_back(arr[i]);
    }

    // Record the index of the max value.
    maxIdx = findMax(dq);

    // Print the first value.
    std::cout << dq[maxIdx];

    // Step through the array, pushing into the deque
    // and popping from the front.
    while (nextIdx < n) {
        // Push the new value into the deque.
        int newValue = arr[nextIdx++];
        dq.push_back(newValue);

        // If the new value can be the max it
        // supplants the previous.
        if (newValue >= dq[maxIdx]) {
            maxIdx = k;
        }

        // Remove an element 
        dq.pop_front();

        // All values in the deque have shifted down.
        // Update the location of the maxVal.
        --maxIdx;
        
        // If the previous max value was popped,
        // find a new one.
        if (maxIdx == -1) {
            maxIdx = findMax(dq);
        }

        std::cout << " " << dq[maxIdx];
    }
    std::cout << endl;
}

int hackerrank::stl_deque ()
{
    // START HACKERRANK GIVEN CODE
    int t;
    cin >> t;
    while(t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[10000];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
    // END HACKERRANK GIVEN CODE
}

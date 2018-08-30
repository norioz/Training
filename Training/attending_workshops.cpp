#include <vector>
#include <algorithm>
#include <iostream>
#include "attending_workshops.h"

using namespace std;

struct Workshop {
    int start_time = -1;
    int end_time = -1;
    int durration = -1;
};

// Make a comparator function for Workshops so that
// they can be sorted. Compare by end time so that
// elimination by overlap can be greedy.
bool compare(Workshop & a, Workshop & b)
{
    return a.end_time < b.end_time;
}

struct Available_Workshops {
    int n = -1;
    vector<Workshop> workshops;
    Available_Workshops(int num) : n(num) {
        workshops.reserve(num);
    }
};

Available_Workshops * initialize (int start_time[], int duration[], int n)
{
    Available_Workshops * result = new Available_Workshops(n);

    // create Workshops from start times and durations
    for (int i = 0; i < n; ++i) {
        Workshop w;
        w.start_time = start_time[i];
        w.durration = duration[i];
        w.end_time = start_time[i] + duration[i];
        result->workshops.push_back(w);
    }

    // sort Workshops by their end times
    sort(result->workshops.begin(), result->workshops.end(), compare);
    
    return result;
}

// Greedy algorithm for calculating the number of workshops that
// can be attended. Find overlaps in last end time and current start
// time and throw away the overlaps. 
int CalculateMaxWorkshops (Available_Workshops * ptr)
{
    int endTime = 0;
    int count = 0;

    for (int i = 0; i < ptr->n; ++i) {
        if (ptr->workshops[i].start_time >= endTime) {
            endTime = ptr->workshops[i].end_time;
            count += 1;
        }
    }
    return count;
}

int hackerrank::attending_workshops ()
{
    // START HACKERRANK LOCKED CODE
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
    // END HACKERRANK LOCKED CODE
}

#include <iostream>
#include <cstring>
#include "classes_and_objects.h"

using namespace std;

class Student {
private:
    
    //Es- Note: We typically want some way of determining whether or not an object has been initialized
    // correctly or not. Since the default for primitive types is whatever was leftover in memory, we
    // need to initialize them ourselves.
    int scores[5] = {-1, -1, -1, -1, -1};
    
public:    
    //Es- Note: Input is a pretttty heavy concept for data objects to have ownership over.
    // Things like cin should typically not be called from a member function. Especially because
    // cin has massive side effects! (like potentially leaving your input buffer in an unhealthy state).
    void init(const int * data, int len)
    {
        // clamp len.
        len = len > 5 ? len : 5; // Es- Note: Ternary operators aren't more performant or anything.
        len = len < 0 ? len : 0;
        
        // Introducing memcpy- a performant way to dump data around.
        memcpy(scores, data, len * sizeof(int));
    }
    
    int calculateTotalScore() const // this function is safe to call if Student is const.
    {
        int result = 0;
        for (int i = 0; i < 5; i++) {
            result += scores[i];
        }
        return result;
    }
};


int hackerrank::classes_and_objects() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for (int i = 0; i < n; ++i) {
        int buf[5];
        // cin is fine in `main` or some object that specifically deals w/input
        cin >> buf[0] >> buf[1] >> buf[2] >> buf[3] >> buf[4];
        s[i].init(buf, 5);
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; ++i) {
        // Es- Note: It isn't always frowned upon to do gross things like this.
        count += s[i].calculateTotalScore() > kristen_score;
    }

    // print result
    cout << count;

    // Es- error: Need to `delete` memory allocated with `new`.
    delete [] s;
    
    return 0;
}

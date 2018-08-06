#include <iostream>
#include <string>
#include "structs.h"

using namespace std;

struct Student {
    int age;
    string first_name;
    string last_name;
    int standard;
};

int hackerrank::structs()
{
    Student st;

    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

    return 0;
}

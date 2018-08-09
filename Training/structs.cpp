#include <iostream>
#include <string>
#include "structs.h"

using namespace std;

struct Student {
    int age = -1, standard = -1;
    string first_name = "INVALID";
    string last_name = "INVALID";
};

int hackerrank::structs()
{
    Student st;

    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard << endl;

    return 0;
}

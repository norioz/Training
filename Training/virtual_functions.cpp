#include <iostream>
#include <string>
#include "virtual_functions.h"

using namespace std;

class Person {
protected:
    string m_name = "UNSET";
    int m_age = -1;
public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person {
private:
    static int s_next_id;
    int m_publications = -1,
        m_cur_id = -1;
public:
    Professor()
    {
        m_cur_id = s_next_id++;
    }
    void getdata() 
    {
        cin >> m_name >> m_age >> m_publications;
    }
    void putdata() 
    {
        cout << m_name << " " << m_age << " " << m_publications << " " << m_cur_id << endl;
    }
};

int Professor::s_next_id = 1;

class Student : public Person {
private:
    static int s_next_id;
    int m_marks[6] = { -1, -1, -1, -1, -1, -1 };
    int m_cur_id = -1;
public:
    Student()
    {
        m_cur_id = s_next_id++;
    }
    void getdata()
    {
        cin >> m_name >> m_age;
        for (int i = 0; i < 6; ++i) {
            cin >> m_marks[i];
        }
    }
    void putdata()
    {
        cout << m_name << " " << m_age;
        int marks_sum = 0;
        for (int i = 0; i < 6; ++i) {
            marks_sum += m_marks[i];
        }
        cout << " " << marks_sum << " " << m_cur_id << endl;
    }
};

int Student::s_next_id = 1;

int hackerrank::virtual_functions()
{
    // START HACKERRANK BOILERPLATE
    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person *per[1000];

    for (int i = 0;i < n;i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
    // END HACKERRANK BOILERPLATE
}

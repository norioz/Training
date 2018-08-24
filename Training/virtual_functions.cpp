#include <iostream>
#include <string>
#include "virtual_functions.h"

using namespace std;

class Person {
protected:
    string m_name;
    int m_age = -1;
public:
    virtual void getdata () = 0;
    virtual void putdata () = 0;
    virtual ~Person () {};
};

class Professor : public Person {
private:
    static int id_counter;
    int m_publications = -1;
    int m_cur_id = -1;
public:
    Professor ();
    static Person * make ();
    void getdata () override;
    void putdata () override;
};

class Student : public Person {
private:
    static int id_counter;
    int m_marks[6] = { -1, -1, -1, -1, -1, -1 };
    int m_cur_id = -1;
public:
    Student ();
    static Person * make ();
    void getdata () override;
    void putdata () override;
};

int hackerrank::virtual_functions ()
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

///////////////////
// Professor Impl

int Professor::id_counter = 0;
inline Professor::Professor ()
{
    m_cur_id = ++id_counter;
}

inline void Professor::getdata ()
{
    cin >> m_name >> m_age >> m_publications;
}

inline void Professor::putdata ()
{
    cout << m_name << " " << m_age << " " << m_publications << " " << m_cur_id << endl;
}

inline Person * Professor::make ()
{
    auto ret = new Professor();
    ret->m_cur_id = ++id_counter;
    return ret;
}

///////////////////
// Student Impl

int Student::id_counter = 0;
inline Student::Student ()
{
    m_cur_id = ++id_counter;
}

inline Person * Student::make ()
{
    auto ret = new Student();
    ret->m_cur_id = ++id_counter;
    return ret;
}

inline void Student::getdata ()
{
    cin >> m_name >> m_age;
    for (int i = 0; i < 6; ++i) {
        cin >> m_marks[i];
    }
}

inline void Student::putdata ()
{
    cout << m_name << " " << m_age;
    int marks_sum = 0;
    for (int i = 0; i < 6; ++i) {
        marks_sum += m_marks[i];
    }
    cout << " " << marks_sum << " " << m_cur_id << endl;
}
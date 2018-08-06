#include <iostream>
#include <string>
#include <sstream>
#include "classes.h";

using namespace std;

class Student {
private:
    int m_age;
    int m_standard;
    string m_first_name;
    string m_last_name;
public:
    void set_age(int age) { m_age = age; }
    int get_age() { return m_age; }
    void set_standard(int standard) { m_standard = standard; }
    int get_standard() { return m_standard; }
    void set_first_name(string first_name) { m_first_name = first_name; }
    string get_first_name() { return m_first_name; }
    void set_last_name(string last_name) { m_last_name = last_name; }
    string get_last_name() { return m_last_name; }
    string to_string() {
        stringstream ss;
        ss << m_age << "," << m_first_name << "," << m_last_name << "," << m_standard;
        return ss.str();
    }
};

int hackerrank::classes()
{
    int age, standard;
    string first_name, last_name;
    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << endl;
    cout << st.get_last_name() << ", " << st.get_first_name() << endl;
    cout << st.get_standard() << endl;
    cout << st.to_string();

    return 0;
}
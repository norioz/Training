#include <iostream>
#include <string>
#include "virtual_functions.h"

using namespace std;

class Person {
protected:
	string m_name; /// Es-Note: String is an object that default initializes.
	int	   m_age  = -1;

public:
	/// Es-Note: Hackerrank is gross. Get/Put here is mixed/non-idiomatic
	virtual void getdata () = 0;
	virtual void putdata () = 0;
	virtual ~Person () { }; /// Es-Note: Search 'Virtual Destructors'
};


class Professor : public Person {
private:
	static int s_next_id;
	int m_publications = -1;
	int m_cur_id	   = -1;

public:
	Professor ();
	static Person * make ();
	void getdata () override; /// Es-Note: Should explicitly use override keyword.
	void putdata () override;
};


class Student : public Person {
private:
	static int s_next_id;
	int m_marks[6] = { -1, -1, -1, -1, -1, -1 };
	int m_cur_id   = -1;
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
	Person * per[1000];
	memset(per, 0, sizeof(Person*)); ///Es-Note: Initialize `per` array to nullptrs for safety.

	for (int i = 0; i < n; i++) {

		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor(); ///Es-Note: Use function-call style syntax for constructors.

		}
		else { ///Es-Note: match brace style w/the if statement-- either both or neither have it.
			per[i] = new Student(); // Else the current object is of type Student
		}
		per[i]->getdata(); // Get the data from the user.

	}

	for (int i = 0; i < n; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;
	// END HACKERRANK BOILERPLATE
}


///////////////////
// Professor Impl

int Professor::s_next_id = 1;

inline Professor::Professor () {
	m_cur_id = s_next_id++;
}
inline void Professor::getdata () {
	cin >> m_name >> m_age >> m_publications;
}
inline void Professor::putdata () {
	cout << m_name << " " << m_age << " " << m_publications << " " << m_cur_id << endl;
}

inline Person * Professor::make () {
	auto ret = new Professor();
	ret->m_cur_id = s_next_id;
	return ret;
}

///////////////////
// Student Impl

/// Es-Note: Static variables/objects are always default initialized to 0 or the  default constructor.
/// In this case, you could work with this assumption and just start counting from 0.
// int Student::s_next_id = 1;

inline Student::Student () {
	///Es-Note: Constructors get called incidentally/accidentally all the time.
	/// It's a good idea not to perform static incrementation using a constructor,
	/// but instead provide a factory builder. That way this object will behave
	/// when used in data structures that need to copy stuff around.
	/// IE. Just because the object was constructed, does not mean that it
	/// represents new data.
	m_cur_id = s_next_id++;
}


inline Person * Student::make () {
	/// Es-Note: See 'Student::Student ()' above.
	auto ret = new Student();
	ret->m_cur_id = ++s_next_id; // Assuming s_next_id starts at 0.
	return ret;
}


inline void Student::getdata () {
	/// Es-Note: string is whitespace delimited here, which is dangerous
	/// to follow with an integer. Obviously input validation and feedback
	/// is pretty pointless in these hacker rank problems- just something to consider.
	cin >> m_name >> m_age;
	for (int i = 0; i < 6; ++i) {
		cin >> m_marks[i];
	}
}


inline void Student::putdata () {
	/// Es-Note: Generally we want to overload the '<<' operator instead
	/// of using cout directly.
	cout << m_name << " " << m_age;
	int marks_sum = 0;
	for (int i = 0; i < 6; ++i) {
		marks_sum += m_marks[i];
	}
	cout << " " << marks_sum << " " << m_cur_id << endl;
}

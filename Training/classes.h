#pragma once

// hackerrank: Class
// https://www.hackerrank.com/challenges/c-tutorial-class/problem
//
// Input
//
// You have to create a class, named Student, representing the student's 
// details, as mentioned above, and store the data of a student. Create setter
// and getter functions for each element; that is, the class should at least
// have following functions:
// get_age, set_age
// get_first_name, set_first_name
// get_last_name, set_last_name
// get_standard, set_standard
// Also, you have to create another method to_string() which returns the 
// string consisting of the above elements, separated by a comma(,).
// You can refer to stringstream for this.
// 
// Input will consist of four lines. 
// The first line will contain an integer, representing the age.
// The second line will contain a string, consisting of lower - case Latin
// characters('a' - 'z'), representing the first_name of a student.
// The third line will contain another string, consisting of lower - case
// Latin characters('a' - 'z'), representing the last_name of a student.
// The fourth line will contain an integer, representing the standard of 
// student.
//
//Note: The number of characters in first_name and last_name will not exceed 50.

namespace hackerrank {

int classes();

}

#pragma once

// hackerrank: Classes and Objects
// https://www.hackerrank.com/challenges/classes-objects/problem
// 
// Input
// Kristen is a contender for valedictorian of her high school. She wants 
// to know how many students (if any) have scored higher than her in the 5 
// exams given during this semester.
// Create a class named Student with the following specifications :
// An instance variable named scores to hold a student's 5 exam scores.
// A void input() function that reads 5 integers and saves them to scores.
// An int calculateTotalScore() function that returns the sum of the 
// student's scores.
//
// In the void Student::input() function, you must read 5 scores from stdin
// and save them to your scores instance variable.
//
// Constraints
// 1 <= n <= 100  (n := the number of students)
// 0 <= examscore <= 50
//
// Output
// In the int Student::calculateTotalScore() function, return the student's
// total grade (the sum of the values in scores).

namespace hackerrank {

int classes_and_objects();

}

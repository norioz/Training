#pragma once

// hackerrank: Inherited Code
// https://www.hackerrank.com/challenges/inherited-code/problem
//
// Exercise
// You inherited a piece of code that performs username validation for your company's website.
// The existing function works reasonably well, but it throws an exception when the username is
// too short. Upon review, you realize that nobody ever defined the exception.
// The inherited code is provided for you in the locked section of your editor. Complete the 
// code so that, when an exception is thrown, it prints Too short: n (where n is the length of
// the given username).
//
// Input
// The first line contains an integer, t, the number of test cases.
// Each of the t subsequent lines describes a test case as a single username string, u.
//
// Constraints
// 1 <= t <= 1000
// 1 <= |u| <= 100
// The username only consists of uppercase and lowercase letters.
//
// Output
// You are not responsible for directly printing anything to stdout. If your code is correct,
// the locked stub code in your editor will print either Valid (if the username is valid), 
// Invalid (if the username is invalid), or Too short: n (where n is the length of the 
// too-short username) on a new line for each test case.

namespace hackerrank {

int inherited_code();

}

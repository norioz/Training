#pragma once

// hackerrank: Exceptional Server
// https://www.hackerrank.com/challenges/exceptional-server/problem
// 
// Overview
// Your friend set up a small computational server that performs complex calculations. 
// It has a function that takes 2 large numbers as its input and returns a numeric result.
// Unfortunately, there are various exceptions that may occur during execution.
// Complete the code in your editor so that it prints appropriate error messages, should
// anything go wrong. The expected behavior is defined as follows :
// - If the compute function runs fine with the given arguments, then print the result of
// the function call.
// - If it fails to allocate the memory that it needs, print "Not enough memory".
// - If any other standard C++ exception occurs, print Exception : S where S is the 
// exception's error message.
// - If any non - standard exception occurs, print "Other Exception".
//
// Input
// The first line contains an integer, T, the number of test cases.
// Each of the T subsequent lines describes a test case as 2 space-separated integers,
// A and B, respectively.
//
// Constraints
// 1 <= T <= 10^3
// 0 <= A,B <= 2^60
//
// Output
// For each test case, print a single line containing whichever message described in
// the Problem Statement above is appropriate. After all messages have been printed, 
// the locked stub code in your editor prints the server load.
//
// 2
// -8 5
// 1435434255433 5
//
// Exception: A is negative
// Not enough memory
// 2

namespace hackerrank {

int exceptional_server();

}
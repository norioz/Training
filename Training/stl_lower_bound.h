#pragma once

// hackerrank: Lower-Bound STL
// https://www.hackerrank.com/challenges/cpp-lower-bound/problem
//
// You are given N integers in the sorted order. Then you are given Q queries.
// In each query you will be given an integer and you have to tell whether 
// that integer is present in the array, if so you have to tell at which
// index it is present and if it is not present you have to tell the index
// at which the smallest integer that is just greater than the given number is
// present.
//
// Input
// The first line of the input contains the number of integers N. The next 
// line contains N integers in sorted order. The next line contains Q, the
// number of queries. Then Q lines follow each containing a single integer
// Y.
// If the same number is present multiple times, you have to print the
// first index at which it occurs.
// The input is such that you always have an answer for each query.
//
// Output
// For each query you have to print "Yes" if the number is present and
// at which index(1-based) it is present separated by a space.
// If the number is not present you have to print "No" followed by the 
// index of the next smallest number just greater than that number.
// You have to output each query in a new line.

namespace hackerrank {

int stl_lower_bound ();

}

#pragma once

// hackerrank: Sets-STL
// https://www.hackerrank.com/challenges/cpp-sets/problem
//
// You will be given Q queries. Each query is of one of the following three types:
// 1 x: Add an element x to the set.
// 2 x: Delete an element x from the set. (If the number x is not present in the set, then do nothing).
// 3 x: If the number x is present in the set, then print "Yes" else print "No".
//
// Input
// The first line of the input contains Q where Q is the number of queries. The next Q lines contain 1 
// query each. Each query consists of two integers y and x where y is the type of the query and x is 
// an integer.
//
// Output
// For queries of type 3 print "Yes" if the number x is present in the set and if the number is not 
// present, then print "No".
// Each query of type 3 should be printed in a new line.

namespace hackerrank {

int stl_sets();

}
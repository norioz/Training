#pragma once

// hackerrank: Vector-Erase
// https://www.hackerrank.com/challenges/vector-erase/problem
//
// You are provided with a vector of N integers. Then, you are given 
// 2 queries. For the first query, you are provided with 1 integer, 
// which denotes a position in the vector. The value at this position
// in the vector needs to be erased. The next query consists of 2 
// integers denoting a range of the positions in the vector. The 
// elements which fall under that range should be removed. The 
// second query is performed on the updated vector which we get after
// performing the first query.
//
// Input
// The first line of the input contains an integer N. The next line 
// contains N space separated integers(1-based index). The third line
// contains a single integer x, denoting the position of an element 
// that should be removed from the vector. The fourth line contains 
// two integers a and b denoting the range that should be erased from
// the vector inclusive of a and exclusive of b.
//
// Output
// Print the size of the vector in the first line and the elements 
// of the vector after the two erase operations in the second line 
// separated by space.
//
// Sample
// 6
// 1 4 6 2 8 9
// 2
// 2 4
//
// 3
// 1 8 9

namespace hackerrank {
    
int stl_vector_erase ();

}

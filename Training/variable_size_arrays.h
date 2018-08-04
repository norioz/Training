#pragma once

// hackerrank: Varaible Size Arrays
// https://www.hackerrank.com/challenges/variable-sized-arrays/problem
//
// Input
// The first line contains two space-separated integers denoting the respective values of n
// (the number of variable-length arrays) and q (the number of queries). 
// Each line i of the n subsequent lines contains a space-separated sequence in the format
// k a[i]0 a[i]1 … a[i]k-1 describing the k-element array located at a[i].
// Each of the q subsequent lines contains two space-separated integers describing the
// respective values of i(an index in array a) and j(an index in the array referenced by a[i])
// for a query.
//
// Constraints
// 1 <= n <= 10^5
// 1 <= q <= 10^5
// 1 <= Ak <= 3*10^5
// n <= Sk <= 3*10^5
// 0 <= Ai <= n
// 0 <= Aj <= k
// All indices in the challenge are zero-based.
// All the given numbers are non negative and are not greater than 10^6.
//
// Output
// For each pair of i and j values (i.e., for each query), print a single integer denoting
// the element located at index j of the array referenced by a[i]. There should be a total of
// q lines of output.

namespace hackerrank {

int variable_size_arrays();

}

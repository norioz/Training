#pragma once

// hackerrank: Accessing Inherited Functions
// https://www.hackerrank.com/challenges/accessing-inherited-functions/problem
//
// You are given three classes A, B and C. All three classes implement 
// their own version of func.
// In class A, func multiplies the value passed as a parameter by 2.
// In class B, func multiplies the value passed as a parameter by 3.
// In class C, func multiplies the value passed as a parameter by 5.
// You are given a class D.
// You need to modify the class D and implement the function update_val
// which sets D's val to new_val by manipulating the value by only calling
// the func defined in classes A, B and C.
// 
// Input
// Implement class D's function update_val. This function should update
// D's val only by calling A, B and C's func.
//
// Constraints
// new_val has only 2, 3, and 5 as its prime factors.
// 1 <= new_val <= 10000

namespace hackerrank {
    
int accessing_inherited ();

}

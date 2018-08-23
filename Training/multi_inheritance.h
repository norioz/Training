#pragma once

// hackerrank: Multi Level Inheritance
// https://www.hackerrank.com/challenges/multi-level-inheritance-cpp/problem
// 
// Suppose we have a class A which is the base class and we have a class B which is 
// derived from class A and we have a class C which is derived from class B, we can
// access the functions of both class A and class B by creating an object for class
// C. This is called Multi-Level inheritance. (B inherits A and C inherits B.)
// Create a class called Equilateral which inherits from Isosceles and should have a
// function such that the output is as given below.
//
// I am an equilateral triangle
// I am an isosceles triangle
// I am a triangle

namespace hackerrank {
    
int multi_inheritance ();

}

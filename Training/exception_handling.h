#pragma once

// hackerrank: Cpp exception handling
// https://www.hackerrank.com/challenges/cpp-exception-handling/problem
//
// In this challenge, the task is to debug the existing code to 
// successfully execute all provided test files.
// 
// You are required to extend the existing code so that it handles 
// std::invalid_argument exception properly. More specifically, you have
// to extend the implementation of process_input function. It takes 
// integer n as an argument and has to work as follows:
// 1) It calls function largest_proper_divisor(n).
// 2) If this call returns a value without raising an exception, it should
// print in a single line result = d where d is the returned value.
// 3) Otherwise, if the call raises a std::invalid_argument exception, it 
// has to print in a single line the string representation of the raised
// exception, i.e. its message.
// 4) Finally, no matter if the exception is raised or not, it should print
// in a single line "returning control flow to caller" after any other 
// previously printed output.
//
// To keep the code quality high, you are advised to have exactly one line
// printing returning control flow to caller in the body of process_input 
// function.
//
// Input
// In the only line of the input, there is a single integer n, which is
// going to be the argument passed to function process_input.
// 
// Output
// The output should be produced by function process_input as described
// in the statement.
//
// Constraints
// 0 <= n <= 100

namespace hackerrank {
    
int exception_handling ();

}

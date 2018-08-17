#pragma once

// hackerrank: Print Pretty
// https://www.hackerrank.com/challenges/prettyprint/problem
//
// Input
// Your manager gave you a text file with many lines of numbers to format and print. 
// For each row of 3 space-separated doubles, format and print the numbers using the
// specifications in the Output Format section below.
//
// Output
// For each test case, print 3 lines containing the formatted A, B, and C, respectively. 
// Each A, B, and C must be formatted as follows:
// A: Strip its decimal(i.e., truncate it) and print its hexadecimal representation
// (including the 0x prefix) in lower case letters.
// B: Print it to a scale of 2 decimal places, preceded by a + or - sign(indicating if 
// it's positive or negative), right justified, and left-padded with underscores so 
// that the printed result is exactly 15 characters wide.
// C: Print it to a scale of exactly nine decimal places, expressed in scientific 
// notation using upper case.
//
// Sample
// 1
// 100.345 2006.008 2331.41592653498
//
// 0x64             
// _______ + 2006.01
// 2.331415927E+03

namespace hackerrank {

int print_pretty();

}

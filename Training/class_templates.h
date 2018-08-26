#pragma once

// hackerrank : C++ Class Templates
// https://www.hackerrank.com/challenges/c-class-templates/problem
//
// You are given a main() function which takes a set of inputs. The type
// of input governs the kind of operation to be performed, i.e. concatenation
// for strings and addition for int or float. You need to write the class
// template AddElements which has a function add() for giving the sum of int
// or float elements. You also need to write a template specialization for
// the type string with a function concatenate() to concatenate the second
// string to the first string.
//
// Input
// The first line contains an integer n. Input will consist of n+1 lines 
// where n is the number given in the first line of the input followed by n
// lines. Each of the next n line contains the type of the elements 
// provided and depending on the type, either two strings or two integers
// or two floating point numbers will be given. The type will be one of int,
// float or string types only. Out of the following two elements, you have
// to concatenate or add the second element to the first element.
//
// Output
// The code provided in the code editor will use your class template to
// add/append elements and give the output.
//
// Sample
// 3
// string John Doe
// int 1 2
// float 4.0 1.5
//
// JohnDoe
// 3
// 5.5

namespace hackerrank {

int class_templates ();

}

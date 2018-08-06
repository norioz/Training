#pragma once

// hackerrank: Overload Operators
// https://www.hackerrank.com/challenges/overload-operators/problem

// You need to overload operators + and << for the Complex class.
// The operator + should add complex numbers according to the rules
// of complex addition : (a+ib) + (c+id) = (a+c) + i(b+d)
// Overload the stream insertion operator << to add "a + ib" to
// the stream.
//
// Input 
// The overloaded operator + should receive two complex numbers
// (a+ib and c+id) as parameters. It must return a single complex
// number.
// The overloaded operator << should add "a + ib" to the stream 
// where a is the real part and b is the imaginary part of the 
// complex number which is then passed as a parameter to the 
// overloaded operator.

namespace hackerrank {

int overload_operators();

}

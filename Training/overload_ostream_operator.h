#pragma once

// hackerrank: Overloading Ostream Operator
// https://www.hackerrank.com/challenges/overloading-ostream-operator/problem
//
// The task is to overload the << operator for Person class in such a
// way that for p being an instance of class Person the result of:
// ```std::cout << p << " " << <some_string_value> << std::endl;```
// produces the following:
// ```first_name=<first_name>,last_name=<last_name> <some_string_value>```

namespace hackerrank {

int overload_ostream ();

}

#pragma once

// hackerrank:: Attribute Parser
// https://www.hackerrank.com/challenges/attribute-parser/problem
//
// Input
// We have defined our own markup language HRML. In HRML, each element 
// consists of a starting and ending tag, and there are attributes associated
// with each tag. Only starting tags can have attributes. We can call an
// attribute by referencing the tag, followed by a tilde, '~' and the name
// of the attribute. The tags may also be nested.
// The opening tags follow the format :
// <tag - name attribute1 - name = "value1" attribute2 - name = "value2" ...>
// The closing tags follow the format :
// < / tag - name>
// You are given the source code in HRML format consisting of n lines. 
// You have to answer q queries. Each query asks you to print the value of 
// the attribute specified. Print "Not Found!" if there isn't any such 
// attribute.
//
// Constraints
// 1 <= n <= 20
// 1 <= q <= 20
// Each line in the source program contains, at max, 200 characters.
// Every reference to the attributes in the q queries contains at max 200 characters.
// All tag names are unique and the HRML source program is logically correct.
// A tag can have no attributes as well.
//
// Output
// Print the value of the attribute for each query. Print "Not Found!" without 
// quotes if there is no such attribute in the source program.

namespace hackerrank {

int attribute_parser ();

}

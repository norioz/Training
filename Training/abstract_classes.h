#pragma once

// hackerrank: Abstract Classes - Polymorphism
// https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
//
// Given an abstract base class Cache with member variables and functions: 
// mp - Map the key to the node in the linked list
// cp - Capacity
// tail - Double linked list tail pointer
// head - Double linked list head pointer
// set() - Set / insert the value of the key, if present, otherwise add the
// key as the most recently used key.If the cache has reached its capacity,
// it should replace the least recently used key with a new key.
// get() - Get the value (will always be positive) of the key if the key 
// exists in the cache, otherwise return -1.
// You have to write a class LRUCache which extends the class Cache and uses
// the member functions and variables to implement an LRU cache.
//
// Input
// First line of input will contain the N number of lines containing get or
// set commands followed by the capacity M of the cache.
// The following N lines can either contain get or set commands.
// An input line starting with "get" will be followed by a key to be found
// in the cache. An input line starting with "set" will be followed by the
// key and value respectively to be inserted / replaced in the cache.
//
// Constraints
// 1 <= N <= 50000
// 1 <= M <= 1000
// 1 <= key <= 20
// 1 <= value <= 2000
//
// Output
// The locked code will use LRUCache to output the value whenever a get
// command is encountered.

namespace hackerrank {

int abstract_classes ();

}

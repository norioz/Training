#pragma once

// hackerrank: Messages Order
// https://www.hackerrank.com/challenges/messages-order/problem
//
// In this problem, the task is to implement a software layer over the
// top of a network protocol sending messages in arbitrary order, in
// such a way that the sent messages are printed by the recipient in
// the order they were sent.
// In the template code, there are implementations of classes Recipient
// and Network.
// Your task is to implement classes Message and MessageFactory 
// according to the below specification:
// Class Message is required to store a text value of type std::string
// and provide a public getter const string& get_text() which is 
// expected to return this text value. Besides that, it should 
// implement the < operator that will be used in fix_order() method
// of the recipient to fix the order of received messages. Feel free
// to implement any other methods and class/instance variables. In 
// particular, you can implement any additional constructors, but make
// sure that you provide an empty constructor, i.e. the one without
// arguments.
// Class MessageFactory is required to have an empty constructor, and
// implement a method Message create_message(const string& text) that
// is expected to return a Message object storing the value of text
// argument. Feel free to implement any other methods and 
// class/instance variables of this class.
//
// Input
// The input is read by the provided locked code template. It contains
// several lines of text messages in the order that they will be sent
// over the network.
//
// Output
// The output should be produced by the provided locked code template
// and it is produced as described in details in the statement. The
// expected order of printed messages is the same as the one in the
// input.

namespace hackerrank {
   
int messages_order ();

}


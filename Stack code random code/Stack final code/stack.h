#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    T *data;       // pointer to hold array
    int capacity;  // maximum size
    int top;       // index of top element

public:
    Stack();                    // Default Constructor
    Stack(int size);            // Constructor
    Stack(const Stack &other);  // Copy Constructor
    Stack &operator=(const Stack &other); // Assignment Operator

    void push(T value);   // Push element
    T pop();              // Pop element
    bool isFull();        // Check if full
    bool isEmpty();       // Check if empty
    int getTop();         // Get index of top
    T stackTop();         // Get top element

    ~Stack();             // Destructor
};

// -------- infix/postfix/prefix functions --------
int precedence(char c);
string infix_to_postfix(string s);
string infix_to_prefix(string s);

#include "stack.cpp"  // include implementation for templates

#endif

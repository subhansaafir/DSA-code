#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T *data;       // pointer to hold array
    int capacity;  // maximum size
    int top;       // index of top element

public:
    // Constructor
    Stack(int size);

    // Copy Constructor
    Stack(const Stack &other);

    // Assignment Operator
    Stack &operator=(const Stack &other);

    // Push element
    void push(T value);

    // Pop element
    T pop();

    // Check if full
    bool isFull();

    // Check if empty
    bool isEmpty();

    // Get index of top
    int getTop();

    // Get top element
    T stackTop();

    // Destructor
    ~Stack();
};

#endif
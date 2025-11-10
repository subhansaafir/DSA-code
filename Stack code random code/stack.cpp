#include "stack.h"
using namespace std;

//Default constructor
template <class T>
Stack<T>::Stack() {
    capacity = 100;
    data = new T[capacity];
    top = -1;
}
// Constructor
template <class T>
Stack<T>::Stack(int size) {
    capacity = size;
    data = new T[capacity];
    top = -1;
}

// Copy Constructor
template <class T>
Stack<T>::Stack(const Stack<T> &other) {
    capacity = other.capacity;
    top = other.top;
    data = new T[capacity];
    for (int i = 0; i <= top; i++) {
        data[i] = other.data[i];
    }
}

// Assignment Operator
template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        top = other.top;
        data = new T[capacity];
        for (int i = 0; i <= top; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Push element
template <class T>
void Stack<T>::push(T value) {
    if (isFull()) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    data[++top] = value;
}

// Pop element
template <class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return T(); // return default-constructed T
    }
    return data[top--];
}

// Check if full
template <class T>
bool Stack<T>::isFull() {
    return top == capacity - 1;
}

// Check if empty
template <class T>
bool Stack<T>::isEmpty() {
    return top == -1;
}

// Get index of top
template <typename T>
int Stack<T>::getTop() {
    return top;
}

// Get top element
template <typename T>
T Stack<T>::stackTop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return T();
    }
    return data[top];
}

// Destructor
template <typename T>
Stack<T>::~Stack() {
    delete[] data;
}
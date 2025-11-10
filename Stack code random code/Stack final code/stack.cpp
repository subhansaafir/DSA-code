#include "stack.h"
#include <algorithm>
#include <cctype>
using namespace std;

// ================= STACK IMPLEMENTATION =================

// Default constructor
template <typename T>
Stack<T>::Stack() {
    capacity = 100;
    data = new T[capacity];
    top = -1;
}

// Constructor
template <typename T>
Stack<T>::Stack(int size) {
    capacity = size;
    data = new T[capacity];
    top = -1;
}

// Copy Constructor
template <typename T>
Stack<T>::Stack(const Stack<T> &other) {
    capacity = other.capacity;
    top = other.top;
    data = new T[capacity];
    for (int i = 0; i <= top; i++) {
        data[i] = other.data[i];
    }
}

// Assignment Operator
template <typename T>
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
template <typename T>
void Stack<T>::push(T value) {
    if (isFull()) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    data[++top] = value;
}

// Pop element
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return T();
    }
    return data[top--];
}

// Check if full
template <typename T>
bool Stack<T>::isFull() {
    return top == capacity - 1;
}

// Check if empty
template <typename T>
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

// ================= INFIX/POSTFIX/PREFIX FUNCTIONS =================

int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1; // brackets
}

string infix_to_postfix(string s) {
    Stack<char> st;
    string res = "";

    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];

        if (isspace((unsigned char)c)) continue;

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            res += c;
        } else if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char match = (c == ')') ? '(' : (c == '}') ? '{' : '[';
            while (!st.isEmpty() && st.stackTop() != match) {
                res += st.stackTop();
                st.pop();
            }
            if (!st.isEmpty()) st.pop();
        } else {
            while (!st.isEmpty() && precedence(st.stackTop()) >= precedence(c)) {
                res += st.stackTop();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.isEmpty()) {
        if (st.stackTop() == '(' || st.stackTop() == '{' || st.stackTop() == '[') {
            st.pop();
        } else {
            res += st.stackTop();
            st.pop();
        }
    }
    return res;
}

string infix_to_prefix(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
        else if (s[i] == '{') s[i] = '}';
        else if (s[i] == '}') s[i] = '{';
        else if (s[i] == '[') s[i] = ']';
        else if (s[i] == ']') s[i] = '[';
    }
    string post = infix_to_postfix(s);
    reverse(post.begin(), post.end());
    return post;
}

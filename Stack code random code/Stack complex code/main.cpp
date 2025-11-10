#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== Testing Stack ===" << endl;

    // Create a stack of int with capacity 5
    Stack<int> s1(5);
    cout << "Pushing elements into s1..." << endl;
    for (int i = 1; i <= 5; i++) {
        s1.push(i * 10);
        cout << "Pushed: " << i * 10 << " | Top: " << s1.stackTop() << endl;
    }

    // Copy constructor test
    cout << "\nCreating s2 as a copy of s1..." << endl;
    Stack<int> s2 = s1;  // copy constructor
    cout << "Top of s2: " << s2.stackTop() << endl;

    // Pop from s1 and show s2 remains unchanged
    cout << "\nPopping from s1..." << endl;
    cout << "Popped: " << s1.pop() << endl;
    cout << "New top of s1: " << s1.stackTop() << endl;
    cout << "Top of s2 (should be unchanged): " << s2.stackTop() << endl;

    // Assignment operator test
    cout << "\nCreating s3 and assigning s1 to s3..." << endl;
    Stack<int> s3(5);
    s3 = s1;  // assignment
    cout << "Top of s3: " << s3.stackTop() << endl;

    // Push new element in s1 and check s3 stays unchanged
    cout << "\nPushing 999 into s1..." << endl;
    s1.push(999);
    cout << "Top of s1: " << s1.stackTop() << endl;
    cout << "Top of s3 (should be unchanged): " << s3.stackTop() << endl;

    // Empty the stack s1
    cout << "\nEmptying s1..." << endl;
    while (s1.getTop() >= 0) {
        cout << "Popped: " << s1.pop() << endl;
    }

    cout << "\n=== Tests Finished ===" << endl;
    return 0;
}
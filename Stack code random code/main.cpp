#include "stack.h"
// #include "infix_to_postfix.cpp"
#include <iostream>
using namespace std;

int main(){
    Stack<int> ss;
    ss.push(10);
    ss.push(20);
    ss.push(30);
    cout << ss.pop() << endl; // 30
    cout << ss.pop() << endl; // 20
    cout << ss.getTop() << endl; // 0
    cout << ss.stackTop() << endl; // 10
    cout << ss.isEmpty() << endl; // 0 (false)
    // cout << infix_to_postfix("A++")<<endl;
    // cout << infix_to_prefix("A++")<<endl;
    return 0;
}
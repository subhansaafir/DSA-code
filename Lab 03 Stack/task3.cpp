#include<iostream>
#include<string>
#include "stack.cpp"
using namespace std;

int main(){
    Stack<char> s;

    string exp = "3+3";

    if (s.isValid(exp)){
        cout<<exp<<" is Valid"<<endl;
    }
    else
    {
        cout<<exp<<" is not Valid"<<endl;
    }
    return 0;
}
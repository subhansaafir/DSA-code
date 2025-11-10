#include<iostream>
#include<string>
#include "stack.cpp"
using namespace std;

int main(){
    Stack<char> s;

    string strng;
    cout<<"Enter string form: ";
    getline(cin,strng);

    if (s.isPalindrome(strng)){
        cout<<strng<<" is a palindrome."<<endl;
    }
    else
    {
        cout<<strng<<" is not a palindrome."<<endl;
    }
    return 0;
}
#include<iostream>
#include<string>
#include "stack.cpp"
using namespace std;

int main(){
    Stack<char> s;

    string strng;
    cout<<"Enter word or phrase: ";
    getline(cin,strng);

    if (s.isin_Form(strng)){
        cout<<strng<<" is in a^n*b^n form"<<endl;
    }
    else
    {
        cout<<strng<<" is not in a^n*b^n form"<<endl;
    }
    return 0;
}
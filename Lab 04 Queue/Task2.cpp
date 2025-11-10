#include <iostream>
#include <string>
#include "stack.cpp"
using namespace std;

string reverseEachWord(string s) {
    Stack<char> charStack;
    string result = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            charStack.push(s[i]);
        } else {
            // pop all characters to reverse the current word
            while (!charStack.isEmpty()) {
                result += charStack.getTop();
                charStack.pop();
            }
            result += ' '; // add space after word
        }
    }

    // Pop remaining characters (for the last word)
    while (!charStack.isEmpty()) {
        result += charStack.getTop();
        charStack.pop();
    }

    return result;
}

int main() {
    string st;
    cout << "Enter String: ";
    getline(cin, st);

    cout << "Reversed: " << reverseEachWord(st) << endl;

    return 0;
}



// #include"stack.cpp"

// string reverse(string s){
//     int len = s.length();
//     Stack<char> charstack;

//     for(int i=0; i<len; i++){
//         charstack.push(s[i]);
//     }

//     Stack<string> result;
//     string rword="";
//     while(!charstack.isEmpty()){
//         rword += charstack.getTop();
//         if(charstack.getTop()==' ' || (!charstack.isEmpty())){
//             result.push(s);
//             rword="";
//         }
//         charstack.pop();
//     }

//     string fullfinalresult = "";
//     while(!result.isEmpty()){
//         fullfinalresult += result.getTop();
//         result.pop();
//     }
//     return fullfinalresult;
// }

// int main(){
//     string st;
//     cout<<"Enter String: ";
//     getline(cin,st);

//     cout<<reverse(st)<<endl;

//     return 0;
// }
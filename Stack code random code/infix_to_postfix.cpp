#include <algorithm>
#include "stack.h"
#include <string>
using namespace std;

// bool isValid(string str){
//     stack<char> st;
//     for (int i = 0; i < str.size(); i++)
//     {
//         if(str[i] == '(' || str[i] == '{' || str[i] == '['){
//             st.push(str[i]);
//         }
//         else{
//             if(st.size() == 0){
//                 return false;
//             }
//             if(st.top() == '(' && str[i] == ')' || st.top() == '{' && str[i] == '}' || st.top() == '[' && str[i] == ']'){
//                 st.pop();
//             }
//             else{
//                 return false;
//             }
//         }
//     }
//     return st.size() == 0;
//}

int precedence(char c){
    if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;              //for '(' ')' brackets.
    }
}

string infix_to_postfix(string s){
    Stack<char> st;
    string res = "";

    for (int i = 0; i < (int)s.size(); i++)
    {
        char c = s[i];

        // skip spaces
        if (isspace((unsigned char)c)) continue;

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            res += c;
        }
        else if(c == '(' || c == '{' || c == '['){
            st.push(c);
        }
        else if(c == ')' || c == '}' || c == ']'){
            // find matching opening bracket for this closing one
            char match = (c == ')') ? '(' : (c == '}') ? '{' : '[';
            while (!st.isEmpty() && st.stackTop() != match)
            {
                res += st.stackTop();
                st.pop();
            }
            if(!st.isEmpty()){
                st.pop(); // pop the matching opening bracket
            }
        }
        else
        {
            while(!st.isEmpty() && precedence(st.stackTop()) >= precedence(c))
            {
                res += st.stackTop();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.isEmpty()){
        // skip any leftover opening brackets
        if(st.stackTop() == '(' || st.stackTop() == '{' || st.stackTop() == '['){
            st.pop();
        } else {
            res += st.stackTop();
            st.pop();
        }
    }
    return res;
}

string infix_to_prefix(string s){
    reverse(s.begin(), s.end());
    for(int i = 0; i < (int)s.size(); i++){
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
        else if(s[i] == '{') s[i] = '}';
        else if(s[i] == '}') s[i] = '{';
        else if(s[i] == '[') s[i] = ']';
        else if(s[i] == ']') s[i] = '[';
    }
    // return s;

    // string rev = reverse_and_swap(s);          // step 1
    string post = infix_to_postfix(s);       // step 2
    reverse(post.begin(), post.end());         // step 3
    return post;
}



int main(){
    cout << infix_to_postfix("(A+B)*(C-D)")<<endl;
    cout << infix_to_prefix("(A+B)*(C-D)")<<endl;
    return 0;
}
#include<iostream>
#include<string>
using namespace std;

template <class T>
class Stack {
private:
    T *data;      
    int capacity;  
    int top;     

public:
    Stack() {
        capacity = 100;
        data = new T[capacity];
        top = -1;
    }
    
    Stack(int size) {
        capacity = size;
        data = new T[capacity];
        top = -1;
    }
    
    Stack(const Stack<T> &other) {
        capacity = other.capacity;
        top = other.top;
        data = new T[capacity];
        for (int i = 0; i <= top; i++) {
            data[i] = other.data[i];
        }
    }
    
    Stack<T> &operator=(const Stack<T> &other) {
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
    
    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        data[++top] = value;
    }
    
    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return T(); // return default-constructed T
        }
        return data[top--];
    }
    
    bool isFull() {
        return top == capacity - 1;
    }
    
    bool isEmpty() {
        return top == -1;
    }

    void clear(){
        top = -1;
    }
    
    int getTop() {
        return top;
    }
    
    T stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return data[top];
    }
    
    ~Stack() {
        delete[] data;
    }

    // Task 1
    bool isPalindrome(string word){
        int len = word.length();
        int mid = len/2;

        for(int i=0; i<mid; i++){  // half word ko stack pr push kre ga
            push(word[i]);
        }

        int start=0;
        if(len%2==0){
            start = mid;
        }
        else{
            start = mid + 1;
        }
            
        for(int i=start; i<len; i++){
            if(isEmpty() || word[i] != stackTop()){
                return false;
            }
            pop();
        }
        return isEmpty();
    }

    // Task 2
    bool isin_Form(string word){
        int len = word.length();
        int mid = len/2;

        if(len%2!=0){
            return false;
        }
        else{
            for(int i=0; i<mid; i++){  // half word ko stack pr push kre ga
                push(word[i]);
            }

            for(int i=0; i<(len/4); i++){
                if(isEmpty() || word[i] != stackTop()){
                    return false;
                }
                pop();
            }
            //rest half
            clear();
            for(int i=mid; i<len; i++){  // half word ko stack pr push kre ga
                push(word[i]);
            }
            
            for(int i=mid; i<(mid+(len/4)); i++){
                if(isEmpty() || word[i] != stackTop()){
                    return false;
                }
                pop();
            }
        }
        return true;
    }

    //task 3
    bool isValid(string str){
    Stack<char> s(str.length());

    for(int i=0; i<str.length(); ++i){
        char ch = str[i];

        if(ch=='(' || ch=='{' || ch=='['){
            s.push(ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if (s.isEmpty()){
                return false;
            }
            char topChar = s.stackTop();

            if((ch==')' && topChar !='(') || (ch=='}' && topChar !='{') || (ch==']' && topChar !='[')){
                return false; 
            }
            s.pop();
        }
    }
    return s.isEmpty();
}
};
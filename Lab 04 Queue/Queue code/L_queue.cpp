#include <iostream>
using namespace std;

template <typename T>
class LQueue{
private:
    T* data;
    int capacity;
    int noofelements;

public:
    LQueue(){
        capacity = 5;
        noofelements = 0;  
        data = new T[capacity];
    }

    LQueue(int cap){
        capacity = cap;
        noofelements = 0;  
        data = new T[capacity];
    }

    LQueue(const LQueue& other)
        : capacity(other.capacity), noofelements(other.noofelements) {
        data = new T[capacity];
        for (int i = 0; i < noofelements; ++i) {
            data[i] = other.data[i];
        }
    }

    LQueue& operator=(const LQueue& other){
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            noofelements = other.noofelements;
            data = new T[capacity];
            for (int i = 0; i < noofelements; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~LQueue(){
        delete[] data;
    }

    void enqueue(const T value){
        if (noofelements == capacity){
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        data[noofelements++] = value;
    }

    T dequeue(){
        if (noofelements == 0) {
            cout<<"Queue is empty."<<endl;
            return false;
        }
        T value = data[0];
        for (int i = 1; i < noofelements; ++i) {
            data[i - 1] = data[i];
        }
        noofelements--;
        return value;
    }

    bool isEmpty(){
        return noofelements == 0;
    }

    bool isFull(){
        return noofelements == capacity;
    }

    T top(){
        return data[0];
    }

    T size(){
        return noofelements;
    }
};
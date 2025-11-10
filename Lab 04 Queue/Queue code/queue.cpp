#include <iostream>
using namespace std;

template <typename T>
class Queue {

private:
    int front,rear,noofelements,capacity;
    T* data;

public:

Queue(){
    capacity = 5;
    data = new T[capacity];
    front = 0;
    rear = -1;
    noofelements = 0;
}

Queue(int cap){
    capacity = cap;
    data = new T[capacity];
    front = 0;
    rear = -1;
    noofelements = 0;
}

~Queue(){
    delete[] data;
}

Queue(const Queue<T>& other){
    capacity = other.capacity;
    data = new T[capacity];
    front = other.front;
    rear = other.rear;
    noofelements = other.noofelements;
    for (int i = 0; i < capacity; ++i){
        data[i] = other.data[i];
    }
}

Queue<T>& operator=(const Queue<T>& other){
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        data = new T[capacity];
        front = other.front;
        rear = other.rear;
        noofelements = other.noofelements;
        for (int i = 0; i < capacity; ++i){
            data[i] = other.data[i];
        }
    }
    return *this;
}


bool isEmpty(){
    return noofelements == 0;
}

bool isFull(){
    return noofelements == capacity;
}

void enqueue(T value){
    if(isFull()){
        cout<<"Queue is full, can't able to add value: "<<value<<endl;
        return;
    }
    rear = (rear + 1) % capacity;
    data[rear] = value;
    noofelements++;
}

T dequeue(){
    if(isEmpty()){
        cout << "Queue is empty!" << endl;
        return T();
    }
    T value = data[front];
    front = (front + 1) % capacity;
    noofelements--;
    return value;
}

T peek(){
    if(isEmpty()){
        cout << "Queue is empty!" << endl;
        return T();
    }
    return data[front];
}

void display(){
    if (isEmpty()){
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = 0; i < noofelements; i++){
        cout << data[(front + i) % capacity] << " ";
    }
    cout << endl;
}
};
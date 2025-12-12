#include<iostream>
using namespace std;

  
class Student { 
 
public: 
    double cgpa;  // Student’s CGPA  
    int rollNo;   // Student’s roll number  
    Student() { 
        cgpa = 0.0; 
        rollNo = 0; 
    } 
    Student(int r, double c) { 
        rollNo = r; 
        cgpa = c; 
    } 
}; 

class StudentMaxHeap { 
private: 
    Student* st; 
    int currSize;
    int maxSize;  
 
    bool isGreater(const Student& a, const Student& b){

        if(a.cgpa > b.cgpa){
            return true;
        }
        else if(a.cgpa == b.cgpa || a.rollNo < b.rollNo){
            return false;
        }
    }

    void heapifyUp(int i){
        if(i == 0){
            return;
        }

        int parent = (i - 1)/2;
        if(isGreater(st[i], st[parent])){
            swap(st[i], st[parent]);
            heapifyUp(parent);
        }

    }

    void heapifyDown(int i){
        int largest = i;
        int leftChild = 2*i+ 1;
        int rightChild = 2*i+2;

        if(leftChild < currSize && isGreater(st[leftChild],st[largest])){
            largest = leftChild;
        }
        if(rightChild < currSize && isGreater(st[rightChild],st[largest])){
            largest = rightChild;
        }
        if(largest != i){
            swap(st[i], st[largest]);
            heapifyDown(largest);
        }
    }
 
public: 
    StudentMaxHeap(int size){
        st = new Student[size];
        currSize = 0;
        maxSize = size;
    }

    ~StudentMaxHeap(){
        delete [] st;
    }
    bool isEmpty(){
        return currSize == 0;
    }

    bool isFull(){
        return currSize == maxSize;
    }

    bool insert (int rollNo, double cgpa){
        if(isFull()){
            return false;
        }
        Student s(rollNo,cgpa);

        st[currSize]=s;
        currSize++;
        heapifyUp(currSize-1);
        return true;
    }


    bool removeBestStudent (int& rollNo, double& cgpa){
        
    }

    void levelOrder(){
        for(int i=0; i<currSize; i++){
            cout<<"Roll No: "<<st[i].rollNo<<", CGPA: "<<st[i].cgpa<<endl;
        }
    } 

    int height(){
        if(isEmpty()){
            return -1;
        }

        int h=0;
        int node = 1;
        while(node <= currSize){
            h++;
            node = node *2;
        }
        return h-1;
    }
}; 


int main() { 
    StudentMaxHeap heap(20); 
    heap.insert(10, 3.2); 
    heap.insert(5, 3.9); 
    heap.insert(12, 3.5); 
    heap.insert(3, 3.9);   // Same CGPA as roll 5 (tie-break: smaller roll first) 
    heap.insert(7, 2.8); 
    heap.insert(18, 3.7); 
    heap.insert(1, 4.0);   // Highest CGPA 
    heap.insert(20, 3.4); 
    heap.insert(11, 3.7);  // Same CGPA as roll 18 (tie-break) 
    heap.insert(4, 3.8); 
    cout << "===== Level Order After Insertions =====\n"; 
    heap.levelOrder(); 
    cout << endl;
    cout << "\nHeight of the heap: " << heap.height() << endl; 
 
    // // ---- Remove top student twice ---- 
    // int roll; 
    // double cg; 
 
    // if (heap.removeBestStudent(roll, cg)) { 
    //     cout << "Removed Student - Roll No: " << roll 
    //          << ", CGPA: " << cg << endl; 
    // } 
 
    // if (heap.removeBestStudent(roll, cg)) { 
    //     cout << "Removed Student - Roll No: " << roll 
    //          << ", CGPA: " << cg << endl; 
    // } 
 
    // cout << "\n===== Level Order After Two Removals =====\n"; 
    // heap.levelOrder(); 
 
    // cout << "\nHeight of the heap: " << heap.height() << endl; 
 
    return 0; 
} 
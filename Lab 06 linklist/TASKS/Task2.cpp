#include <iostream>
using namespace std;

class Node{
public:    
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;

    }
};

class List{
    Node* head; // head pointer
    Node* tail;  //tail pointer    

public:
    List(){
        head = NULL;
        tail = NULL;  // declare both null at start
    }

    ~List(){
        delete head;
        delete tail;
    }

    void pushfront(int val){   //O(1)
        Node* newNode = new Node(val); //create new node when add

        if(head == NULL){  //if list empty, both 
            head= newNode;
            tail= newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void print(){      //O(n)
        Node* temp = head;

        while(temp != NULL){
            cout<< temp->data <<" -> ";
            temp = temp->next;   //next node ka address to print val  
        }
        cout <<"NULL" <<endl;
    }

void combineList(List& l1, List& l2) {
    head = NULL;
    tail = NULL;

    if(l1.head != NULL){
        head = l1.head;
        tail = l1.tail;
        l1.head = NULL;
        l1.tail = NULL;  //original l1 list NULL hogyi
    }

    if(l2.head != NULL){
        if(head == NULL){
            head = l2.head;
            tail = l2.tail;
        }
        else{
            tail->next = l2.head;
            tail = l2.tail;
        }
        l2.head = NULL;
        l2.tail = NULL;  //l2 ko bhi NULL empty
    }
}

};


int main(){
    List l1;
    l1.pushfront(1);
    l1.pushfront(4);
    l1.pushfront(3);
    l1.pushfront(8);
    l1.print();
    List l2;
    l2.pushfront(3);
    l2.pushfront(1);
    l2.pushfront(2);
    l2.print();

    List l3;
    l3.combineList(l1,l2);
    l3.print();
    return 0;
}
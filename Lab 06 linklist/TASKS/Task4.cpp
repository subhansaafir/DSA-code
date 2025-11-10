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

    void reverselist(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        tail = head;
        head = prev;
    }
};

int main(){
    List l1;
    l1.pushfront(1);
    l1.pushfront(2);
    l1.pushfront(3);
    l1.pushfront(4);
    l1.pushfront(5);
    l1.pushfront(6);
    l1.print();

    l1.reverselist();
    l1.print();
    return 0;
}
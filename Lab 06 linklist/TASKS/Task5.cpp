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

    void removeduplicates(){
    if (head == NULL || head->next == NULL){
        return;
    }

    Node* curr = head;
    while(curr != NULL){
        Node* check = curr;
        while(check->next != NULL){
            if(curr->data == check->next->data){
                Node* temp = check->next;
                check->next = check->next->next;
                delete temp;
            }
            else{
                check = check->next;
            }
        }
        curr = curr->next;
    }
}
};

int main(){
    List l1;
    l1.pushfront(1);
    l1.pushfront(2);
    l1.pushfront(3);
    l1.pushfront(4);
    l1.pushfront(3);
    l1.pushfront(2);
    l1.print();

    l1.removeduplicates();
    l1.print();
    return 0;
}
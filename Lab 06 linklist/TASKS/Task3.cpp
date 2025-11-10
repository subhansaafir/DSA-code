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

    Node* getHead(){
        return head;
    }

    void print(){      //O(n)
        Node* temp = head;

        while(temp != NULL){
            cout<< temp->data <<" -> ";
            temp = temp->next;   //next node ka address to print val  
        }
        cout <<"NULL" <<endl;
    }

    void shufflemerge(List& l1, List& l2){
        if (l1.head == NULL) {
            head = l2.head;
            l2.head = NULL;
            return;
        }
        if (l2.head == NULL) {
            head = l1.head;
            l1.head = NULL;
            return;
        }

        Node* curr1 = l1.head;
        Node* curr2 = l2.head;
        Node* next1;
        Node* next2;

        // Start with first list
        head = curr1;
        while (curr1 != NULL && curr2 != NULL) {
            // Save next pointers
            next1 = curr1->next;
            next2 = curr2->next;

            // Link current nodes
            curr1->next = curr2;
            if (next1 != NULL) {
                curr2->next = next1;
            }

            // Move to next pair of nodes
            curr1 = next1;
            curr2 = next2;
        }

        // Clear the original lists
        l1.head = NULL;
        l2.head = NULL;
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
    l2.pushfront(1);
    l2.pushfront(4);
    l2.pushfront(3);
    l2.pushfront(8);
    l2.print();

    List l3;
    l3.shufflemerge(l1,l2);
    l3.print();
    return 0;
}



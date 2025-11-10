#include <iostream>
#include <unordered_set>
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


    int search(int key){     //O(n)
        Node* temp = head;
        int idx = 0;

        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1; //means have not find the key in the list
    }

    int countNodes(){
        int count = 0;
        Node* temp = head;
        while (temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool removekthNode(int k){

    int n = countNodes();
    if(k>n){
        return false;
    }

    Node* prev = head;
    for(int i=0; i< k-1; ++i){
        prev = prev->next;
    }

    Node* temp = prev->next;
    prev->next = temp->next;
    if (temp == tail){
        tail = prev;
    }
    delete temp;
    return true;
}

};

int main() {
    List l1;
    l1.pushfront(4);
    l1.pushfront(2);
    l1.pushfront(8);
    l1.pushfront(1);
    l1.pushfront(9);
    l1.pushfront(5);
    l1.pushfront(4);
    l1.pushfront(6);

    l1.print();

    l1.removekthNode(4);
    l1.print();

    return 0;
}

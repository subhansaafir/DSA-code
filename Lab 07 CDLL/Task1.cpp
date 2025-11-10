#include <iostream>
using namespace std;

class DNode{
public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class CDLinkedList{
private:
    DNode* head;

public:
    CDLinkedList(){
        head = NULL;
    }

    ~CDLinkedList(){
        if (head == NULL) return;
        
        DNode* current = head;
        DNode* nextNode;
        
        do{
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
        
        head = NULL;
    }

    void insertAtHead(int val){
        DNode* newNode = new DNode(val);
        
        if(head == NULL){
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        }
        else{
            DNode* tail = head->prev;
            
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(int val){
        DNode* newNode = new DNode(val);
        
        if (head == NULL){
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        }
        else{
            DNode* tail = head->prev;
            
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
        }
    }

    void removeAtHead(){
        if (head == NULL){
            cout << "List is empty!" << endl;
            return;
        }
        
        if (head->next == head){
            delete head;
            head = NULL;
        } 
        else{
            DNode* tail = head->prev;
            DNode* temp = head;
            
            head = head->next;
            head->prev = tail;
            tail->next = head;
            
            delete temp;
        }
    }

    void removeAtTail(){
        if (head == NULL){
            cout << "List is empty!" << endl;
            return;
        }
        
        if (head->next == head){
            delete head;
            head = NULL;
        } 
        else{
            DNode* tail = head->prev;
            DNode* newTail = tail->prev;
            
            newTail->next = head;
            head->prev = newTail;
            
            delete tail;
        }
    }

    void display(){
        if (head == NULL){
            cout << "List is empty!" << endl;
            return;
        }
        
        DNode* current = head;
        
        cout << "List: ";
        do {
            cout << current->data;
            if (current->next != head) {
                cout << " <=> ";
            }
            current = current->next;
        } while (current != head);
        cout << " <=> (back to " << head->data << ")" << endl;
    }

    void merge(CDLinkedList& list1,CDLinkedList& list2){
        DNode* head1 = list1.head;
        DNode* head2 = list2.head;

        if (head1 == NULL && head1 == NULL){
            head = NULL;
            return;
        }
        if (head1 == NULL){
            head = head2;
            list2.head = NULL;
            list1.head = NULL;
            return;
        }
        if (head2 == NULL){
            head = head1;
            list1.head = NULL;
            list2.head = NULL;
            return;
        }

        DNode* tail1 = head1->prev;
        DNode* tail2 = head2->prev;  //head1 aur head2 ke prev == Null, 
        tail1->next = NULL;          // aur tail1, tail2 ke next ko NUll, yani tail khud ko point kr rahi
        head1->prev = NULL;
        tail2->next = NULL;
        head2->prev = NULL;         // now abhi circular nahi ahi

        
        
    }
};

int main(){
    CDLinkedList list1,list2;

    list1.insertAtTail(4);
    list1.insertAtTail(7);
    list1.insertAtTail(10);
    list1.insertAtTail(11);
    list1.display();

    list2.insertAtTail(1);
    list2.insertAtTail(3);
    list2.insertAtTail(6);
    list2.insertAtTail(8);
    list2.insertAtTail(15);
    list2.display();

    CDLinkedList list3;

    list3.merge(list1,list2);
    list3.display();
    return 0;
}
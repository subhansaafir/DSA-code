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

    int countNodes(){
        if (head == NULL) return 0;
        
        int count = 0;
        DNode* current = head;
        
        do {
            count++;
            current = current->next;
        } while (current != head);
        
        return count;
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

    void splitList(CDLinkedList& leftHalf, CDLinkedList& rightHalf){
        int count = countNodes();
        int mid = count/2;

        leftHalf.head = head;
        for(int i =0; i < mid; i++){
            head = head->next;
        }

        rightHalf.head = head;
        
        DNode* secondhead = rightHalf.head;
        DNode* secondtail = secondhead->next->next->next->next;
        secondhead->prev = secondtail;

        for(int i =0; i < mid; i++){
            secondhead = secondhead->next;
        }

        DNode* secondtail = secondhead;
    }
};

int main(){
    CDLinkedList list1;

    list1.insertAtTail(4);
    list1.insertAtTail(7);
    list1.insertAtTail(10);
    list1.insertAtTail(11);
    list1.insertAtTail(20);
    list1.insertAtTail(30);
    list1.insertAtTail(40);
    list1.insertAtTail(50);
    list1.display();

    CDLinkedList list2,list3;
    list1.splitList(list1,list2);

    list2.display();
    list3.display();
    return 0;
}
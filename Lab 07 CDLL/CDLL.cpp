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

    void remove(int val){
        if (head == NULL){
            cout << "List is empty!" << endl;
            return;
        }
        
        DNode* current = head;
        
        do{
            if (current->data == val){
                if (current == head && current->next == head){
                    delete head;
                    head = NULL;
                    return;
                } else if (current == head) {
                    removeAtHead();
                    return;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    return;
                }
            }
            current = current->next;
        } while (current != head);
        
        cout << "Value " << val << " not found!" << endl;
    }

    bool search(int key) {
        if (head == NULL) return false;
        
        DNode* current = head;
        
        do {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        } while (current != head);
        
        return false;
    }

    void update(int key, int val){
        if (head == NULL){
            cout << "List is empty!" << endl;
            return;
        }
        
        DNode* current = head;
        
        do{
            if (current->data == key){
                current->data = val;
                cout << "Updated " << key << " to " << val << endl;
                return;
            }
            current = current->next;
        } while (current != head);
        
        cout << "Key " << key << " not found!" << endl;
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


};

int main() {
    CDLinkedList list;
    
    list.insertAtHead(5);
    list.insertAtHead(10);
    list.insertAtHead(15);
    list.display();
    
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.display();
    
    cout <<"\nTotal nodes: " <<list.countNodes()<< endl;

    cout <<"\nSearching for 20: " << (list.search(20) ? "Found" : "Not found") << endl;
    cout <<"Searching for 100: " << (list.search(100) ? "Found" : "Not found") << endl;
    
    cout <<"\nUpdating 20 to 25" << endl;
    list.update(20, 25);
    list.display();
    
    cout <<"\nRemoving at head" << endl;
    list.removeAtHead();
    list.display();
    
    cout <<"\nRemoving at tail" << endl;
    list.removeAtTail();
    list.display();
    
    cout << "\nRemoving value 25" << endl;
    list.remove(25);
    list.display();
    
    cout << "\nFinal node count: " << list.countNodes() << endl;
    
    return 0;
}
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

    void pushback(int val){   //O(1)
        Node* newNode = new Node(val); //create new node when add

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void popfront(){    //O(1)
        if (head == NULL){
            cout<<"List is empty"<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;

    }

    void popback(){     //O(n)
        if(head == NULL){
            cout<<"list is Empty"<<endl;
            return;
        }

        if(head == tail){  
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node* temp = head;

        while(temp->next != tail){   //temp ke next ka next; (temp->next->next == Null) (2nd last node)
             temp = temp->next;  // aage aage jate jayo, jab tk 2nd last node na aajaye

        }
        temp->next = NULL; //end last ko null kr do
        delete tail;
        tail = temp;  // now new tail is 2nd last node
    }

    void insert(int val, int pos){    //O(n)
        if (pos<0){
            cout<<"Invalid position"<<endl;
            return;
        }

        if (pos==0){
            pushfront(val);
            return;
        }

        Node*temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp == NULL){
                cout <<"Invalid position, size of list is small"<<endl;
                return;
            }
            temp = temp->next;     // now we have the address of node, where we add new node
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
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


//Now (task 4)
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

        // update head and tail
        tail = head;
        head = prev;
    }

//returning the middle node of list--------------
    Node* middlenode(){
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL  &&  fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

// Detect cycle in the list
    bool hascycle(){
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL  &&  fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                return true;
            }
        }

        return false;
    }

// Cycle starting node detection
    Node* detectcyclestart(){
        Node* slow = head;
        Node* fast = head;
        bool cyclepresent = false;
        
        while(fast != NULL  &&  fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                cyclepresent = true;
                break;
            }
        }

        if(cyclepresent == false){
            return NULL; // no cycle
        }

        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // starting node of cycle
    }

    ~List(){
        delete head;
        delete tail;
    }

    Node* getHead(){
        return head;
    }
    void setHead(Node* h){
        head = h;
    }
};

//--------------------------------------------------------------------------------------------------------
//Now reverselist question, reverse the connections

// Node* reverseList(Node* head){
//     Node* prev = NULL;
//     Node* curr = head;
//     Node* next = NULL;

//     while(curr != NULL){
//         next = curr->next;
//         curr->next = prev;

//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }

// Merge two sorted lists
Node* mergetwolist(Node* head1, Node* head2){
    // base condition
    if (head1==NULL){
        return head2;
    }
    if (head2==NULL){
        return head1;
    }

    //case 1
    if (head1->data <= head2->data){
        head1->next = mergetwolist(head1->next,head2);
        return head1;
    }
    else{ //case 2
        head2->next = mergetwolist(head1,head2->next);
        return head2;
    }
}

// int main(){
//     List l;
//     l.pushfront(1);
//     l.pushfront(2);
//     l.pushfront(3);
//     l.pushback(4);
//     l.print();
//     l.popfront();
//     l.print();
//     l.popback();
//     l.print();
    
//     l.insert(10, 1);
//     l.print();
    
//     l.pushback(5);
//     l.pushback(19);
//     l.print();

//     cout <<"This val is at index: "<< l.search(5)<<endl;
//     l.print();

//     l.reverselist();
//     l.print();

//     l.hascycle() ? cout<<"Cycle is present"<<endl : cout<<"No Cycle"<<endl;

//     Node* mid = l.middlenode();
//     cout <<"Middle node data is: "<< mid->data<<endl;

// // //Only if  merge and get new head
// // Node* mergedHead = l1.mergetwolist(l1.getHead(), l2.getHead());

// // // print merged list
// // Node* temp = mergedHead;
// // while(temp != NULL){
// //     cout << temp->data << " -> ";
// //     temp = temp->next;
// // }
// // cout << "NULL" << endl;

//     return 0;
// }


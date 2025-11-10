#include <iostream>
using namespace std;

// ========================
// Node Class (Template)
// ========================
template <class T>
class Node
{
public:
    T info;
    Node<T>* next;

    Node()            // Default constructor
    {
        next = nullptr;
    }

    Node(T val)       // Parameterized constructor
    {
        info = val;
        next = nullptr;
    }
};

// ========================
// LSLL Class (Template)
// ========================
template <class T>
class LSLL
{
private:
    Node<T>* head;

public:
    LSLL()    // Constructor
    {
        head = nullptr;
    }

    // ========================
    // Insertion Functions
    // ========================

    // Insert at beginning of list
    void insertAtHead(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end of list
    void insertAtTail(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node<T>* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    // Insert a new node before a given key
    void insertBefore(T key, T val)
    {
        if (head == nullptr)
            return;

        // If the key is at head
        if (head->info == key)
        {
            insertAtHead(val);
            return;
        }

        Node<T>* prev = nullptr;
        Node<T>* curr = head;
        while (curr != nullptr && curr->info != key)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) return; // key not found

        Node<T>* newNode = new Node<T>(val);
        prev->next = newNode;
        newNode->next = curr;
    }

    // Insert a new node after a given key
    void insertAfter(T key, T val)
    {
        Node<T>* curr = head;
        while (curr != nullptr && curr->info != key)
            curr = curr->next;

        if (curr == nullptr) return; // key not found

        Node<T>* newNode = new Node<T>(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    // ========================
    // Deletion Functions
    // ========================

    // Remove node at head
    void removeAtHead()
    {
        if (head == nullptr) return;

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    // Remove node at tail
    void removeAtTail()
    {
        if (head == nullptr) return;

        // Only one node
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* prev = nullptr;
        Node<T>* curr = head;
        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;
        delete curr;
    }

    // Remove node with given value
    void remove(T val)
    {
        if (head == nullptr) return;

        // If head node contains value
        if (head->info == val)
        {
            removeAtHead();
            return;
        }

        Node<T>* prev = nullptr;
        Node<T>* curr = head;
        while (curr != nullptr && curr->info != val)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) return; // not found

        prev->next = curr->next;
        delete curr;
    }

    // Remove node before a given value
    void removeBefore(T val)
    {
        if (head == nullptr || head->info == val) return;

        Node<T>* prevPrev = nullptr;
        Node<T>* prev = head;
        Node<T>* curr = head->next;

        while (curr != nullptr && curr->info != val)
        {
            prevPrev = prev;
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) return; // key not found

        // remove prev
        if (prevPrev == nullptr)
        {
            // removing head
            removeAtHead();
        }
        else
        {
            prevPrev->next = curr;
            delete prev;
        }
    }

    // Remove node after a given value
    void removeAfter(T val)
    {
        Node<T>* curr = head;
        while (curr != nullptr && curr->info != val)
            curr = curr->next;

        if (curr == nullptr || curr->next == nullptr) return;

        Node<T>* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    // ========================
    // Utility Functions
    // ========================

    // Search for a value, return its index (0-based), -1 if not found
    int search(T key)
    {
        int index = 0;
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            if (temp->info == key)
                return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    // Update node value
    void update(T key, T val)
    {
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            if (temp->info == key)
            {
                temp->info = val;
                return;
            }
            temp = temp->next;
        }
    }

    // Count total nodes
    int countNodes()
    {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display list
    void display()
    {
        Node<T>* temp = head;
        while (temp != nullptr)
        {
            cout << temp->info << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // ========================
    // Destructor
    // ========================
    ~LSLL()
    {
        while (head != nullptr)
            removeAtHead();
    }
};

// ========================
// Main Function (Testing)
// ========================
int main()
{
    LSLL<int> list;

    // Insertions
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtTail(40);
    list.insertAfter(30, 35);
    list.insertBefore(20, 10);

    cout << "List after insertions: ";
    list.display();

    // Deletions
    list.removeAtHead();
    list.removeAtTail();
    list.remove(35);
    list.removeBefore(30);
    list.removeAfter(20);

    cout << "List after deletions: ";
    list.display();

    // Search, Update, Count
    cout << "Index of 30: " << list.search(30) << endl;
    list.update(30, 300);
    cout << "List after updating 30 to 300: ";
    list.display();

    cout << "Total nodes: " << list.countNodes() << endl;

    return 0;
}

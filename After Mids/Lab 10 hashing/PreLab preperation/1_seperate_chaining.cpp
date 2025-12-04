#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class HashTable {
public:
    Node** table;
    int size;

    HashTable(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insertItem(int key) {
        int idx = hashFunction(key);

        Node* newNode = new Node();
        newNode->data = key;
        newNode->next = table[idx];

        table[idx] = newNode;
    }

    bool searchItem(int key) {
        int idx = hashFunction(key);
        Node* temp = table[idx];

        while (temp != NULL) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void deleteItem(int key) {
        int idx = hashFunction(key);
        Node* temp = table[idx];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->data == key) {
                if (prev == NULL) 
                    table[idx] = temp->next;
                else 
                    prev->next = temp->next;

                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void printTable() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable ht(10);

    ht.insertItem(10);
    ht.insertItem(20);
    ht.insertItem(15);
    ht.insertItem(7);

    ht.printTable();
    return 0;
}

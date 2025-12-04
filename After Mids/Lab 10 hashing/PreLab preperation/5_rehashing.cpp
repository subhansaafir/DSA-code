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
    int elements;

    HashTable(int s) {
        size = s;
        elements = 0;
        table = new Node*[size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    int hashFunction(int key) {
        return key % size;
    }

    double loadFactor() {
        return (double)elements / size;
    }

    // ---------- REHASH FUNCTION ----------
    void rehash() {
        int oldSize = size;
        size = size * 2;

        Node** oldTable = table;
        table = new Node*[size];

        for (int i = 0; i < size; i++)
            table[i] = NULL;

        elements = 0;

        // move old keys into new table
        for (int i = 0; i < oldSize; i++) {
            Node* temp = oldTable[i];
            while (temp != NULL) {
                insertItem(temp->data);
                temp = temp->next;
            }
        }

        delete[] oldTable;
    }

    void insertItem(int key) {
        if (loadFactor() > 0.7) {
            cout << "Rehashing... (new size = " << size * 2 << ")\n";
            rehash();
        }

        int idx = hashFunction(key);

        Node* newNode = new Node();
        newNode->data = key;
        newNode->next = table[idx];

        table[idx] = newNode;
        elements++;
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
    HashTable h(5);

    for (int i = 1; i <= 20; i++) {
        h.insertItem(i);
    }

    h.printTable();
    return 0;
}

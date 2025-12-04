#include <iostream>
using namespace std;

class HashTable {
    static const int SIZE = 7;
    int table[SIZE];
    int probingType;        // 1 = Linear, 2 = Quadratic, 3 = Double Hashing
    const int EMPTY = -1;
    const int DELETED = -2;

public:
    HashTable(int type) {
        probingType = type;
        for (int i = 0; i < SIZE; i++)
            table[i] = EMPTY;
    }

    int h1(int key) {
        return key % SIZE;
    }

    int h2(int key) {   // Only for double hashing
        return 5 - (key % 5);
    }

    void insert(int key) {
        int index = h1(key);
        int i = 1;
        int start = index;
        bool inserted = false;

        do {
            if (table[index] == EMPTY || table[index] == DELETED) {
                table[index] = key;
                inserted = true;
                break;
            }

            // Collision resolution
            if (probingType == 1) index = (index + 1) % SIZE;            // Linear
            else if (probingType == 2) index = (h1(key) + i * i++) % SIZE; // Quadratic
            else index = (h1(key) + i++ * h2(key)) % SIZE;                // Double hashing

        } while (index != start);

        if (!inserted)
            cout << "Hash table is full! Cannot insert " << key << "\n";
    }

    bool search(int key) {
        int index = h1(key);
        int i = 1;
        int start = index;

        do {
            if (table[index] == EMPTY)
                return false;
            if (table[index] == key)
                return true;

            if (probingType == 1) index = (index + 1) % SIZE;
            else if (probingType == 2) index = (h1(key) + i * i++) % SIZE;
            else index = (h1(key) + i++ * h2(key)) % SIZE;

        } while (index != start);

        return false;
    }

    void deleteItem(int key) {
        int index = h1(key);
        int i = 1;
        int start = index;

        do {
            if (table[index] == EMPTY)
                return;
            if (table[index] == key) {
                table[index] = DELETED;
                return;
            }

            if (probingType == 1) index = (index + 1) % SIZE;
            else if (probingType == 2) index = (h1(key) + i * i++) % SIZE;
            else index = (h1(key) + i++ * h2(key)) % SIZE;

        } while (index != start);
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            if (table[i] == EMPTY) cout << "EMPTY";
            else if (table[i] == DELETED) cout << "DELETED";
            else cout << table[i];
            cout << "\n";
        }
    }
};

int main() {
    int choice;
    cout << "Choose Probing Method:\n1. Linear\n2. Quadratic\n3. Double Hashing\n";
    cin >> choice;

    HashTable ht(choice);

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nChoose: ";
        int op;
        cin >> op;

        if (op == 1) {
            int key;
            cout << "Enter key: ";
            cin >> key;
            ht.insert(key);
        } 
        else if (op == 2) {
            int key;
            cout << "Search key: ";
            cin >> key;
            cout << (ht.search(key) ? "Found\n" : "Not Found\n");
        } 
        else if (op == 3) {
            int key;
            cout << "Delete key: ";
            cin >> key;
            ht.deleteItem(key);
        } 
        else if (op == 4) {
            ht.display();
        } 
        else break;
    }

    return 0;
}
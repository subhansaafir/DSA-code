#include <iostream>
using namespace std;

class LinearProbing {
public:
    int* table;
    int size;

    LinearProbing(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;  // empty
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insertItem(int key) {
        int idx = hashFunction(key);

        while (table[idx] >= 0) {  // occupied or tombstone?
            idx = (idx + 1) % size;
        }

        table[idx] = key;
    }

    bool searchItem(int key) {
        int idx = hashFunction(key);
        int start = idx;

        while (table[idx] != -1) { // stop only at EMPTY slot
            if (table[idx] == key)
                return true;

            idx = (idx + 1) % size;
            if (idx == start) break;
        }
        return false;
    }

    // -------------- DELETE USING TOMBSTONE (-2) --------------
    void deleteItem(int key) {
        int idx = hashFunction(key);
        int start = idx;

        while (table[idx] != -1) {
            if (table[idx] == key) {
                table[idx] = -2;   // tombstone
                return;
            }

            idx = (idx + 1) % size;
            if (idx == start) break;
        }

        cout << "Key not found\n";
    }

    void printTable() {
        for (int i = 0; i < size; i++) {
            cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    LinearProbing h(7);

    h.insertItem(10);
    h.insertItem(20);
    h.insertItem(15);
    h.insertItem(7);

    cout << "Before deletion:\n";
    h.printTable();

    h.deleteItem(15);

    cout << "After deletion of 15:\n";
    h.printTable();

    cout << "Search 20: " << h.searchItem(20) << endl;
    return 0;
}

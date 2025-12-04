#include <iostream>
using namespace std;

class QuadraticProbing {
public:
    int* table;
    int size;

    QuadraticProbing(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;   // empty
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insertItem(int key) {
        int idx = hashFunction(key);
        int i = 0;

        while (table[(idx + i*i) % size] >= 0) { // occupied or tombstone
            i++;
        }

        table[(idx + i*i) % size] = key;
    }

    bool searchItem(int key) {
        int idx = hashFunction(key);
        int i = 0;

        while (table[(idx + i*i) % size] != -1) {  // -1 means EMPTY only
            if (table[(idx + i*i) % size] == key)
                return true;
            i++;
        }
        return false;
    }

    void deleteItem(int key) {
        int idx = hashFunction(key);
        int i = 0;

        while (table[(idx + i*i) % size] != -1) {
            int pos = (idx + i*i) % size;

            if (table[pos] == key) {
                table[pos] = -2;   // tombstone
                return;
            }
            i++;
        }

        cout << "Key not found\n";
    }

    void printTable() {
        for (int i = 0; i < size; i++)
            cout << i << ": " << table[i] << endl;
    }
};

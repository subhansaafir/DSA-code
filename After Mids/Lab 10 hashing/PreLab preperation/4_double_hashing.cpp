#include <iostream>
using namespace std;

class DoubleHashing {
public:
    int* table;
    int size;

    DoubleHashing(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;
    }

    int h1(int key) { return key % size; }
    int h2(int key) { return 7 - (key % 7); }  // 2nd hash must be non-zero

    void insertItem(int key) {
        int idx = h1(key);
        int step = h2(key);
        int i = 0;

        while (table[(idx + i * step) % size] >= 0) {
            i++;
        }

        table[(idx + i * step) % size] = key;
    }

    bool searchItem(int key) {
        int idx = h1(key);
        int step = h2(key);
        int i = 0;

        while (table[(idx + i * step) % size] != -1) {
            if (table[(idx + i * step) % size] == key)
                return true;
            i++;
        }
        return false;
    }

    void deleteItem(int key) {
        int idx = h1(key);
        int step = h2(key);
        int i = 0;

        while (table[(idx + i * step) % size] != -1) {
            int pos = (idx + i * step) % size;

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

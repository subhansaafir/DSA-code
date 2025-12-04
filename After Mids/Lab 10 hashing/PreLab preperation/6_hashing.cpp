#include <iostream>
using namespace std;

// ==========================
// 1. SEPARATE CHAINING
// ==========================
struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(NULL) {}
};

class ChainingHash {
public:
    int size;
    Node** table;

    ChainingHash(int s) {
        size = s;
        table = new Node*[size];
        for(int i=0;i<size;i++) table[i] = NULL;
    }

    int hash(int key) { return key % size; }

    void insertKey(int key) {
        int idx = hash(key);
        Node* n = new Node(key);
        n->next = table[idx];
        table[idx] = n;
    }

    bool searchKey(int key) {
        int idx = hash(key);
        Node* p = table[idx];
        while(p) {
            if(p->key == key) return true;
            p = p->next;
        }
        return false;
    }

    void deleteKey(int key) {
        int idx = hash(key);
        Node* p = table[idx];
        Node* prev = NULL;
        while(p) {
            if(p->key == key) {
                if(prev) prev->next = p->next;
                else table[idx] = p->next;
                delete p;
                return;
            }
            prev = p;
            p = p->next;
        }
    }

    void print() {
        for(int i=0;i<size;i++){
            cout<<i<<" : ";
            Node* p = table[i];
            while(p){ cout<<p->key<<" -> "; p=p->next; }
            cout<<"NULL\n";
        }
    }
};

// ==========================
// 2. LINEAR PROBING
// ==========================
class LinearHash {
public:
    int size;
    int *table;
    int count;

    LinearHash(int s){
        size=s;
        table=new int[size];
        for(int i=0;i<size;i++) table[i]=-1;
        count=0;
    }

    int hash(int key){ return key%size; }

    void insertKey(int key){
        int idx = hash(key);
        for(int i=0;i<size;i++){
            int pos = (idx + i) % size;
            if(table[pos] == -1 || table[pos] == -2){
                table[pos] = key;
                count++;
                return;
            }
        }
    }

    bool searchKey(int key){
        int idx = hash(key);
        for(int i=0;i<size;i++){
            int pos = (idx + i) % size;
            if(table[pos] == -1) return false;
            if(table[pos] == key) return true;
        }
        return false;
    }

    void deleteKey(int key){
        int idx = hash(key);
        for(int i=0;i<size;i++){
            int pos = (idx + i) % size;
            if(table[pos] == -1) return;
            if(table[pos] == key){ table[pos] = -2; return; }
        }
    }

    void print(){ for(int i=0;i<size;i++) cout<<i<<":"<<table[i]<<"\n"; }
};

// ==========================
// 3. QUADRATIC PROBING
// ==========================
class QuadraticHash{
public:
    int size;
    int *table;

    QuadraticHash(int s){
        size=s;
        table=new int[size];
        for(int i=0;i<size;i++) table[i]=-1;
    }

    int hash(int key){ return key%size; }

    void insertKey(int key){
        int idx = hash(key);
        for(int i=0;i<size;i++){
            int pos = (idx + i*i) % size;
            if(table[pos] == -1 || table[pos] == -2){ table[pos]=key; return; }
        }
    }

    bool searchKey(int key){
        int idx=hash(key);
        for(int i=0;i<size;i++){
            int pos=(idx+i*i)%size;
            if(table[pos]==-1) return false;
            if(table[pos]==key) return true;
        }
        return false;
    }

    void deleteKey(int key){
        int idx=hash(key);
        for(int i=0;i<size;i++){
            int pos=(idx+i*i)%size;
            if(table[pos]==-1) return;
            if(table[pos]==key){ table[pos] = -2; return; }
        }
    }

    void print(){ for(int i=0;i<size;i++) cout<<i<<":"<<table[i]<<"\n"; }
};

// ==========================
// 4. DOUBLE HASHING
// ==========================
class DoubleHash{
public:
    int size;
    int *table;

    DoubleHash(int s){
        size=s;
        table=new int[size];
        for(int i=0;i<size;i++) table[i]=-1;
    }

    int hash1(int key){ return key % size; }
    int hash2(int key){ return 7 - (key % 7); }

    void insertKey(int key){
        int i=0;
        int idx1 = hash1(key);
        int idx2 = hash2(key);
        while(i < size){
            int pos = (idx1 + i*idx2) % size;
            if(table[pos] == -1 || table[pos] == -2){ table[pos] = key; return; }
            i++;
        }
    }

    bool searchKey(int key){
        int i=0;
        int idx1 = hash1(key);
        int idx2 = hash2(key);
        while(i < size){
            int pos = (idx1 + i*idx2) % size;
            if(table[pos] == -1) return false;
            if(table[pos] == key) return true;
            i++;
        }
        return false;
    }

    void deleteKey(int key){
        int i=0;
        int idx1 = hash1(key);
        int idx2 = hash2(key);
        while(i < size){
            int pos = (idx1 + i*idx2) % size;
            if(table[pos] == -1) return;
            if(table[pos] == key){ table[pos] = -2; return; }
            i++;
        }
    }

    void print(){ for(int i=0;i<size;i++) cout<<i<<":"<<table[i]<<"\n"; }
};

// ==========================
// 5. REHASHING IMPLEMENTATION
// ==========================
class RehashingHash{
public:
    int size;
    int *table;
    int count;

    RehashingHash(int s){
        size=s;
        table=new int[size];
        for(int i=0;i<size;i++) table[i]=-1;
        count=0;
    }

    int hash(int key){ return key%size; }

    float loadFactor(){ return (float)count/size; }

    void rehash(){
        int oldSize = size;
        size = size*2;
        int *oldTable = table;

        table = new int[size];
        for(int i=0;i<size;i++) table[i] = -1;

        count = 0;

        for(int i=0;i<oldSize;i++){
            if(oldTable[i] >= 0){ insertKey(oldTable[i]); }
        }

        delete [] oldTable;
    }

    void insertKey(int key){
        if(loadFactor() > 0.75) rehash();

        int idx = hash(key);
        for(int i=0;i<size;i++){
            int pos = (idx + i) % size;
            if(table[pos] == -1 || table[pos] == -2){ table[pos] = key; count++; return; }
        }
    }

    void print(){ for(int i=0;i<size;i++) cout<<i<<":"<<table[i]<<"\n"; }
};

int main(){ 
    return 0;
}

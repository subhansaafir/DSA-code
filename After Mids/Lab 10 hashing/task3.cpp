#include <iostream>
#include<ctime>
#include<iomanip>
using namespace std;


class HashTable{ 
private: 
    int* table; 
    int S;
    int n;
public: 
    HashTable(int size){
        n = 0;
        table = new int[size];
        S = size;   
        for(int i=0; i<S; i++){
            table[i] = -1;
        }
    }

    float loadFactor(){
        return n / S;
    }

    ~HashTable(){
        delete[] table;
    }

    int idx(int k,int i){
        return (k+i) % S;
    }
    
    bool isEmpty(){
        return n == 0;
    }
    bool isFull(){
        return n == S;
    }


    bool insert(int k){
        if(isFull()){
            cout<<"Cannot insert, table is already full"<<endl;
        }
        else{
            int index = k % S;
            if (table[index] == -1){
                table[index] = k;
                n++;
                return true;
            }
            else{
                // cout<<"Collision occored at "<<index<<endl;
                return false;
            }

        }
        return false;
    }

    
    void display(){
        for(int i=0; i<S; i++){
            cout<<i<<": "<<table[i]<<endl;
        }
    }
};

int getRandomNumber(int start, int end) { 
    return rand() % (end - start + 1) + start; 
} 

int experiment(int tableSize) {
    HashTable expTable(tableSize);

    bool notcollision = false;
    int no_of_insertions = 0;

    for(int i=0; i<tableSize; i++){
        if(notcollision==false){
            int num = getRandomNumber(1,100);
            notcollision = !(expTable.insert(num));
            no_of_insertions++;
        }

    }
    return no_of_insertions;

}

int main() { 

    
    srand(static_cast<unsigned>(time(0)));  // seed random generator 
    const int numExperiments = 50; 
    cout << "Table Size\tAverage Inserted\n"; 
    cout << "-----------\t----------------\n"; 
    // Run experiments for table sizes 10, 20, 30, ..., 100 
    for (int S = 10; S <= 100; S += 10) { 
        double totalInserted = 0.0; 
        for (int i = 0; i < numExperiments; i++) 
        totalInserted += experiment(S); 
        double averageInserted = totalInserted / numExperiments; 
        cout << setw(5) << S << "\t\t" << fixed << setprecision(2)<< averageInserted << endl; 
    }

}
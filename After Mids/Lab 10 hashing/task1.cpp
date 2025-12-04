#include <iostream>
using namespace std;


class HashTable{ 
private: 
    string* table; 
    int S;
    int n;
public: 
    HashTable(int size){
        n = 0;
        table = new string[size];
        S = size;   
        for(int i=0; i<S; i++){
            table[i] = "Empty";
        }
    }

    float loadFactor(){
        return n / S;
    }

    ~HashTable(){
        delete[] table;
    }

    int getHashValue(string name){
        int count = 0;  
        for (int i=0; i<name.length(); i++){
            count = int(name[i]) + count;
        }
        return count;

    }

    int idx(string s,int i){
        return (getHashValue(s)+i) % S;
    }

    bool insert(string name){
        if(isFull()){
            cout<<"Cannot insert, table is already full"<<endl;
        }
        else{
            int index = getHashValue(name) % S;
            if (table[index] == "Empty"){
                table[index] = name;
                n++;
                return true;
            }
            else{
                cout<<"Collision occored at "<<index<<endl;
                
                while(table[index] != "Empty"){
                    index = (index + 1) % S;
                }
                table[index] = name;
                n++;
                return true;
            }


        }
        return false;
    }



    bool isEmpty(){
        return n == 0;
    }
    bool isFull(){
        return n == S;
    }

    bool search(string name){
        for(int i=0; i<S; i++){
            cout<<"Search travesed: "<<i<<endl;
            if (table[idx(name,i)] == name){
                return true;
            }
        }
        return false;
    } 

    bool remove(string name){
        for(int i=0; i<S; i++){
            if (table[idx(name,i)] == name){
                table[idx(name,i)] = "Empty";
                n--;
                return true;
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

int main(){
    
    // cout<<t.getHashValue("ali")<<endl;
    
    // t.insert("ali");
    // t.insert("G");
    // t.insert("ali");
    // t.insert("Subhan");
    
    // cout<<t.search("Subhan")<<endl;
    // cout<<t.search("ABC")<<endl;
    // t.display();
    
    
    int size;
    cout<<"Enter size of Hash Table: ";
    cin>>size;
    int choice;
    
    HashTable t(size);

    
    do{
        cout<<"1 for Insert name\n2 for Search name\n3 for Remove name\n4 for Display Table\n6 for Load factor\n6 for Exit"<<endl;
        
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            {
                string name;
                cout<<"Enter name to insert: ";
                cin>>name;
                t.insert(name);
            }
            break;
        case 2:
            {
                string name;
                cout<<"Enter name to search: ";
                cin>>name;
                if(t.search(name)){
                    cout<<"Name found in table"<<endl;
                }
                else{
                    cout<<"Name not found in table"<<endl;
                }
            }
            break;
        case 3:
            {
                string name;
                cout<<"Enter name to remove: ";
                cin>>name;
                if(t.remove(name)){
                    cout<<"Name removed from table"<<endl;
                }
                else{
                    cout<<"Name not found in table"<<endl;
                }
            }
            break;
        case 4:
            t.display();
            break;
        case 5:
            cout<<"Load factor: "<<t.loadFactor()<<endl;
            break;
        case 6:
            cout<<"Exitid"<<endl;
            break;
        
        default:
            cout<< "Invalid choice"<<endl;
            break;
        }
    }while(choice!=5);
}

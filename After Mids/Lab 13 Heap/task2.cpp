#include<iostream>
#include<vector>
using namespace std;

bool findfirstnonrepeater(vector<int> &arr, int index){

    for(int i = 0; i <arr.size(); i++){

        if(i != index && arr[i]==arr[index]){
            return false;
        }
    }
    return true;
}


int main(){
    int size;
    cout << "Enter Size of Vector(max size 1000000): ";
    cin>> size;

    vector<int> arr(size);

    cout <<"Populate Vector array with data: "<<endl;
    for (int i=0; i < size; i++){
        cout<<"Enter Value at index "<<i<<" :";
        cin >> arr[i];
    }

    for(int i=0; i<size; i++){
        if (findfirstnonrepeater(arr,i)){
            cout<<arr[i]<<endl;
            break;
        }
    }
    return 0;
}
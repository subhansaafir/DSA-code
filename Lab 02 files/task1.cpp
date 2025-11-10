#include<iostream>
using namespace std;

void printND(int n){
    for(int i=1;i<=n; i++){
        cout<<"I"<<i;

        int j=i+1;
        while(j<=n){
            cout<<"U"<<j;
            j++;
        }

        if(i==n){
            break;
        }
        else{
            cout<<" + ";
        }
    }

}

int main(){
    // int n;
    // cout<<n;
    printND(3);
    return 0;
}
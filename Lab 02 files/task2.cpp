#include<iostream>
using namespace std;

class NDarray{
    int *arr;

    public:
    NDarray(int n,int arr[3]){
        arr = new int[arr[0]*arr[1]*arr[2]];
        
    }

    int calculateIndex(int ind[3]){
        int i1= ind[0];
        int i2= ind[1];
        int i3= ind[2];

        int index = 0; int n=3;
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

    void setValue(int I[3], int val){
        // arr = val;

    }

};

int main(){
    int dim_size[3] = {2,3,5};  // 3 is n, which is dynaymically
    NDarray arr(3,dim_size);

    int index_set[3]= {0,1,4}; // where 0 is I1, 1 is I2, 4 is I3
    arr.setValue(index_set,10);

    return 0;
}
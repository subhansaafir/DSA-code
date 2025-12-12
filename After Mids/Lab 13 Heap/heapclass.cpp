#include<iostream>
using namespace std;

class heap{
public:
    int arr[100];
    int size = 0;

    void insert(int val) {
        arr[size] = val;
        int index = size;
        size = size + 1;

        while(index > 0){
            int parent = (index-1)/2;
            if(arr[parent] < arr[index]) {
            swap(arr[parent], arr[index]);
            index = parent;
            }
            else{
                return;
            }
        }
    }

    void deletefromHeap() {
        if(size == 0) {
            cout << "nothing to delete" << endl;
            return;
        }

        arr[0] = arr[size-1];
        size--;

        int i = 0;
        while(true){
            int leftIndex = 2*i+1;
            int rightIndex = 2*i+2;

            if(leftIndex >= size) return;

            int larger = leftIndex;
            if(rightIndex < size && arr[rightIndex] > arr[leftIndex]) larger = rightIndex;

            if(arr[i] < arr[larger]){
                swap(arr[i], arr[larger]);
                i = larger;
            }
            else{
                return;
            }
        }
    }

    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left < n && arr[largest] < arr[left]) {
            largest = left;
        }
        
        if(right < n && arr[largest] < arr[right]) {
            largest = right;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapSort(int arr[], int n) {
        for(int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);

        int size = n;

        while(size > 1) {
            swap(arr[size-1], arr[0]);
            size--;
            heapify(arr, size, 0);
        }
    }

    void print(){
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void heapifyUp(int i){
        while(i>0){
            int p=(i-1)/2;
            if(arr[p]<arr[i]){
                swap(arr[p],arr[i]);
                i=p;
            }
            else return;
        }
    }

    void heapifyDown(int i){
        while(true){
            int left=2*i+1;
            int right=2*i+2;
            if(left>=size) return;
            int large=left;
            if(right<size && arr[right]>arr[left]) large=right;
            if(arr[i]<arr[large]){
                swap(arr[i],arr[large]);
                i=large;
            }
            else return;
        }
    }

    void convertToMinHeap(){
        for(int i=size/2-1;i>=0;i--){
            int smallest=i;
            int left=2*i+1;
            int right=2*i+2;
            if(left<size && arr[left]<arr[smallest]) smallest=left;
            if(right<size && arr[right]<arr[smallest]) smallest=right;
            if(smallest!=i){
                swap(arr[i],arr[smallest]);
                i=size;
            }
        }
    }

    void convertToMaxHeap(){
        for(int i=size/2-1;i>=0;i--){
            int largest=i;
            int left=2*i+1;
            int right=2*i+2;
            if(left<size && arr[left]>arr[largest]) largest=left;
            if(right<size && arr[right]>arr[largest]) largest=right;
            if(largest!=i){
                swap(arr[i],arr[largest]);
                i=size;
            }
        }
    }

    void buildHeapFromArray(int a[], int n){
        for(int i=0;i<n;i++) arr[i]=a[i];
        size=n;
        for(int i=n/2-1;i>=0;i--) heapifyDown(i);
    }

    void remove(int index){
        if(index >= size) return;
        arr[index] = arr[size-1];
        size--;
        heapifyDown(index);
        heapifyUp(index);
    }

};


int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    h.deletefromHeap();
    h.print();
    int arr[6] = {54, 53, 55, 52, 50};

    int n = 5;
    for(int i= n/2-1; i>=0; i--){
        h.heapify(arr, n, i);
    }

    cout << "printing the array now "<< endl;
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    } 
    cout << endl;

    h.heapSort(arr,n);

    cout <<"printing sorted array: "<<endl;
    for(int i = 0; i<n; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;

    return 0;
}



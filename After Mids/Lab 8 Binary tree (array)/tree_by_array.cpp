#include<iostream>
#include<cmath>
using namespace std;

template<typename T>
class binarytree{
    int height;
    T *data;
    bool *status;
    int nodes;

    void preorder(int index){
        if(index >= nodes || !status[index]){
            return;
        }
        cout << data[index] << " ";
        preorder(2*index + 1);
        preorder(2*index + 2);
    }

    void postorder(int index){
        if(index >= nodes || !status[index]){
            return ;
        }
        postorder(2*index+1);
        postorder(2*index+2);
        cout << data[index] << " ";
    }

    void inorder(int index){
        if(index >= nodes || !status[index]){
            return;
        }
        inorder(2*index+1);
        cout << data[index] << " ";
        inorder(2*index+2);
    }

    public: 

    // Task 1
    binarytree(int h){
        height = h;
        nodes = (pow(2,h)-1);
        data = new T[nodes];
        status = new bool[nodes];
        for (int i = 0; i < nodes; i++){
            status[i] = false;
        }
    }

    ~binarytree(){
        delete[] data;
        delete[] status;
    }
    
    // Task 2
    void setRoot(T v){
        data[0] = v;
        status[0] = true;
    }

    // Task 3
    T getRoot(){
        if (status[0]==false){
            cout <<"No Root/Tree Exist"<<endl;
            return -1;
        }
        return data[0];
    }

    // Task 4
    void setLeftChild(T parent, T val){
        for (int i = 0; i < nodes; i++)
        {
            if(status[i] && data[i] == parent){
                int left = 2*i + 1;
                if (status[left] == false && left<nodes)
                {
                    data[left] = val;
                    status[left] = true;
                }
            }
        }
    }

    // Task 5
    void setRightChild(T parent, T val){
        for (int i = 0; i < nodes; i++)
        {
            if(status[i] && data[i] == parent){
                int right = 2*i + 2;
                if(status[right] == false && right<nodes){
                    data[right] = val;
                    status[right] = true;
                }
            }
        }
    }

    // Task 6
    T getParent(T node){
        for(int i=0; i<nodes; i++){
            if(status[i] && (data[i] == node)){
                int parent = (i - 1) / 2;
                return data[parent];
            }
        }
    }

    // Task 7
    void remove(int node){
        for(int i=0; i<nodes; i++){
            if(status[i] && data[i] == node){
                remove(2*i + 1);
                remove(2*i + 2);
                status[i] = false;
            }
        }
    }

    // Task 8
    void displayAncestors(T nod){
        cout << "Ancestors: ";
        for(int i = 0; i < nodes; i++){
            if(status[i] && data[i] == nod){
                int parentidx = (i - 1) / 2;

                while(parentidx >= 0){
                    if(status[parentidx]){
                        cout << data[parentidx] << " ";
                    }
                    if(parentidx == 0){
                        break;
                    }
                    parentidx = (parentidx - 1) / 2;
                }
                cout << endl;
                return;
            }
        }
        cout << "No Node such exist" << endl;
    }

    // Task 9
    void displayDescendents(T node){
        cout << "Descendents of "<<node<<" are:  ";

        for(int i = 0; i < nodes; i++){
            if(status[i] && data[i] == node){
                inorder(2*i + 1);
                inorder(2*i + 2);
                cout << endl;
                return;
            }
        }
        cout << "Node not found." << endl;
    }

    //Task 10
    void heightOfTree(){
        int actualL = -1;
        for(int i=0; i<nodes; i++){
            
            if(status[i]){
                int level = 0;
                int pidx = i;
                while(pidx > 0){
                    pidx = (pidx - 1) / 2;
                    level++;
                }
                if(level > actualL){
                    actualL = level;
                }
            }
        }

        if(actualL == -1){
            cout <<"Height of tree: 0 (no any tree exist)"<<endl;
        } else {
            cout <<"Height of tree: " << (actualL + 1)<<endl;
        }
    } 

    void preorder(){
        cout << "Preorder: ";
        preorder(0);
        cout << endl;
    }

    void postorder(){
        cout << "Postorder: ";
        postorder(0);
        cout << endl;
    }

    void inorder(){
        cout << "Inorder: ";
        inorder(0);
        cout << endl;
    }
    
    void levelorder(){
        cout << "Level Order: ";
        for(int i = 0; i < nodes; i++){
            if(status[i]){
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }

    void displayLevel(int levelNo){
        // level 1  0    2 pow 0
        // leverl 2   1 2   2 pow 1
        // level 3   3 4 5 6    2 pow 2
        // level 4    7 8 9 10 11 12 13 14   2 pow 3
        if (levelNo < 1 || levelNo > height){
            cout << "Invalid Level Number" << endl;
            return;
        }
        
    }

    //Task 16
    int findLevelOfNode(T node){
        for(int i = 0; i < nodes; i++){

            if(status[i] && data[i] == node){
                int level = 0;
                int index = i;
                while(index > 0){
                    index = (index - 1) / 2;
                    level++;
                }
                return level+1;
            }
        }
        return -1; 
    } 

    bool isvalidbinarytree(){
        for(int i = 0; i < nodes; i++){
            if(status[i]){
                int left = 2*i + 1;
                int right = 2*i + 2;
                
                if(left < nodes && status[left]){
                    if(status[i] == false){
                        return false;
                    }
                }
                
                if(right < nodes && status[right]){
                    if(status[i] == false){
                        return false;
                    }
                }
            }
            else{
                int left = 2*i + 1;
                int right = 2*i + 2;
                
                if((left < nodes && status[left]) || (right < nodes && status[right])){
                    return false;
                }
            }
        }
        return true;
    }

    void mirror(int index){
        if(index >= nodes || !status[index]){
            return;
        }
        
        int left = 2*index + 1;
        int right = 2*index + 2;
        
        if(left < nodes && right < nodes){
            swap(data[left], data[right]);
            swap(status[left], status[right]);
        }
        
        mirror(left);
        mirror(right);
    }

    int countLeafNodes() {
        int n = pow(2, height) - 1;  //give no of nodes
        int leafCount = 0;
        for (int i = 0; i < n; i++) {
            if (status[i]) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;

                // check if both children are absent or inactive
                if ((left >= n || !status[left]) && (right >= n || !status[right])) {
                    leafCount++;
                }
            }
        }
        return leafCount;
    }

    int countnonleafNodes(){
        int count = 0;
        for(int i = 0; i < nodes; i++){
            if(status[i]){
                int left = 2*i + 1;
                int right = 2*i + 2;
                
                if((left < nodes && status[left]) || (right < nodes && status[right])){
                    count++;
                }
            }
        }
        return count;
    }
    
    int countLeafNodes(int index){
        if(index >= nodes || !status[index]){
            return 0;
        }
        int left = 2*index + 1;
        int right = 2*index + 2;
        // agar dono children nahi hain toh yeh leaf node hai
        if((left >= nodes || !status[left]) && (right >= nodes || !status[right])){
            return 1;
        }
        return countLeafNodes(left) + countLeafNodes(right);
    }
};

int main(){
    binarytree<int> tree(4);  //task 1
    
    tree.setRoot(1);  //task 2
    cout<< tree.getRoot()<<endl;  //task 3
    tree.setLeftChild(1, 2);  // task 4
    tree.setRightChild(1, 3);  //task 5
    tree.setLeftChild(2, 4);
    tree.setRightChild(2, 5);
    tree.setLeftChild(3, 6);
    tree.setRightChild(3, 7);
    tree.setLeftChild(4, 8);
    tree.setRightChild(4, 9);
    tree.setLeftChild(5, 10);
    tree.setRightChild(5, 11);
    tree.setLeftChild(6, 12);
    tree.setRightChild(6, 13);
    tree.setLeftChild(7, 14);
    tree.setRightChild(7, 15);

    cout<<"Parent of child 5 is: "<< tree.getParent(5) <<endl; //task 6
    tree.displayAncestors(8);   // task 8
    tree.displayDescendents(2); // task 9

    tree.preorder();
    tree.postorder();
    tree.inorder();
    tree.levelorder();
    // tree.remove(4);  //task 7
    tree.inorder();
    tree.heightOfTree();
    cout<< tree.findLevelOfNode(2);
    // tree.displayLevel(3);
    // tree.mirror(0);
    // cout<<tree.countLeafNodes()<<endl;
    // cout<<tree.countLeafNodes(0)<<endl;
    // cout<<tree.countnonleafNodes()<<endl;
    return 0;
}
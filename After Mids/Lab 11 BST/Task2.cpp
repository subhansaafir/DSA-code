#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST{
    private:
    Node* root;

    bool recsearch(Node* b, int key){
        if(b == NULL){
            return false;
        }
        if(b->data == key){
            return true;
        }
        else{
            return recsearch(b->left, key);
            return recsearch(b->right, key);
        }
    }

    int count(Node* b){
        if(b == NULL){
            return 0;
        }
        else{
            return 1 + count(b->left) + count(b->right);
        }
    }

    int height(Node* b){
        if(b == NULL){
            return 0;
        }
        else{
            return 1 + max(count(b->left), count(b->right));
        }
    }

    public:
    BST(){
        root = NULL;
    }

    void insert(int value){
        Node* NewNode = new Node(value);
        if(root == NULL){
           root = NewNode; 
        }
        else{
            Node* current = root;
            Node* parent = NULL;
            while (current != NULL){
                parent = current;
                if (value < current->data){
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (value < parent->data){
                parent->left = NewNode;
            } else {
                parent->right = NewNode;
            }
        }
    }


    bool recsearch(int key){
        return recsearch(root, key);
    }

    int count(){
        return count(root);
    }

    int getheight(){
        return height(root);
    }

};


int main(){
    BST tree;
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    cout<<tree.recsearch(3)<<endl;
    cout << "Count: " << tree.count()<<endl;
    cout << "Heigh: "<< tree.getheight()<< endl;
    return 0;
}
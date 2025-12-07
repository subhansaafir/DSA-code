#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST
{
private:
	Node *root;
    void inOrderHelper(Node *p) {
        if (p != nullptr) {
            inOrderHelper(p->left);
            cout << p->data << " ";
            inOrderHelper(p->right);
        }
    }
    
    void preOrderHelper(Node *p) {
        if (p != nullptr) {
            std::cout << p->data << " ";
            preOrderHelper(p->left);
            preOrderHelper(p->right);
        }
    }

    void postOrderHelper(Node* p) {
    if (p != nullptr) {
        postOrderHelper(p->left);
        postOrderHelper(p->right);
        cout << p->data << " ";
    }
}

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* root, int node) {
        if (root == nullptr) {
            return root;
        }

        if (node < root->data) {
            root->left = deleteNode(root->left, node);
        } else if (node > root->data) {
            root->right = deleteNode(root->right, node);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node *temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    
public:
	BST() : root(nullptr) {}

    void insert(int node) {
        Node* newNode = new Node(node);
        
        if (root == nullptr) {
            root = newNode;
        } else {
            Node* current = root;
            Node* parent = nullptr;
            
            while (current != nullptr) {
                parent = current;
                if (node < current->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            
            if (node < parent->data) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }
    }

    void distroy(int node) {
        root = deleteNode(root, node);
    }


    bool search(int node) {
        Node *current = root;
        while (current != nullptr) {
            if (current->data == node) {
                return true;
            } else if (node < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
    

    void construct_from_traversals(vector<int> in_order, vector<int> pre_order){

        int pre_index = 0;
        root = bstHelper(in_order, pre_order, 0, in_order.size()-1, pre_index);
    }

    Node* bstHelper(vector<int>& in_order, vector<int>& pre_order, int start, int end, int& pre_index){
        if (start > end){
            return nullptr;
        }
        
        int rootValue = pre_order[pre_index];
        pre_index++;
        
        Node* root = new Node(rootValue);
        
        int mid = -1;
        for (int i =start; i <= end; i++){
            if (in_order[i] == rootValue){
                mid = i;
                break;
            }
        }

        root->left = bstHelper(in_order,pre_order, start, mid-1, pre_index);
        root->right = bstHelper(in_order,pre_order, mid+1, end, pre_index);
        
        return root;
    }


    // Public function
    void inOrder() {
        inOrderHelper(root);
        cout << endl;
    }
    
    // Public function
    void preOrder() {
        preOrderHelper(root);
        cout << endl;
    }
    
    // Public function
    void postOrder() {
        postOrderHelper(root);
        cout << endl;
    }

};


int main(){ 
    BST bst1; 
    vector<int> in1 = {1, 2, 3, 4, 5, 6}; 
    vector<int >pre1 = {3, 1, 2, 5, 4, 6}; 
     
    bst1.construct_from_traversals(in1, pre1); 
    
    cout << "In-order traversal (Example 1): "; 
    bst1.inOrder(); 
    
    cout << "Post-order traversal (Example 1): "; 
    bst1.postOrder();
    
    BST bst2; 
    vector<int> in2 = {5,10,15,25,27,30,35,40,45,50,52,55,60,65,70,75,80,85,90,100}; 
    vector<int> pre2 = {50,25,10,5,15,40,30,27,35,45,75,60,55,52,65,70,90,80,85,100}; 
    
    bst2.construct_from_traversals(in2, pre2); 
    
    cout << "\nIn-order traversal (Example 2): "; 
    bst2.inOrder();
    
    cout << "Post-order traversal (Example 2): "; 
    bst2.postOrder(); 
    return 0; 
} 
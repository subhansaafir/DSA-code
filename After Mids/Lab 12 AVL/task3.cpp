#include<iostream>
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


int main() { 
    BST bst; 
    bst.insert(1); 
    bst.insert(5); 
    bst.insert(10); 
    bst.insert(20); 
    bst.insert(25); 
    bst.insert(30); 
    bst.insert(35); 
    bst.insert(40); 
    bst.insert(45); 
     
    cout<<"Original BST  Height: "<<bst.getHeight()<<endl; 
 
    cout << "\nOriginal BST (Inorder): "; 
    bst.inOrder(); 
    cout << "\nOriginal BST Pre-order: "; 
    bst.preOrder(); 
 
    cout << "\nOriginal BST Post-order: "; 
    bst.postOrder(); 
 
    bst.createPerfectBST(); 
 
    cout<<"\nHeight After DSW: "<<bst.getHeight()<<endl; 
 
    cout << "\nBalanced BST using DSW (Inorder): "; 
    bst.inOrder(); 
 
    cout << "\nBalanced BST using (DSWPre-order:) "; 
    bst.preOrder(); 
 
    cout << "\nBalanced BST using DSW (Post-order:) "; 
    bst.postOrder(); 
 
    return 0; 
} 
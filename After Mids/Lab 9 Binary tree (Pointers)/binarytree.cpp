#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    
    Node(){
        left = NULL;
        right = NULL;
    }

    Node(T value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BinaryTree{
private:
    Node<T>* root;

    // task 11
    void preorder(Node<T>* curr){
        if (curr == NULL) return;
        cout << curr->data << " ";
        preorder(curr->left);
        preorder(curr->right);
    }
    
    // Task 12
    void postorder(Node<T>* curr){
        if (curr == NULL) return;
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << " ";
    }

    // Task 13
    void inorder(Node<T>* curr){
        if (curr == NULL) return;
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }

    void deleteTree(Node<T>* curr){
        if (curr == NULL){
            return;
        }
        deleteTree(curr->left);
        deleteTree(curr->right);
        delete curr;
    }

public:
    // Task 1
    BinaryTree(){
        root = 0;
    }

    // Task 2
    void setroot(T value){
        if (root == NULL)
            root = new Node<T>(value);
        else
            cout << "Root already exists!\n";
    }

    // Task 3
    Node<T>* getRoot(){
        return root;
    }

    // Task 4
    void setleftchild(Node<T>* parent, T value){
        if (parent == NULL){
            cout << "Parent is null!\n";
            return;
        }
        if (parent->left != NULL){
            cout << "Left child already exists!\n";
            return;
        }
        parent->left = new Node<T>(value);
    }

    // Task 5
    void setrightchild(Node<T>* parent, T value){
        if (parent == NULL){
            cout << "Parent is null!\n";
            return;
        }
        if (parent->right != NULL){
            cout << "Right child already exists!\n";
            return;
        }
        parent->right = new Node<T>(value);
    }

    // Task 6
    T getparent(T curr){
        
    }
    
    // Task 7
    void remove(T curr){
        if (curr == NULL){
            return;
        }
        remove(curr->left);
        remove(curr->right);
        delete curr;
    }
    
    // Task 8
    bool isInternalNode(Node<T>* curr){
        if (curr == NULL){
            cout<<"No tree exist"<<endl;
            return false;
        }
        return (curr->left != NULL || curr->right != NULL);
    }

    // Task 9
    bool isExternalNode(Node<T>* curr){
        if (curr == NULL){
            cout<<"No tree exist"<<endl;
            return false;
        }
        return (curr->left == NULL && curr->right == NULL);
    }

    // Task 10
    int findsibling(Node<T>* curr){
        if (curr == NULL){
            cout<<"No sibling exist"<<endl;
            return -1;
        }
        
        Node<T>* parent = root;
        while (parent != NULL){
            if (parent->left == curr && parent->right != NULL)
                return parent->right->data;
            if (parent->right == curr && parent->left != NULL)
                return parent->left->data;

            if (curr->data < parent->data)
                parent = parent->left;
            else
                parent = parent->right;
        }
        return -1;
    }

    // Task 11
    void preOrder(){
        preorder(root);
        cout << endl;
    }

    // Task 12
    void postOrder(){
        postorder(root);
        cout << endl;
    }

    // Task 13
    void inOrder(){
        inorder(root);
        cout << endl;
    }

    // Task 14
    void levelOrder(){
        if (root == NULL) {
            cout << "Tree is empty!" << endl;
            return;
        }

        queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()){
            Node<T>* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << endl;
    }

    // Task 15
    void displayDescendants(Node<T>* curr){
        if (curr == NULL){
            cout<<"No tree exist"<<endl;
            return;
        }

        cout <<"Desendents of the Node ("<<curr->data<< ") are: ";
        inorder(curr->left);
        inorder(curr->right);
    }

    // Task 16
    int treeheight(Node<T>* curr){
        if (curr == NULL)
            return 0;

        int leftHeight = treeheight(curr->left);
        int rightHeight = treeheight(curr->right);

        return 1 + max(leftHeight, rightHeight);
    }

    // Task 20
    BinaryTree(const BinaryTree<T>& other){
        root = other.root;
        left = other.left;
        right = other.right;
        while(other != NULL){
            setleftchild(other->left, other->left->data);
            setrightchild(other->right, other->right->data);
        }
        delete other;
    }

    // Task 18
    ~BinaryTree(){
        deleteTree(root);
    }


    // Task 21
    void mirror(Node<T>* curr) {
        if (curr == NULL)
            return;

        swap(curr->left, curr->right);

        mirror(curr->left);
        mirror(curr->right);
    }
    BinaryTree<T> getMirrorImage(){
        BinaryTree<T> mirrorTree;
        mirrorTree.root = root;
        mirrorTree.mirror(root);
        return mirrorTree;
    }


};

int main(){
    BinaryTree<int> tree;

    tree.setroot(1);
    Node<int>* root = tree.getRoot();
    tree.setleftchild(root, 2);
    tree.setrightchild(root, 3);
    tree.setleftchild(root->left, 4);
    tree.setrightchild(root->left, 5);
    tree.setleftchild(root->right, 6);
    tree.setrightchild(root->right, 7);
    tree.setleftchild(root->left->left, 8);
    tree.setrightchild(root->left->left, 9);
    tree.setleftchild(root->left->right, 10);
    tree.setrightchild(root->left->right, 11);
    tree.setleftchild(root->right->left, 12);
    tree.setrightchild(root->right->left, 13);
    tree.setleftchild(root->right->right, 14);
    tree.setrightchild(root->right->right, 15);


    cout << "Preorder: ";
    tree.preOrder();

    cout << "Postorder: ";
    tree.postOrder();

    cout << "Inorder: ";
    tree.inOrder();


    cout << "Level Order: ";
    tree.levelOrder();
    

    cout<< tree.isExternalNode(root->right->right->right)<<endl;
    tree.displayDescendants(root->left);
    cout<<endl;

    BinaryTree<int> tree2 = tree.getMirrorImage();
    tree2.levelOrder();
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BinaryTree {
private:
    Node<T>* root;

    void preorder(Node<T>* node){
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node<T>* node){
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(Node<T>* node){
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void deleteTree(Node<T>* node){
        if (node == NULL) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BinaryTree(){
        root = NULL;
    }

    ~BinaryTree(){
        deleteTree(root);
    }

    Node<T>* getRoot(){
        return root;
    }

    void insertRoot(T value){
        if (root == NULL)
            root = new Node<T>(value);
        else
            cout << "Root already exists!\n";
    }

    void insertLeft(Node<T>* parent, T value){
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

    void insertRight(Node<T>* parent, T value){
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

    void preorderTraversal(){
        preorder(root);
        cout << endl;
    }

    void inorderTraversal(){
        inorder(root);
        cout << endl;
    }

    void postorderTraversal(){
        postorder(root);
        cout << endl;
    }

    void levelOrderTraversal(){
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

    int countNodes(Node<T>* curr) {
        if (curr == nullptr)
            return 0;

        return 1 + countNodes(curr->left) + countNodes(curr->right);
    }


    void levelbyleveldisplay(){
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

    int treeheight(Node<T>* curr) {
        if (curr == NULL)
            return 0;

        int leftHeight = treeheight(curr->left);
        int rightHeight = treeheight(curr->right);

        return 1 + max(leftHeight, rightHeight);
    }

    int sumatlevel(Node<T>* curr, int level) {
        if (curr == NULL)
            return 0;
        if (level == 1)
            return curr->data;

        return sumatlevel(curr->left, level - 1) + sumatlevel(curr->right, level - 1);
    }


    int treesum(Node<T>* curr){
        if (curr == NULL)
            return 0;
        
        return curr->data + treesum(curr->left) + treesum(curr->right);
    }

    bool exists(Node<T>* curr, T value) {
        if (curr == NULL)
            return false;
        if (curr->data == value)
            return true;

        return exists(curr->left, value) || exists(curr->right, value);
    }

    void reverseTree(Node<T>* curr) {
        if (curr == NULL)
            return;

        swap(curr->left, curr->right);

        reverseTree(curr->left);
        reverseTree(curr->right);
    }

    void displayLeafNodes(Node<T>* curr) {
        if (curr == NULL)
            return;

        if (curr->left == NULL && curr->right == NULL) {
            cout << curr->data << " ";
            return;
        }

        displayLeafNodes(curr->left);
        displayLeafNodes(curr->right);
    }

    int findlevelofnode(Node<T>* curr, T value, int level) {
        if (curr == NULL)
            return -1;
        if (curr->data == value)
            return level;

        int leftLevel = findlevelofnode(curr->left, value, level + 1);
        if (leftLevel != -1)
            return leftLevel;

        return findlevelofnode(curr->right, value, level + 1);
    }

    // void displayAncestors(Node<T>* curr, T value) {
    //     if (curr == NULL)
    //         return;

    //     if (curr->left != NULL && (curr->left->data == value || exists(curr->left, value))) {
    //         cout << curr->data << " ";
    //         displayAncestors(curr->left, value);
    //     }
    //     else if (curr->right != NULL && (curr->right->data == value || exists(curr->right, value))) {
    //         cout << curr->data << " ";
    //         displayAncestors(curr->right, value);
    //     }
    // }


    // void roottoleafpaths(Node<T>* curr, vector<T>& path) {
    //     if (curr == NULL)
    //         return;

    //     path.push_back(curr->data);

    //     if (curr->left == NULL && curr->right == NULL) {
    //         for (T val : path)
    //             cout << val << " ";
    //         cout << endl;
    //     }
    //     else {
    //         roottoleafpaths(curr->left, path);
    //         roottoleafpaths(curr->right, path);
    //     }

    //     path.pop_back();
    // }

    // void rootToLeafPaths(Node<T>* curr, T path[], int pathLen) {
    //     if (curr == NULL)
    //         return;

    //     // Add current node to path
    //     path[pathLen] = curr->data;
    //     pathLen++;

    //     // If leaf, print the path
    //     if (curr->left == NULL && curr->right == NULL) {
    //         for (int i = 0; i < pathLen; i++)
    //             cout << path[i] << " ";
    //         cout << endl;
    //     } 
    //     else {
    //         rootToLeafPaths(curr->left, path, pathLen);
    //         rootToLeafPaths(curr->right, path, pathLen);
    //     }
    // }

    bool isIdentical(Node<T>* tree1, Node<T>* tree2) {
        if (tree1 == NULL && tree2 == NULL)
            return true;
        if (tree1 == NULL || tree2 == NULL)
            return false;
        if (tree1->data != tree2->data)
            return false;

        return isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right);
    }


};
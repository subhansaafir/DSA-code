#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<class T>
class BST
{
private:
    Node<T> *root;
    void inOrderHelper(Node<T> *p);
    void preOrderHelper(Node<T> *p);
    void postOrderHelper(Node<T> *p);
    Node<T>* findMin(Node<T>* node);
    Node<T>* deleteNode(Node<T>* root, T node);
    int heightHelper(Node<T>* node);
    int countNodesHelper(Node<T>* node);
    bool isValidBST(Node<T>* node, T minVal, T maxVal);
    void displayTreeHelper(Node<T>* node, int space);
    bool isLeafHelper(Node<T>* node, T value);
    bool isBalancedHelper(Node<T>* node);
    T sumOfNodesHelper(Node<T>* node);
    void destructorHelper(Node<T>* node);
    
public:
    BST() : root(nullptr) {}
    ~BST();
    
    // Original Functions
    void insert(T node);
    bool search(T node);
    void inOrder();
    void preOrder();
    void postOrder();
    void deleteMethod(T p);
    
    // New Functions
    int height();
    int countNodes();
    bool isEmpty();
    T getMin();
    T getMax();
    void levelOrder();
    bool isBST();
    void displayTree();
    int size();
    void clear();
    Node<T>* findParent(T value);
    bool isLeaf(T value);
    bool isBalanced();
    T sumOfNodes();
    double averageOfNodes();
    void getAncestors(T value);
    void getDescendants(T value);
    void getAncestorsHelper(Node<T>* node, T value, bool found);
    void getDescendantsHelper(Node<T>* node);
};

// Destructor
template<class T>
BST<T>::~BST() {
    destructorHelper(root);
}

template<class T>
void BST<T>::destructorHelper(Node<T>* node) {
    if (node != nullptr) {
        destructorHelper(node->left);
        destructorHelper(node->right);
        delete node;
    }
}

// Insert
template<class T>
void BST<T>::insert(T node) {
    Node<T> *newNode = new Node<T>(node);
    
    if (root == nullptr) {
        root = newNode;
    } else {
        Node<T> *current = root;
        Node<T> *parent = nullptr;
        
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

// Find Min
template<class T>
Node<T>* BST<T>::findMin(Node<T>* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Delete Node
template<class T>
Node<T>* BST<T>::deleteNode(Node<T>* root, T node) {
    if (root == nullptr) {
        return root;
    }

    if (node < root->data) {
        root->left = deleteNode(root->left, node);
    } else if (node > root->data) {
        root->right = deleteNode(root->right, node);
    } else {
        if (root->left == nullptr) {
            Node<T> *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node<T> *temp = root->left;
            delete root;
            return temp;
        }

        Node<T> *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Delete Method
template<class T>
void BST<T>::deleteMethod(T node) {
    root = deleteNode(root, node);
}

// Search
template<class T>
bool BST<T>::search(T node) {
    Node<T> *current = root;
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

// In-Order
template<class T>
void BST<T>::inOrderHelper(Node<T> *p) {
    if (p != nullptr) {
        inOrderHelper(p->left);
        cout << p->data << " ";
        inOrderHelper(p->right);
    }
}

template<class T>
void BST<T>::inOrder() {
    inOrderHelper(root);
    cout << endl;
}

// Pre-Order
template<class T>
void BST<T>::preOrderHelper(Node<T> *p) {
    if (p != nullptr) {
        cout << p->data << " ";
        preOrderHelper(p->left);
        preOrderHelper(p->right);
    }
}

template<class T>
void BST<T>::preOrder() {
    preOrderHelper(root);
    cout << endl;
}

// Post-Order
template<class T>
void BST<T>::postOrderHelper(Node<T> *p) {
    if (p != nullptr) {
        postOrderHelper(p->left);
        postOrderHelper(p->right);
        cout << p->data << " ";
    }
}

template<class T>
void BST<T>::postOrder() {
    postOrderHelper(root);
    cout << endl;
}

// Height
template<class T>
int BST<T>::heightHelper(Node<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + max(heightHelper(node->left), heightHelper(node->right));
}

template<class T>
int BST<T>::height() {
    return heightHelper(root);
}

// Count Nodes
template<class T>
int BST<T>::countNodesHelper(Node<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
}

template<class T>
int BST<T>::countNodes() {
    return countNodesHelper(root);
}

// Is Empty
template<class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

// Get Min
template<class T>
T BST<T>::getMin() {
    if (root == nullptr) {
        throw runtime_error("Tree is empty!");
    }
    return findMin(root)->data;
}

// Get Max
template<class T>
T BST<T>::getMax() {
    if (root == nullptr) {
        throw runtime_error("Tree is empty!");
    }
    Node<T>* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }
    return current->data;
}

// Level Order
template<class T>
void BST<T>::levelOrder() {
    if (root == nullptr) {
        cout << "Tree is empty!" << endl;
        return;
    }
    
    queue<Node<T>*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node<T>* node = q.front();
        q.pop();
        cout << node->data << " ";
        
        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
    cout << endl;
}

// Is Valid BST
template<class T>
bool BST<T>::isValidBST(Node<T>* node, T minVal, T maxVal) {
    if (node == nullptr) {
        return true;
    }
    if (node->data <= minVal || node->data >= maxVal) {
        return false;
    }
    return isValidBST(node->left, minVal, node->data) && 
           isValidBST(node->right, node->data, maxVal);
}

template<class T>
bool BST<T>::isBST() {
    return isValidBST(root, numeric_limits<T>::min(), numeric_limits<T>::max());
}

// Display Tree
template<class T>
void BST<T>::displayTreeHelper(Node<T>* node, int space) {
    if (node == nullptr) {
        return;
    }
    
    space += 10;
    displayTreeHelper(node->right, space);
    
    cout << endl;
    for (int i = 10; i < space; i++) {
        cout << " ";
    }
    cout << node->data;
    
    displayTreeHelper(node->left, space);
}

template<class T>
void BST<T>::displayTree() {
    cout << "Tree Structure:" << endl;
    displayTreeHelper(root, 0);
    cout << endl;
}

// Size (same as countNodes)
template<class T>
int BST<T>::size() {
    return countNodes();
}

// Clear
template<class T>
void BST<T>::clear() {
    destructorHelper(root);
    root = nullptr;
}

// Find Parent
template<class T>
Node<T>* BST<T>::findParent(T value) {
    if (root == nullptr || root->data == value) {
        return nullptr;
    }
    
    Node<T>* current = root;
    while (current != nullptr) {
        if ((current->left != nullptr && current->left->data == value) ||
            (current->right != nullptr && current->right->data == value)) {
            return current;
        }
        
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}

// Is Leaf
template<class T>
bool BST<T>::isLeafHelper(Node<T>* node, T value) {
    if (node == nullptr) {
        return false;
    }
    
    if (node->data == value) {
        return (node->left == nullptr && node->right == nullptr);
    }
    
    if (value < node->data) {
        return isLeafHelper(node->left, value);
    } else {
        return isLeafHelper(node->right, value);
    }
}

template<class T>
bool BST<T>::isLeaf(T value) {
    return isLeafHelper(root, value);
}

// Is Balanced
template<class T>
bool BST<T>::isBalancedHelper(Node<T>* node) {
    if (node == nullptr) {
        return true;
    }
    
    int leftHeight = heightHelper(node->left);
    int rightHeight = heightHelper(node->right);
    
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    
    return isBalancedHelper(node->left) && isBalancedHelper(node->right);
}

template<class T>
bool BST<T>::isBalanced() {
    return isBalancedHelper(root);
}

// Sum of Nodes
template<class T>
T BST<T>::sumOfNodesHelper(Node<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->data + sumOfNodesHelper(node->left) + sumOfNodesHelper(node->right);
}

template<class T>
T BST<T>::sumOfNodes() {
    return sumOfNodesHelper(root);
}

// Average of Nodes
template<class T>
double BST<T>::averageOfNodes() {
    if (countNodes() == 0) {
        return 0;
    }
    return (double)sumOfNodes() / countNodes();
}

// Get Ancestors
template<class T>
void BST<T>::getAncestorsHelper(Node<T>* node, T value, bool found) {
    if (node == nullptr) {
        return;
    }
    
    if (node->data == value) {
        found = true;
        return;
    }
    
    if (value < node->data) {
        getAncestorsHelper(node->left, value, found);
        if (found) {
            cout << node->data << " ";
        }
    } else {
        getAncestorsHelper(node->right, value, found);
        if (found) {
            cout << node->data << " ";
        }
    }
}

template<class T>
void BST<T>::getAncestors(T value) {
    if (!search(value)) {
        cout << "Node not found!" << endl;
        return;
    }
    
    if (root->data == value) {
        cout << "No ancestors (root node)" << endl;
        return;
    }
    
    cout << "Ancestors of " << value << ": ";
    bool found = false;
    getAncestorsHelper(root, value, found);
    cout << endl;
}

// Get Descendants
template<class T>
void BST<T>::getDescendantsHelper(Node<T>* node) {
    if (node == nullptr) {
        return;
    }
    
    cout << node->data << " ";
    
    getDescendantsHelper(node->left);
    getDescendantsHelper(node->right);
}

template<class T>
void BST<T>::getDescendants(T value) {
    if (!search(value)) {
        cout << "Node not found!" << endl;
        return;
    }
    
    Node<T>* current = root;
    while (current != nullptr) {
        if (current->data == value) {
            break;
        }
        if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (current->left == nullptr && current->right == nullptr) {
        cout << "No descendants (leaf node)" << endl;
        return;
    }
    
    cout << "Descendants of " << value << ": ";
    
    if (current->left != nullptr) {
        getDescendantsHelper(current->left);
    }
    if (current->right != nullptr) {
        getDescendantsHelper(current->right);
    }
    cout << endl;
}

int main()
{
    BST<int> obj;
    
    cout << "===== BST Complete Implementation =====" << endl << endl;
    
    // Insert
    cout << "1. Inserting: 5, 3, 7, 2, 4, 6, 8" << endl;
    obj.insert(5);
    obj.insert(3);
    obj.insert(7);
    obj.insert(2);
    obj.insert(4);
    obj.insert(6);
    obj.insert(8);
    cout << "Inserted!" << endl << endl;
    
    // Traversals
    cout << "2. Traversals:" << endl;
    cout << "In-Order: ";
    obj.inOrder();
    cout << "Pre-Order: ";
    obj.preOrder();
    cout << "Post-Order: ";
    obj.postOrder();
    cout << "Level-Order: ";
    obj.levelOrder();
    cout << endl;
    
    // Display Tree
    cout << "3. Display Tree:" << endl;
    obj.displayTree();
    cout << endl;
    
    // Tree Information
    cout << "4. Tree Information:" << endl;
    cout << "Height: " << obj.height() << endl;
    cout << "Count Nodes: " << obj.countNodes() << endl;
    cout << "Size: " << obj.size() << endl;
    cout << "Is Empty: " << (obj.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is Valid BST: " << (obj.isBST() ? "Yes" : "No") << endl;
    cout << "Is Balanced: " << (obj.isBalanced() ? "Yes" : "No") << endl;
    cout << endl;
    
    // Min/Max
    cout << "5. Min/Max:" << endl;
    cout << "Minimum: " << obj.getMin() << endl;
    cout << "Maximum: " << obj.getMax() << endl;
    cout << endl;
    
    // Search
    cout << "6. Search:" << endl;
    cout << "Search 4: " << (obj.search(4) ? "Found" : "Not Found") << endl;
    cout << "Search 10: " << (obj.search(10) ? "Found" : "Not Found") << endl;
    cout << endl;
    
    // Leaf and Parent
    cout << "7. Leaf and Parent:" << endl;
    cout << "Is 4 leaf: " << (obj.isLeaf(4) ? "Yes" : "No") << endl;
    cout << "Is 2 leaf: " << (obj.isLeaf(2) ? "Yes" : "No") << endl;
    cout << endl;
    
    // Sum and Average
    cout << "8. Sum and Average:" << endl;
    cout << "Sum of all nodes: " << obj.sumOfNodes() << endl;
    cout << "Average of nodes: " << obj.averageOfNodes() << endl;
    cout << endl;
    
    // Ancestors and Descendants
    cout << "9. Ancestors and Descendants:" << endl;
    obj.getAncestors(2);
    obj.getAncestors(4);
    obj.getAncestors(5);
    obj.getDescendants(5);
    obj.getDescendants(3);
    obj.getDescendants(2);
    cout << endl;
    
    // Delete
    cout << "10. Delete node 2:" << endl;
    obj.deleteMethod(2);
    cout << "In-Order after delete: ";
    obj.inOrder();
    cout << "Updated Count: " << obj.countNodes() << endl;
    cout << endl;
    
    // Clear
    cout << "11. Clear tree:" << endl;
    obj.clear();
    cout << "Is Empty after clear: " << (obj.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}
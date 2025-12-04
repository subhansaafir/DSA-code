#include <climits>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
      data = val;
      left = NULL;
      right = NULL;
  }
};

class BST {
private:
    Node *root;

    void Inorder(Node *root) {
      if (root == NULL) {
        return;
      }
      Inorder(root->left);
      cout << root->data << " ";
      Inorder(root->right);
    }

    void Preorder(Node *root) {
      if (root == NULL)
        return;
      cout << root->data << " ";
      Preorder(root->left);
      Preorder(root->right);
    }

    void Postorder(Node *root) {
      if (root == NULL)
        return;
      Postorder(root->left);
      Postorder(root->right);
      cout << root->data << " ";
    }

    bool isValid(Node *node, int min = INT_MIN, int max = INT_MAX) {
      if (node == NULL) {
        return true;
      }
      if (node->data < min || node->data > max) {
        return false;
      }
      return isValid(node->left, min, node->data) &&
            isValid(node->right, node->data, max);
    }

    Node *LCA(Node *root, int n1, int n2) {
      if (root == NULL)
        return NULL;
      if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
      if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
      return root;
    }

    void kthSmallestUtil(Node *root, int &k, int &result) {
      if (root == NULL || k <= 0)
        return;
      kthSmallestUtil(root->left, k, result);
      k--;
      if (k == 0) {
        result = root->data;
        return;
      }
      kthSmallestUtil(root->right, k, result);
    }

    void kthLargestUtil(Node *root, int &k, int &result) {
      if (root == NULL || k <= 0)
        return;
      kthLargestUtil(root->right, k, result);
      k--;
      if (k == 0) {
        result = root->data;
        return;
      }
      kthLargestUtil(root->left, k, result);
    }

    int search(int arr[], int start, int end, int value) {
      for (int i = start; i <= end; i++) {
        if (arr[i] == value)
          return i;
      }
      return -1;
    }

  Node *buildTreeUtil(int preorder[], int inorder[], int start, int end,
                      int &preIndex) {
    if (start > end)
      return NULL;

    int curr = preorder[preIndex++];
    Node *node = new Node(curr);

    if (start == end)
      return node;

    int inIndex = search(inorder, start, end, curr);

    node->left = buildTreeUtil(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = buildTreeUtil(preorder, inorder, inIndex + 1, end, preIndex);

    return node;
  }

public:
  BST() { root = NULL; }

  void insert(int val) {
    if (root == NULL) {
      root = new Node(val);
      return;
    }
    Node *temp = root;
    while (true) {
      if (val < temp->data) {
        if (temp->left == NULL) {
          temp->left = new Node(val);
          break;
        }
        temp = temp->left;
      } else {
        if (temp->right == NULL) {
          temp->right = new Node(val);
          break;
        }
        temp = temp->right;
      }
    }
  }

  Node *Search(int val) {
    Node *temp = root;
    while (temp != NULL) {
      if (val == temp->data) {
        return temp;
      } else if (val < temp->data) {
        temp = temp->left;
      } else {
        temp = temp->right;
      }
    }
    return NULL;
  }

  void Inorder() {
    Inorder(root);
    cout << endl;
  }

  void Preorder() {
    Preorder(root);
    cout << endl;
  }

  void Postorder() {
    Postorder(root);
    cout << endl;
  }

  void LevelOrder() {
    if (root == NULL)
      return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
      Node *current = q.front();
      q.pop();
      cout << current->data << " ";
      if (current->left != NULL)
        q.push(current->left);
      if (current->right != NULL)
        q.push(current->right);
    }
    cout << endl;
  }

  int min() {
    if (root == NULL)
      return -1; // Or handle error
    Node *temp = root;
    while (temp->left != NULL) {
      temp = temp->left;
    }
    return temp->data;
  }

  int max() {
    if (root == NULL)
      return -1; // Or handle error
    Node *temp = root;
    while (temp->right != NULL) {
      temp = temp->right;
    }
    return temp->data;
  }

  void Delete(int val) {
    Node *temp = root;
    Node *parent = NULL;
    // Find node
    while (temp != NULL && temp->data != val) {
      parent = temp;
      if (val < temp->data)
        temp = temp->left;
      else
        temp = temp->right;
    }

    if (temp == NULL)
      return; // Not found

    // Case 3: Two children
    if (temp->left != NULL && temp->right != NULL) {
      Node *successor = temp->right;
      Node *successorParent = temp;
      while (successor->left != NULL) {
        successorParent = successor;
        successor = successor->left;
      }
      temp->data = successor->data;
      // Now delete successor (which has at most one child - right)
      temp = successor;
      parent = successorParent;
    }

    // Case 1 & 2: Leaf or One child
    Node *child = (temp->left != NULL) ? temp->left : temp->right;

    if (parent == NULL) {
      root = child;
    } else if (parent->left == temp) {
      parent->left = child;
    } else {
      parent->right = child;
    }
    delete temp;
  }

  bool isValid() { return isValid(root, INT_MIN, INT_MAX); }

  int LCA(int n1, int n2) {
    Node *lca = LCA(root, n1, n2);
    return (lca != NULL) ? lca->data : -1;
  }

  int kthSmallest(int k) {
    int result = -1;
    kthSmallestUtil(root, k, result);
    return result;
  }

  int kthLargest(int k) {
    int result = -1;
    kthLargestUtil(root, k, result);
    return result;
  }

  void buildFromTraversals(int preorder[], int inorder[], int size) {
    int preIndex = 0;
    root = buildTreeUtil(preorder, inorder, 0, size - 1, preIndex);
  }
};
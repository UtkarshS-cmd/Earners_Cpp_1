
#include <iostream>
#include <algorithm>
using namespace std;

// AVL Tree Node
struct Node {
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int value) {
        key = value;
        left = right = NULL;
        height = 1;
    }
};

// Get height
int getHeight(Node* node) {
    if (node == NULL)
        return 0;

    return node->height;
}

// Get balance factor
int getBalance(Node* node) {
    if (node == NULL)
        return 0;

    return getHeight(node->left) -
           getHeight(node->right);
}

// Right rotation (LL)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    return x;
}

// Left rotation (RR)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left),
                        getHeight(x->right));

    y->height = 1 + max(getHeight(y->left),
                        getHeight(y->right));

    return y;
}

// Insert a node
Node* insert(Node* root, int key) {

    // Normal BST insertion
    if (root == NULL)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);

    else if (key > root->key)
        root->right = insert(root->right, key);

    else
        return root;

    // Update height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    // Calculate balance factor
    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Find minimum node
Node* minValueNode(Node* node) {
    Node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete a node
Node* deleteNode(Node* root, int key) {

    // Normal BST deletion
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {

        // Node with zero or one child
        if (root->left == NULL ||
            root->right == NULL) {

            Node* temp = root->left ?
                         root->left : root->right;

            // No child
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            // One child
            else {
                *root = *temp;
            }

            delete temp;
        }

        // Node with two children
        else {
            Node* temp = minValueNode(root->right);

            root->key = temp->key;

            root->right =
                deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    // Update height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    // Calculate balance
    int balance = getBalance(root);

    // LL Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR Case
    if (balance > 1 &&
        getBalance(root->left) < 0) {

        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL Case
    if (balance < -1 &&
        getBalance(root->right) > 0) {

        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Search
bool search(Node* root, int key) {

    if (root == NULL)
        return false;

    if (root->key == key)
        return true;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// Inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Preorder traversal
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

// Main function
int main() {

    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    int key = 25;

    if (search(root, key))
        cout << "\n" << key << " Found";
    else
        cout << "\n" << key << " Not Found";

    root = deleteNode(root, 20);

    cout << "\nAfter Deletion: ";
    inorder(root);

    return 0;
}

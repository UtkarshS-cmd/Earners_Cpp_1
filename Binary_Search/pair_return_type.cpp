#include<iostream>
#include<limits>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

class Data{ //dat: size, sum
public:
    int size;
    int sum;
    Data(int size, int sum){
        this->size = size;
        this->sum = sum;
    }
};

// aesa function jhan bst ya bt ka isze, sum, max, min saari chezzein return kr skun
Data sizeSum(Node* root){
    if(root == NULL) return Data(0,0); //or return {0,0}
    Data left = sizeSum(root->left);
    Data right = sizeSum(root->right);
    int size = 1 + left.size + right.size;
    int sum = 1 + left.sum + right.sum;
    return Data(size,sum);
}

void printTree(Node* root){
    if(root == NULL) return;
    // sumOfTree += root->val;
    // sizeOfTree += 1;
    // maxOfTree = max(maxOfTree,root->val);
    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);
}

pair<int,int> maxMin(Node* root){
    if(root == NULL) return {INT_MIN, INT_MAX};
    pair<int,int> left = maxMin(root->left);
    pair<int,int> right = maxMin(root->right);
    int mx = max(root->val, max(left.first, right.first));
    int mn = max(root->val, min(left.second, right.second));
    return {mx,mn};
}



int main(){
    Node* a = new Node(1); // root
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(8);
    Node* h = new Node(9);

    a->left = b; a->right = c;
    b->left = d; b->right = e;
    c->right = f;
    e->left = g; e->right = h;

    cout<<size(a)<<endl;
    cout<<sum(a)<<endl;
    cout<<maxInTree(a)<<endl;

    // sumOfTree = 0;
    // sizeOfTree = 0;
    // maxOfTree = INT_MIN;
    // printTree(a);
    // cout<<sumOfTree<<endl;

    // cout<<a->val<<endl;
    // cout<<a->left->val<<endl;
    // cout<<a->right->val<<endl;
    // cout<<a->left->left->val<<endl;
    // cout<<a->left->right->val<<endl;
    // cout<<a->right->right->val<<endl;
}
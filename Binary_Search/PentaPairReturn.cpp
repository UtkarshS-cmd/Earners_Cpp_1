// #GJBBB cheez hai ye
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

class Penta{
public:
    int size;
    int sum;
    Penta(int size, int sum, int BSTmax, int BSTmin, int levels ){
        this->size = size;
        this->sum = sum;
        this->BSTmax = BSTmax;
        this->BSTmin = BSTmin;
        this->levels = levels;
    }
};

Penta sizeSumMaxMinLevel(Node* root){
    if(root == NULL) return Penta(0,0,INT_MAX,INT_MIN,0); //or return {0,0}
    Penta left = sizeSumMaxMinLevel(root->left);
    Penta right = sizeSumMaxMinLevel(root->right);
    int size = 1 + left.size + right.size;
    int sum = 1 + left.sum + right.sum;
    int mx = max(root->val, max(left.mx, right.mx));
    int mn = min(root->val, min(left.mn, right.mn));
    int levels = 1 + max(left.level,right.level);
    
    return {size,sum,mx,mn,levels};
}

// // aesa function jhan bst ya bt ka isze, sum, max, min saari chezzein return kr skun
// Data sizeSum(Node* root){
//     if(root == NULL) return Data(0,0); //or return {0,0}
//     Data left = sizeSum(root->left);
//     Data right = sizeSum(root->left);
//     int size = 1 + left.size + right.size;
//     int sum = 1 + left.sum + right.sum;
//     return Data(size,sum);
// }

// pair<int,int> maxMin(Node* root){
//     if(root == NULL) return {INT_MIN, INT_MAX};
//     pair<int,int> left = maxMin(root->left);
//     pair<int,int> right = maxMin(root->right);
//     int mx = max(root->val, max(left.first, right.first));
//     int mn = max(root->val, min(left.second, right.second));
//     return {mx,mn};
// }

void printTree(Node* root){
    if(root == NULL) return;
    // sumOfTree += root->val;
    // sizeOfTree += 1;
    // maxOfTree = max(maxOfTree,root->val);
    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);
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
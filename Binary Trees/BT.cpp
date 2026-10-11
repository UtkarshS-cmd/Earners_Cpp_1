#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left, *right;

        Node(int key){
            data = key;
            left = nullptr;
            right = nullptr;
        }
}

int main(){
 Node* firstNode = newNode(2);
 Node* secondNode = newNode(2);
 Node* thirdNode = newNode(2);
 Node* fourthNode = newNode(2);

 firstNode->left = secondNode;
 firstNode->right = thirdNode;
 secondNode->left = fourthNode;

return 0;
}
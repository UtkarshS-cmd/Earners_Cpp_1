class Node{ // User Defined Data Type
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
    }
};

class MyLinkedList{ // User Defined Data Type
private:
    Node* head;
    Node* tail;
    int length;
public:
    MyLinkedList(){
        head = tail = NULL;
        length = 0;
    }
};
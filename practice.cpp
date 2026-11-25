class Node{
    public:
     int data;
     Node* next;

    Node(int value){
        this->data = value;
        next = nullptr;
    }
};

class LinkedList{
    public:
        Node* head;
        Node* tail;
        int length;

    // Helper function: Get node at a particular index
    Node* getNode(int index){
        if(index < 0|| index > length) return nullptr;

        Node* temp = head;

        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp;
    }

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    ~LinkedList() {
        clear();
    }

     void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
        length = 0;
    }

    void insertAtHead(int value){
        Node* newNode = newNode(value);


    }
}
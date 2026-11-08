#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = nullptr;
        }
    };

    Node* frontNode;
    Node* rearNode;
    int currSize;

public:
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
        currSize = 0;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    int size() {
        return currSize;
    }

    void enqueue(int ele) {
        Node* newNode = new Node(ele);

        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }

        currSize++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = frontNode;

        frontNode = frontNode->next;

        delete temp;
        currSize--;

        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return frontNode->data;
    }

    int rear() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return rearNode->data;
    }

    int getAtIdx(int idx) {
        if (idx < 0 || idx >= currSize) {
            cout << "Invalid Index\n";
            return -1;
        }

        Node* temp = frontNode;

        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }

        return temp->data;
    }

    void pushAtIdx(int idx, int ele) {
        if (idx < 0 || idx > currSize) {
            cout << "Invalid Index\n";
            return;
        }

        Node* newNode = new Node(ele);

        // Insert at the beginning.
        if (idx == 0) {
            newNode->next = frontNode;
            frontNode = newNode;

            if (rearNode == nullptr) {
                rearNode = newNode;
            }
        }

        // Insert at the end.
        else if (idx == currSize) {
            rearNode->next = newNode;
            rearNode = newNode;
        }

        // Insert in the middle.
        else {
            Node* temp = frontNode;

            for (int i = 0; i < idx - 1; i++) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        currSize++;
    }

    void popAtIdx(int idx) {
        if (idx < 0 || idx >= currSize) {
            cout << "Invalid Index\n";
            return;
        }

        Node* temp = frontNode;

        // Remove the first node.
        if (idx == 0) {
            frontNode = frontNode->next;
            delete temp;

            currSize--;

            if (frontNode == nullptr) {
                rearNode = nullptr;
            }

            return;
        }

        // Find the node immediately before the target.
        for (int i = 0; i < idx - 1; i++) {
            temp = temp->next;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;

        // Update rear if the last node was removed.
        if (nodeToDelete == rearNode) {
            rearNode = temp;
        }

        delete nodeToDelete;
        currSize--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        Node* temp = frontNode;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Original Queue: ";
    q.display();

    cout << "Front: " << q.front() << endl;
    cout << "Rear: " << q.rear() << endl;
    cout << "Size: " << q.size() << endl;

    cout << "\nInsert 25 at index 2:\n";
    q.pushAtIdx(2, 25);
    q.display();

    cout << "\nElement at index 3: ";
    cout << q.getAtIdx(3) << endl;

    cout << "\nRemove element at index 1:\n";
    q.popAtIdx(1);
    q.display();

    cout << "\nDequeue:\n";
    q.dequeue();
    q.display();

    return 0;
}
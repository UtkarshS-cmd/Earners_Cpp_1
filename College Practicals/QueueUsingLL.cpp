#include <iostream>
using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty())
            front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;
        cout << front->data << " removed successfully.\n";
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    void getFront() {
        if (isEmpty())
            cout << "Queue is empty!\n";
        else
            cout << "Front element: " << front->data << '\n';
    }

    void getRear() {
        if (isEmpty())
            cout << "Queue is empty!\n";
        else
            cout << "Rear element: " << rear->data << '\n';
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << '\n';
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n===== QUEUE USING LINKED LIST =====\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. Get Front\n";
        cout << "4. Get Rear\n";
        cout << "5. Display Queue\n";
        cout << "6. Check if Empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.getFront();
                break;
            case 4:
                q.getRear();
                break;
            case 5:
                q.display();
                break;
            case 6:
                cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

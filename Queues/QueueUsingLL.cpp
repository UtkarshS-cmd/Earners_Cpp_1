
#include <iostream>
using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;

        Node(int x) {
            data = x;
            next = NULL;
        }
    };

    Node* front;
    Node* rear;

public:

    Queue() : front(NULL), rear(NULL) {}

    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << x << " inserted into the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;

        cout << "Dequeued element: " << front->data << '\n';

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

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

        while (temp != NULL) {
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
                cout << (q.isEmpty() ?
                    "Queue is empty.\n" :
                    "Queue is not empty.\n");
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


#include <iostream>
using namespace std;

class Queue {
    int front, rear, capacity;
    int* arr;

public:
    Queue(int cap) {
        capacity = cap;
        front = -1;
        rear = -1;
        arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;
        arr[rear] = x;

        cout << x << " inserted into the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Dequeued element: " << arr[front] << '\n';

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void getFront() {
        if (isEmpty())
            cout << "Queue is empty!\n";
        else
            cout << "Front element: " << arr[front] << '\n';
    }

    void getRear() {
        if (isEmpty())
            cout << "Queue is empty!\n";
        else
            cout << "Rear element: " << arr[rear] << '\n';
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue elements: ";

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

        cout << '\n';
    }
};

int main() {
    int capacity;

    cout << "Enter queue capacity: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Capacity must be greater than zero.\n";
        return 1;
    }

    Queue q(capacity);
    int choice, value;

    do {
        cout << "\n===== LINEAR QUEUE MENU =====\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. Get Front\n";
        cout << "4. Get Rear\n";
        cout << "5. Display Queue\n";
        cout << "6. Check if Empty\n";
        cout << "7. Check if Full\n";
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
                cout << (q.isEmpty()
                    ? "Queue is empty.\n"
                    : "Queue is not empty.\n");
                break;

            case 7:
                cout << (q.isFull()
                    ? "Queue is full.\n"
                    : "Queue is not full.\n");
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
#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int capacity;
    int rear;

public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return rear == -1;
    }

    void enqueue(int value) {
        if (rear == capacity - 1) {
            cout << "Queue is full!\n";
            return;
        }

        arr[++rear] = value;
        cout << value << " inserted successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << arr[0] << " removed successfully.\n";

        for (int i = 0; i < rear; i++) {
            arr[i] = arr[i + 1];
        }
        rear--;
    }

    void getFront() {
        if (isEmpty())
            cout << "Queue is empty!\n";
        else
            cout << "Front element: " << arr[0] << '\n';
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
        for (int i = 0; i <= rear; i++) {
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
        cout << "\n===== QUEUE USING ARRAY =====\n";
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

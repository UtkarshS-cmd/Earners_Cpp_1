#include <iostream>
#include <stdexcept>
using namespace std;

class myQueue {
    int *arr;
    int capacity;
    int size;
    int front;

public:
    myQueue(int c) : arr(nullptr), capacity(c), size(0), front(0) {
        if (capacity <= 0) {
            throw invalid_argument("Queue capacity must be greater than zero.");
        }
        arr = new int[capacity];
    }

    ~myQueue() {
        delete[] arr;
    }

    myQueue(const myQueue&) = delete;
    myQueue& operator=(const myQueue&) = delete;

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }

        arr[(front + size) % capacity] = x;
        size++;

        cout << x << " inserted successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << arr[front] << " removed successfully.\n";
        front = (front + 1) % capacity;
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        return arr[(front + size - 1) % capacity];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue: FRONT -> ";

        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }

        cout << "<- REAR\n";
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

    myQueue q(capacity);
    int choice, value;

    do {
        cout << "\n========== QUEUE MENU ==========\n";
        cout << "1. Enqueue (Insert element)\n";
        cout << "2. Dequeue (Remove element)\n";
        cout << "3. Get Front element\n";
        cout << "4. Get Rear element\n";
        cout << "5. Display Queue\n";
        cout << "6. Check if Queue is Empty\n";
        cout << "7. Check if Queue is Full\n";
        cout << "8. Exit\n";
        cout << "================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                if (!q.isEmpty())
                    cout << "Front element: "
                         << q.getFront() << "\n";
                else
                    q.getFront();
                break;

            case 4:
                if (!q.isEmpty())
                    cout << "Rear element: "
                         << q.getRear() << "\n";
                else
                    q.getRear();
                break;

            case 5:
                q.display();
                break;

            case 6:
                if (q.isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;

            case 7:
                if (q.isFull())
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;

            case 8:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please select 1-8.\n";
        }

    } while (choice != 8);

    return 0;
}
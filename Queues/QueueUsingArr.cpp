#include <iostream>
using namespace std;

class myQueue {
    int *arr;
    int capacity;
    int size;

public:
    myQueue(int c) {
        capacity = c;
        arr = new int[capacity];
        size = 0;
    }

    // Free dynamically allocated memory
    ~myQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    // Add element to rear
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }

        arr[size] = x;
        size++;

        cout << x << " inserted successfully.\n";
    }

    // Remove front element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << arr[0] << " removed successfully.\n";

        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }

        size--;
    }

    // Return front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        return arr[0];
    }

    // Return rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }

        return arr[size - 1];
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue: FRONT -> ";

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
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
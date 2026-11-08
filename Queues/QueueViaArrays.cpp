#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int frontIdx;
    int rearIdx;
    int currSize;

public:
    Queue(int cap = 100) {
        capacity = cap;
        arr = new int[capacity];

        frontIdx = 0;
        rearIdx = -1;
        currSize = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return currSize == 0;
    }

    bool isFull() {
        return currSize == capacity;
    }

    int size() {
        return currSize;
    }

    void enqueue(int ele) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        rearIdx = (rearIdx + 1) % capacity;
        arr[rearIdx] = ele;
        currSize++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        frontIdx = (frontIdx + 1) % capacity;
        currSize--;

        if (currSize == 0) {
            frontIdx = 0;
            rearIdx = -1;
        }
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return arr[frontIdx];
    }

    int rear() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return arr[rearIdx];
    }

    int getAtIdx(int idx) {
        if (idx < 0 || idx >= currSize) {
            cout << "Invalid Index\n";
            return -1;
        }

        return arr[(frontIdx + idx) % capacity];
    }

    void pushAtIdx(int idx, int ele) {
        if (idx < 0 || idx > currSize) {
            cout << "Invalid Index\n";
            return;
        }

        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        // Shift elements towards the rear.
        for (int i = currSize; i > idx; i--) {
            arr[(frontIdx + i) % capacity] =
                arr[(frontIdx + i - 1) % capacity];
        }

        arr[(frontIdx + idx) % capacity] = ele;

        currSize++;
        rearIdx = (frontIdx + currSize - 1) % capacity;
    }

    void popAtIdx(int idx) {
        if (idx < 0 || idx >= currSize) {
            cout << "Invalid Index\n";
            return;
        }

        // Shift elements towards the front.
        for (int i = idx; i < currSize - 1; i++) {
            arr[(frontIdx + i) % capacity] =
                arr[(frontIdx + i + 1) % capacity];
        }

        currSize--;

        if (currSize == 0) {
            
            
            rearIdx = -1;
        } else {
            rearIdx = (frontIdx + currSize - 1) % capacity;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        for (int i = 0; i < currSize; i++) {
            cout << getAtIdx(i) << " ";
        }

        cout << endl;
    }
};

int main() {
    Queue q(10);

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
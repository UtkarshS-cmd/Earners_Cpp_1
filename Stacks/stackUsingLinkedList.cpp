#include <iostream>
using namespace std;

class Stack {
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* top;
    int size;
    int maxSize;

public:
    Stack(int capacity) {
        top = nullptr;
        size = 0;
        maxSize = capacity;
    }

    void push(int x) {
        if (size == maxSize) {
            cout << "Stack Overflow\n";
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        size++;
        cout << x << " pushed into stack\n";
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        cout << "Popped: " << top->data << endl;
        top = top->next;
        delete temp;
        size--;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return;
        }

        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s(3);
    int ch, data;

    do {
        cout << "\n1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                s.push(data);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            case 4:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }
    } while (ch != 4);

    return 0;
}
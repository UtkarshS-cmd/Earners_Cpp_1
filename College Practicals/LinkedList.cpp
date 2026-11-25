#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertAtHead(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtIndex(Node*& head, int index, int value) {
    if (index < 1) {
        cout << "Invalid index!\n";
        return;
    }

    if (index == 1) {
        insertAtHead(head, value);
        return;
    }

    Node* current = head;
    for (int position = 1; current != nullptr && position < index - 1; position++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid index!\n";
        return;
    }

    Node* newNode = createNode(value);
    newNode->next = current->next;
    current->next = newNode;
}

void deleteAtHead(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* nodeToDelete = head;
    head = head->next;
    delete nodeToDelete;
}

void deleteLast(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
}

void deleteAtIndex(Node*& head, int index) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (index < 1) {
        cout << "Invalid index!\n";
        return;
    }

    if (index == 1) {
        deleteAtHead(head);
        return;
    }

    Node* current = head;
    for (int position = 1; current != nullptr && position < index - 1; position++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid index!\n";
        return;
    }

    Node* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;
}

void display(const Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty\n";
        return;
    }

    const Node* current = head;
    cout << "HEAD -> ";
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice, value, index;

    do {
        cout << "\n===== LINKED LIST MENU =====\n"
             << "1. Insert at head\n"
             << "2. Insert at index\n"
             << "3. Insert at end\n"
             << "4. Delete at head\n"
             << "5. Delete last\n"
             << "6. Delete at index\n"
             << "7. Display\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtHead(head, value);
                break;
            case 2:
                cout << "Enter index and value: ";
                cin >> index >> value;
                insertAtIndex(head, index, value);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 4:
                deleteAtHead(head);
                break;
            case 5:
                deleteLast(head);
                break;
            case 6:
                cout << "Enter index: ";
                cin >> index;
                deleteAtIndex(head, index);
                break;
            case 7:
                display(head);
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    while (head != nullptr) {
        deleteAtHead(head);
    }
    return 0;
}

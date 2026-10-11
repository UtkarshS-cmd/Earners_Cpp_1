#include <iostream>
using namespace std;

class DoublyLinkedList {

private:

    // Node structure
    class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data) {
            this->data = data;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:

    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Destructor
    ~DoublyLinkedList() {
        clear();
    }


    // =========================================
    // 1. INSERT AT BEGINNING
    // =========================================

    void insertAtBeginning(int data) {

        Node* newNode = new Node(data);

        // Empty list
        if (head == nullptr) {
            head = tail = newNode;
        }

        // Non-empty list
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        size++;
    }


    // =========================================
    // 2. INSERT AT END
    // =========================================

    void insertAtEnd(int data) {

        Node* newNode = new Node(data);

        // Empty list
        if (tail == nullptr) {
            head = tail = newNode;
        }

        // Non-empty list
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }


    // =========================================
    // 3. INSERT AT POSITION
    // Position starts from 1
    // =========================================

    void insertAtPosition(int data, int position) {

        if (position < 1 || position > size + 1) {
            cout << "Invalid position\n";
            return;
        }

        // Beginning
        if (position == 1) {
            insertAtBeginning(data);
            return;
        }

        // End
        if (position == size + 1) {
            insertAtEnd(data);
            return;
        }

        Node* current = head;

        // Move to node currently at position
        for (int i = 1; i < position; i++) {
            current = current->next;
        }

        Node* newNode = new Node(data);

        // Connect new node
        newNode->prev = current->prev;
        newNode->next = current;

        // Connect previous node
        current->prev->next = newNode;

        // Connect current node
        current->prev = newNode;

        size++;
    }


    // =========================================
    // 4. DELETE FROM BEGINNING
    // =========================================

    void deleteFromBeginning() {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        // Only one node
        if (head == tail) {
            head = tail = nullptr;
        }

        // Multiple nodes
        else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
        size--;
    }


    // =========================================
    // 5. DELETE FROM END
    // =========================================

    void deleteFromEnd() {

        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail;

        // Only one node
        if (head == tail) {
            head = tail = nullptr;
        }

        // Multiple nodes
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        size--;
    }


    // =========================================
    // 6. DELETE FROM POSITION
    // =========================================

    void deleteFromPosition(int position) {

        if (position < 1 || position > size) {
            cout << "Invalid position\n";
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        if (position == size) {
            deleteFromEnd();
            return;
        }

        Node* current = head;

        for (int i = 1; i < position; i++) {
            current = current->next;
        }

        // Connect previous node to next node
        current->prev->next = current->next;

        // Connect next node to previous node
        current->next->prev = current->prev;

        delete current;
        size--;
    }


    // =========================================
    // 7. DELETE BY VALUE
    // Deletes first occurrence
    // =========================================

    void deleteByValue(int value) {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* current = head;

        while (current != nullptr && current->data != value) {
            current = current->next;
        }

        // Value not found
        if (current == nullptr) {
            cout << "Value not found\n";
            return;
        }

        // First node
        if (current == head) {
            deleteFromBeginning();
            return;
        }

        // Last node
        if (current == tail) {
            deleteFromEnd();
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;
        size--;
    }


    // =========================================
    // 8. SEARCH
    // =========================================

    bool search(int value) {

        Node* current = head;

        while (current != nullptr) {

            if (current->data == value) {
                return true;
            }

            current = current->next;
        }

        return false;
    }


    // =========================================
    // 9. DISPLAY FORWARD
    // =========================================

    void displayForward() {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }

        cout << "NULL\n";
    }


    // =========================================
    // 10. DISPLAY BACKWARD
    // =========================================

    void displayBackward() {

        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* current = tail;

        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->prev;
        }

        cout << "NULL\n";
    }


    // =========================================
    // 11. GET FRONT
    // =========================================

    int getFront() {

        if (head == nullptr) {
            cout << "List is empty\n";
            return -1;
        }

        return head->data;
    }


    // =========================================
    // 12. GET BACK
    // =========================================

    int getBack() {

        if (tail == nullptr) {
            cout << "List is empty\n";
            return -1;
        }

        return tail->data;
    }


    // =========================================
    // 13. GET SIZE
    // =========================================

    int getSize() {
        return size;
    }


    // =========================================
    // 14. CHECK EMPTY
    // =========================================

    bool isEmpty() {
        return head == nullptr;
    }


    // =========================================
    // 15. REVERSE LIST
    // =========================================

    void reverse() {

        Node* current = head;

        while (current != nullptr) {

            // Swap prev and next
            Node* temp = current->prev;

            current->prev = current->next;
            current->next = temp;

            current = current->prev;
        }

        // Swap head and tail
        Node* temp = head;
        head = tail;
        tail = temp;
    }


    // =========================================
    // 16. CLEAR ENTIRE LIST
    // =========================================

    void clear() {

        Node* current = head;

        while (current != nullptr) {

            Node* temp = current;
            current = current->next;

            delete temp;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};


// =============================================
// MAIN
// =============================================

int main() {

    DoublyLinkedList dll;

    // Insert
    dll.insertAtBeginning(20);
    dll.insertAtBeginning(10);

    dll.insertAtEnd(30);
    dll.insertAtEnd(40);

    cout << "Forward:\n";
    dll.displayForward();

    cout << "\nBackward:\n";
    dll.displayBackward();


    // Insert at position
    cout << "\nAfter inserting 25 at position 3:\n";

    dll.insertAtPosition(25, 3);
    dll.displayForward();


    // Delete from beginning
    cout << "\nAfter deleting from beginning:\n";

    dll.deleteFromBeginning();
    dll.displayForward();


    // Delete from end
    cout << "\nAfter deleting from end:\n";

    dll.deleteFromEnd();
    dll.displayForward();


    // Delete from position
    cout << "\nAfter deleting position 2:\n";

    dll.deleteFromPosition(2);
    dll.displayForward();


    // Insert again
    dll.insertAtEnd(50);
    dll.insertAtEnd(60);

    cout << "\nCurrent list:\n";
    dll.displayForward();


    // Delete by value
    cout << "\nDeleting 50:\n";

    dll.deleteByValue(50);
    dll.displayForward();


    // Search
    cout << "\nSearching 60:\n";

    if (dll.search(60))
        cout << "Found\n";
    else
        cout << "Not Found\n";


    // Front and back
    cout << "\nFront: " << dll.getFront() << endl;
    cout << "Back: " << dll.getBack() << endl;

    cout << "Size: " << dll.getSize() << endl;


    // Reverse
    cout << "\nAfter reversing:\n";

    dll.reverse();
    dll.displayForward();


    // Backward after reverse
    cout << "\nBackward:\n";

    dll.displayBackward();


    return 0;
}
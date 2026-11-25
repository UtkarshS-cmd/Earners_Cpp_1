
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Parameterized constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

    // Helper function: Get node at a particular index
    Node* getNode(int index) {
        if (index < 0 || index >= length)
            return nullptr;

        Node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp;
    }

public:

    // Constructor
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // Destructor: Free dynamically allocated memory
    ~LinkedList() {
        clear();
    }

    // 1. Create Linked List
    void createList() {
        int n, value;

        cout << "Enter number of nodes: ";
        cin >> n;

        if (n < 0) {
            cout << "Invalid number of nodes!\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            cout << "Enter data: ";
            cin >> value;
            insertAtEnd(value);
        }
    }

    // 2. Display Linked List
    void display() const {
        if (head == nullptr) {
            cout << "Linked List is Empty\n";
            return;
        }

        Node* temp = head;

        cout << "HEAD -> ";

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // 3. Insert at Beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }

        length++;
    }

    // 4. Insert at End
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

        length++;
    }

    // 5. Insert at Specific Position (1-based)
    void insertAtPosition(int position, int value) {
        if (position < 1 || position > length + 1) {
            cout << "Invalid Position!\n";
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        if (position == length + 1) {
            insertAtEnd(value);
            return;
        }

        Node* temp = getNode(position - 2);
        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;

        length++;
    }

    // 6. Delete from Beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is Empty!\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;
        length--;

        if (head == nullptr) {
            tail = nullptr;
        }
    }

    // 7. Delete from End
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is Empty!\n";
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            length--;
            return;
        }

        Node* temp = head;

        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;

        length--;
    }

    // 8. Delete from Specific Position (1-based)
    void deleteAtPosition(int position) {
        if (position < 1 || position > length) {
            cout << "Invalid Position!\n";
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        if (position == length) {
            deleteFromEnd();
            return;
        }

        Node* temp = getNode(position - 2);
        Node* nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;
        length--;
    }

    // 9. Search an Element
    int search(int value) const {
        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                return position;
            }

            temp = temp->next;
            position++;
        }

        return -1;
    }

    // 10. Update a Node
    void update(int position, int value) {
        Node* temp = getNode(position - 1);

        if (temp == nullptr) {
            cout << "Invalid Position!\n";
            return;
        }

        temp->data = value;
    }

    // 11. Find Length
    int size() const {
        return length;
    }

    // 12. Reverse Linked List
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode = nullptr;

        tail = head;

        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }

    // 13. Find Middle Element
    void findMiddle() const {
        if (head == nullptr) {
            cout << "List is Empty!\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle Element: " << slow->data << endl;
    }

    // 14. Find Maximum Element
    void findMaximum() const {
        if (head == nullptr) {
            cout << "List is Empty!\n";
            return;
        }

        int maximum = head->data;
        Node* temp = head->next;

        while (temp != nullptr) {
            if (temp->data > maximum) {
                maximum = temp->data;
            }

            temp = temp->next;
        }

        cout << "Maximum Element: " << maximum << endl;
    }

    // 15. Count Occurrences
    int countOccurrences(int value) const {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == value) {
                count++;
            }

            temp = temp->next;
        }

        return count;
    }

    // 16. Remove all occurrences of a value
    void removeAll(int value) {
        while (head != nullptr && head->data == value) {
            deleteFromBeginning();
        }

        Node* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->data == value) {
                Node* nodeToDelete = temp->next;
                temp->next = nodeToDelete->next;

                if (nodeToDelete == tail) {
                    tail = temp;
                }

                delete nodeToDelete;
                length--;
            }
            else {
                temp = temp->next;
            }
        }
    }

    // 17. Clear Entire Linked List
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        tail = nullptr;
        length = 0;
    }
};


// MAIN FUNCTION
int main() {

    LinkedList ll;

    int choice, value, position;

    do {
        cout << "\n========== LINKED LIST MENU ==========\n";

        cout << "1. Create Linked List\n";
        cout << "2. Display Linked List\n";
        cout << "3. Insert at Beginning\n";
        cout << "4. Insert at End\n";
        cout << "5. Insert at Position\n";
        cout << "6. Delete from Beginning\n";
        cout << "7. Delete from End\n";
        cout << "8. Delete at Position\n";
        cout << "9. Search Element\n";
        cout << "10. Update Element\n";
        cout << "11. Find Length\n";
        cout << "12. Reverse Linked List\n";
        cout << "13. Find Middle Element\n";
        cout << "14. Find Maximum Element\n";
        cout << "15. Count Occurrences\n";
        cout << "16. Remove All Occurrences\n";
        cout << "17. Clear Linked List\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                ll.createList();
                break;

            case 2:
                ll.display();
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                ll.insertAtBeginning(value);
                break;

            case 4:
                cout << "Enter value: ";
                cin >> value;
                ll.insertAtEnd(value);
                break;

            case 5:
                cout << "Enter position and value: ";
                cin >> position >> value;
                ll.insertAtPosition(position, value);
                break;

            case 6:
                ll.deleteFromBeginning();
                break;

            case 7:
                ll.deleteFromEnd();
                break;

            case 8:
                cout << "Enter position: ";
                cin >> position;
                ll.deleteAtPosition(position);
                break;

            case 9:
                cout << "Enter value to search: ";
                cin >> value;

                position = ll.search(value);

                if (position == -1)
                    cout << "Element Not Found\n";
                else
                    cout << "Element Found at Position: "
                         << position << endl;
                break;

            case 10:
                cout << "Enter position and new value: ";
                cin >> position >> value;
                ll.update(position, value);
                break;

            case 11:
                cout << "Length: " << ll.size() << endl;
                break;

            case 12:
                ll.reverse();
                cout << "Linked List Reversed!\n";
                break;

            case 13:
                ll.findMiddle();
                break;

            case 14:
                ll.findMaximum();
                break;

            case 15:
                cout << "Enter value: ";
                cin >> value;
                cout << "Occurrences: "
                     << ll.countOccurrences(value) << endl;
                break;

            case 16:
                cout << "Enter value to remove: ";
                cin >> value;
                ll.removeAll(value);
                break;

            case 17:
                ll.clear();
                cout << "Linked List Cleared!\n";
                break;

            case 0:
                cout << "Program Terminated!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Function to delete the last node
Node* DeleteAtEnd(Node* head)
{
    // If the list is empty, return nullptr
    if (head == nullptr) {
        return nullptr;
    }

    // If the list has only one node, delete it and return nullptr
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Find the second last node
    Node* second_last = head;
    while (second_last->next->next != nullptr) {
        second_last = second_last->next;
    }

    // Delete the last node
    delete (second_last->next);

    // Change next of second last
    second_last->next = nullptr;

    return head;
}

void printList(Node* head)
{
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of nodes." << endl;
        return 1;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    // Create the linked list based on user input
    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;

        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original list: ";
    printList(head);

    // Removing the last node
    head = DeleteAtEnd(head);

    cout << "List after removing the last node: ";
    printList(head);

    // Free remaining nodes
    while (head != nullptr) {
        head = DeleteAtEnd(head);
    }

    return 0;
}

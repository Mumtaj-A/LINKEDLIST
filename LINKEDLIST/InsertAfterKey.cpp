#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* insertAfter(Node* head, int key, int newData) {
  
  // Iterate over Linked List to find the key
    while (head != nullptr) {
        if (head->data == key)
            break;
        head = head->next;
    }

    if (head == nullptr)
        return head;

    // Allocate new node by given data and point
    // the next of newNode to head's next &
    // point current next to newNode
    Node* newNode = new Node(newData);
    newNode->next = head->next;
    head->next = newNode;
    return head;
}

void printList(Node* node) {
  
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
  
    Node* head = new Node(22);
    head->next = new Node(33);
    head->next->next = new Node(55);
    head->next->next->next = new Node(66);
    
    int newData;
    int key;
    cout << "Enter a value for NEWDATA : ";
    cin >> newData;

    cout << "Enter a value for KEY : ";
    cin >> key;

    cout << "You entered NEWDATA : " << newData << " and KEY : " << key << endl;
    head = insertAfter(head, key, newData);
    printList(head);
    
    return 0;
}
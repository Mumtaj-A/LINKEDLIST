#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* insertBeforeKey(Node* head, int key, int newData) {

    // If the list is empty
    if (head == nullptr) {
        return nullptr;
    }

    // Special case: if the key is at the head
    if (head->data == key) {
        Node* new_node = new Node(newData);
        new_node->next = head;
        return new_node;
    }

    // Initialize current and previous pointers
    Node* curr = head;
    Node* prev = nullptr;

    // Traverse the list to find the key
    while (curr != nullptr && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If the key was found
    if (curr != nullptr) {
        Node* new_node = new Node(newData);
        prev->next = new_node;
        new_node->next = curr;
    }

   return head;
}

void printList(Node* node) {
    Node* curr = node;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    Node* head = new Node(11);
    head->next = new Node(22);
    head->next->next = new Node(33);
    head->next->next->next = new Node(44);
    head->next->next->next->next = new Node(55);
    
    int newData;
    int key;
    cout << "Enter a value for NEWDATA : ";
    cin >> newData;

    cout << "Enter a value for KEY : ";
    cin >> key;

    // Outputting the entered values
    cout << "You entered NEWDATA : " << newData << " and KEY : " << key << endl;
     head=insertBeforeKey(head, key, newData);
     printList(head);

    return 0;
}
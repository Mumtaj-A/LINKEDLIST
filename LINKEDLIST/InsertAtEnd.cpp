#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

Node* insertAtEnd(Node* head, int new_data) {
  
    // Create a new node
    Node* new_node = new Node(new_data);

    // If the Linked List is empty, make
    // the new node as the head and return
    if (head == nullptr) {
        return new_node;
    }

    // Store the head reference in a temporary variable
    Node* last = head;

    // Traverse till the last node
    while (last->next != nullptr) {
        last = last->next;
    }

    // Change the next pointer of the last node
    // to point to the new node
    last->next = new_node;

    // Return the head of the list
    return head;
}

void printList(Node* last)
{
    while (last != nullptr) {
        cout << last->data << " ";
        last = last->next;
    }
     cout << endl;
}

int main()
{
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);

   int new_data, n;
    
    cout << "Enter the number INSERT AT END: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> new_data;
        head = insertAtEnd(head,new_data);
        printList(head);
    }
    return 0;
}

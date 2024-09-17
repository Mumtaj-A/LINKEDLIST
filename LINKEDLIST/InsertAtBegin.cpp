#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr; 
    }
};

Node* insertAtFront(Node* head, int new_data) {
  
    // Create a new node with the given data
    Node* new_node = new Node(new_data);
    new_node->next = head;
    return new_node;
}

void printList(Node* head) {
    while (head != nullptr) {
      
        // Print the current node's data
        cout << " " << head->data;

        // Move to the next node
        head = head->next;
    }

    // Print a newline at the end
    cout << endl;
}

int main() {
  
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    int data, n;
    
    cout << "Enter the number INSERT: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> data;
    head = insertAtFront(head, data);
    printList(head);
}
    return 0;
}

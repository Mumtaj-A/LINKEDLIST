#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to insert a node at a specific position in the
// linked list.
Node* insertAtPosition(Node* head, int position, int data) {
    Node* newNode = new Node(data);

    // If inserting at the beginning
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* current = head;
  
    // Traverse the list to find the node before the
    // insertion point
    for (int i = 1; i < position - 1 && current != nullptr;
         ++i) {
        current = current->next;
    }

    // If the position is out of bounds
    if (current == nullptr) {
        cout << "Position is out of bounds." << endl;
      
        // Deallocate memory to prevent
        delete newNode; 
                       
        return head;
    }

    // Insert the new node at the specified position
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to print the linked list.
void printList(Node* head) {
    while (head != nullptr) {
        cout << " " << head->data;
        head = head->next;
    }
    cout << endl;
}

int main() {
  
    // Creating the list 3->5->8->10
    Node* head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(8);
    head->next->next->next = new Node(10);

    int data;
    int pos;
    cout << "Enter a value for DATA : ";
    cin >> data;

    cout << "Enter a value for KEY : ";
    cin >> pos;

    // Outputting the entered values
    cout << "You entered DATA : " << data << " and POSITION : " << pos << endl;
    head = insertAtPosition(head, pos, data);
 
    printList(head);

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};
Node* deleteHead(Node* head)
{

    if (head == nullptr)
        return nullptr;
  // delete the first data mean temp
    Node* temp = head;
    head = head->next;
    delete temp;
  
      return head;
}

void printList(Node* head)
{
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout  << endl;
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

    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;

        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = head;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original list: ";
    printList(head);
    
    // Deleting the head node
    head = deleteHead(head);
    cout << "List after deleting the head: ";
    printList(head);

    // Free remaining nodes
    while (head != nullptr) {
        head = deleteHead(head);
    }

    return 0;
}

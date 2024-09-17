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
Node* deleteAtBegining(Node* head)
{
    // Base case if linked list is empty
    if (head == nullptr)
        return nullptr;

    Node* temp = head;
    head = head->next;
    delete temp;
  
    // Return the new head
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
   
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);
    // Deleting the head node
    head = deleteAtBegining(head);
    cout << "List after deleting the head: ";
    printList(head);

    return 0;
}

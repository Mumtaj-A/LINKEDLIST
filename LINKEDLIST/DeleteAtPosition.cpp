#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int data){
     this-> data=data;
      this->next=nullptr;
    }
};

Node* deleteNode(Node* head, int position)
{
    // previous of node to be deleted
    Node* prev;
    Node* temp = head;

    if (temp == NULL)
        return head;

    // Case 1: Head is to be deleted
    if (position == 1) {
        // make next node as head and free old head
        head = temp->next;
        free(temp);
        return head;
    }

    // Case 2: Node to be deleted is in middle
    // Traverse till given position
    for (int i = 1; i != position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If given position is found, delete node
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    else {
        cout << "Data not present\n";
    }

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
    
    int pos;
    cout << "ENTER POSITION YOU WANT TO DELETE  : ";
    cin >> pos;

    // Outputting the entered values
    cout << "Enter the POSITION : " << pos << endl;
    head = deleteNode(head, pos);
    cout << "List after deletion : ";
    printList(head);

    // Cleanup remaining nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
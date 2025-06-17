#include <iostream>
using namespace std;

// Definition for singly-linked list node
class Node
{
public:
    int data;      // Value stored in the node
    Node *next;    // Pointer to the next node

    // Constructor to initialize node with a value
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    Node *head;
    head = NULL;

    int arr[] = {20, 30, 40, 50}; // Array of values to insert

    // Insert each element at the beginning of the linked list
    for(int i = 0; i < 4; i++) {
        if (head == NULL)
        {
            head = new Node(arr[i]); // First node becomes head
        }
        else
        {
            Node *temp;
            temp = new Node(arr[i]); // Create new node
            temp->next = head;       // Point new node to current head
            head = temp;             // Update head to new node
        }
    }

    cout << "Linked List: ";
    // Print the linked list
    Node *current = head;
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}

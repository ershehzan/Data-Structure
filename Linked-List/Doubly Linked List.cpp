#include <iostream>
using namespace std;

// Definition of the node class for a doubly linked list
class node
{
public:
    int data;      // Data stored in the node
    node *next;    // Pointer to the next node in the list
    node *prev;    // Pointer to the previous node in the list

    // Constructor to initialize a node with a value
    node(int val)
    {
        data = val;
        next = NULL; // By default, next is set to NULL
        prev = NULL; // By default, prev is set to NULL
    }
};

int main()
{
    node *head = NULL; // Pointer to the head (first node) of the list
    node *tail = NULL; // Pointer to the tail (last node) of the list
    int n;
    cout << "Enter the number of Nodes: ";
    cin >> n;
    cout << "Enter the values: ";

    // Creating the doubly linked list from user input
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if (head == NULL)
        {
            // For the first element, create a new node and set both head and tail to it
            head = new node(val);
            tail = head;
        }
        else
        {
            // For subsequent elements, create a new node at the end
            node *temp = new node(val);
            tail->next = temp;     // Link the current tail's next to new node
            temp->prev = tail;     // Link new node's prev to current tail
            tail = temp;           // Update tail to the new node
        }
    }

    // Print the doubly linked list
    node *curr = head; // Pointer to traverse the list
    cout << "Doubly Linked List: ";
    while (curr != NULL)
    {
        cout << curr->data << " "; // Print data of each node
        curr = curr->next;         // Move to the next node
    }
}

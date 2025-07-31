// Include necessary header file for input/output operations
#include <iostream>
using namespace std;

// Definition of the node class for linked list
class node
{
public:
    int data;      // Value stored in the node
    node *next;    // Pointer to the next node

    // Constructor to initialize node with a value
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Recursive function to delete the node at position 'x'
node *deletenode(node* current, int x) {
    // Base case: if x is 1, we need to delete the current node
    if (x == 1) {
        node* temp = current->next; // Store next node
        delete current;             // Delete current node
        return temp;                // Return new head of the list
    }
    // Recursive case: move to the next node, decrement position
    current->next = deletenode(current->next, x - 1);
    return current; // Return current node as part of the updated list
}

int main()
{
    node *head = NULL; // Pointer to head of linked list
    node *tail = NULL; // Pointer to tail of linked list

    int arr[100];      // Array to store node values
    int n;             // Number of nodes

    // Get number of nodes from user
    cout << "Enter the number of Nodes for linked list: ";
    cin >> n;

    // Get node values from user
    cout << "Enter the elements of Nodes in linked list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Create linked list from input values
    for (int i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            // If list is empty, create the first node
            head = new node(arr[i]);
            tail = head;
        }
        else
        {
            // Otherwise, append new node to the end
            tail->next = new node(arr[i]);
            tail = tail->next;
        }
    }

    int x; // Position of node to delete

    // Get position from user for deletion
    cout << "Enter the value of the node to be deleted: ";
    cin >> x;

    // Delete the node at position x and update head
    head = deletenode(head, x);

    // Print the linked list after deletion
    cout << "Linked List After Deletion: ";
    node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

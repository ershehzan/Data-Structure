#include <iostream>
using namespace std;

// Definition of a singly-linked list node
class node
{
public:
    int data;      // Value stored in the node
    node *next;    // Pointer to the next node

    // Constructor to initialize a node with a value
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Recursive function to delete the x-th node in the linked list
node* deletenode(node* current, int x) {
    // Base case: if x == 1, delete the current node
    if (x == 1) {
        node* temp = current->next; // Store the next node
        delete current;             // Delete the current node
        return temp;                // Return the next node as the new head (for this sublist)
    }
    // Recursive call: move to the next node, decrease x by 1
    current->next = deletenode(current->next, x - 1);
    return current; // Return the current node after updating its next pointer
}

int main()
{
    node *head = NULL; // Head pointer for the linked list
    node *tail = NULL; // Tail pointer for easy insertion at the end

    int arr[100];      // Array to store input values
    int n;
    cout << "Enter the number of Nodes for linked list: ";
    cin >> n;
    cout << "Enter the elements of Nodes in linked list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read node values from user input
    }

    // Create the linked list from the input array
    for (int i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            head = new node(arr[i]); // First node becomes the head
            tail = head;
        }
        else
        {
            tail->next = new node(arr[i]); // Append new node at the end
            tail = tail->next;
        }
    }

    int x;
    cout << "Enter the value of the node to be deleted: ";
    cin >> x;

    // Delete the x-th node using the recursive function
    head = deletenode(head, x);

    // Output the linked list after deletion
    cout << "Linked List After Deletion: ";
    node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

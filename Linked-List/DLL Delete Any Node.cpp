#include <iostream>
using namespace std;

// Definition for a node in a doubly linked list
class node
{
public:
    int data;      // Value stored in the node
    node *next;    // Pointer to the next node
    node *prev;    // Pointer to the previous node

    // Constructor to initialize the node with a value
    node(int val)
    {
        data = val;
        next = prev = NULL; // Set both next and prev to NULL initially
    }
};

int main()
{
    node *head = NULL; // Points to the first node of the list
    node *tail = NULL; // Points to the last node of the list

    int n;
    // Ask user for the number of nodes to create
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;
    cout << "Enter the values of the nodes: ";

    // Build the doubly linked list by taking n values from the user
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        // If the list is empty, initialize head and tail to the first node
        if (head == NULL)
        {
            head = new node(val);
            tail = head;
        }
        // Otherwise, append new node to the end and update pointers
        else
        {
            node *temp = new node(val);
            tail->next = temp;    // Set current tail's next to new node
            temp->prev = tail;    // Set new node's prev to current tail
            tail = temp;          // Move tail to the new node
        }
    }

    int pos;
    // Ask user for the position of the node to delete (1-based index)
    cout << "Enter the position of the node you want to delete: ";
    cin >> pos;

    // Case 1: Deleting the head (first node)
    if (pos == 1)
    {
        // If there is only one node in the list
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        // If there are multiple nodes
        else
        {
            node *temp = head;         // Store pointer to current head
            head = head->next;         // Move head to next node
            delete temp;               // Delete old head
            head->prev = NULL;         // Set new head's prev to NULL
        }
    }
    // Case 2: Deleting a node other than the head
    else
    {
        node *curr = head;
        // Traverse to the node at position 'pos'
        while (--pos)
        {
            curr = curr->next;
        }

        // Sub-case: Deleting the last node
        if (curr->next == NULL)
        {
            curr->prev->next = NULL;   // Remove link from previous node
            delete curr;               // Delete current node
        }
        // Sub-case: Deleting a middle node
        else
        {
            node *back = curr->prev;   // Node before the one to delete
            node *front = curr->next;  // Node after the one to delete

            back->next = front;        // Link previous node to next node
            front->prev = back;        // Link next node back to previous node
            delete curr;               // Delete current node

            // The following commented code is an optimal way to do this in one line:
            // curr->prev->next = curr->next;
            // curr->next->prev = curr->prev;
            // delete curr;
        }
    }

    // Traverse and print the list after deletion
    node *trav = head;
    cout << "Linked List after Deletion : ";
    while (trav)
    {
        cout << trav->data << " "; // Print value of each node
        trav = trav->next;         // Move to next node
    }
}

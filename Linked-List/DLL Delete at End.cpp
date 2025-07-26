#include <iostream>
using namespace std;

// Definition for a node in a doubly linked list
class node
{
public:
    int data;      // Value stored in the node
    node *next;    // Pointer to the next node in the list
    node *prev;    // Pointer to the previous node in the list

    // Constructor to initialize node with a value
    node(int val)
    {
        data = val;
        next = prev = NULL; // Set both next and prev to NULL initially
    }
};

int main()
{
    node *head = NULL; // Pointer to the head (first node) of the list
    node *tail = NULL; // Pointer to the tail (last node) of the list
    int n;

    // Ask user for the number of nodes to create in the doubly linked list
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
        // Otherwise, append the new node to the end and update pointers
        else
        {
            node *temp = new node(val);
            tail->next = temp;    // Set current tail's next to new node
            temp->prev = tail;    // Set new node's prev to current tail
            tail = temp;          // Move tail to the new node
        }
    }

    // --- Deletion at the end of the doubly linked list ---
    if (head != NULL)
    {
        // Case 1: Only one node in the list
        if (head->next == NULL)
        {
            delete head;          // Delete the single node
            head = NULL;          // Set head to NULL, list becomes empty
        }
        // Case 2: More than one node in the list
        else
        {
            node *temp = head;
            // Traverse to the last node
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            // Unlink the last node from the list
            temp->prev->next = NULL;
            delete temp;          // Delete the last node
        }
    }

    // Print the doubly linked list after deletion
    node *trav = head;
    cout << "The linked list is: ";
    while (trav != NULL)
    {
        cout << trav->data << " "; // Output the data of each node
        trav = trav->next;         // Move to the next node
    }
}

#include <iostream>
using namespace std;

// Definition of the node class for the doubly linked list
class node
{
public:
    int data;       // Data held by the node
    node *next;     // Pointer to the next node in the list
    node *prev;     // Pointer to the previous node in the list

    // Constructor to initialize node with a value
    node(int val)
    {
        data = val;         // Set the node's value
        next = prev = NULL; // Initialize pointers as null
    }
};

int main()
{
    node *head = NULL; // Pointer to the first node in the list
    node *tail = NULL; // Pointer to the last node in the list

    int n;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;

    cout << "Enter the values of the nodes: ";

    // Loop to create the doubly linked list with n nodes
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val; // Read the value for the new node

        // If the list is empty, create the first node
        if (head == NULL)
        {
            head = new node(val); // Allocate new node and make it head
            tail = head;          // Head and tail both point to first node
        }
        else
        {
            node *temp = new node(val); // Allocate new node
            tail->next = temp;          // Link new node after current tail
            temp->prev = tail;          // Link new node back to current tail
            tail = temp;                // Move tail to new node
        }
    }

    // Deletion at the end of the doubly linked list
    if (head != NULL)
    {
        // If there is only one node in the list
        if (head->next == NULL)
        {
            delete head; // Delete the only node
            head = NULL; // Set head to NULL (empty list)
        }
        else
        {
            // Traverse to the last node
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            // Disconnect the last node from the list
            temp->prev->next = NULL;
            delete temp; // Delete the last node
        }
    }

    // Print the linked list after deletion
    node *trav = head;
    cout << "The linked list is: ";
    while (trav != NULL)
    {
        cout << trav->data << " "; // Print value of current node
        trav = trav->next;         // Move to next node
    }
}

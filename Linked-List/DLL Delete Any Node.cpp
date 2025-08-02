#include <iostream>
using namespace std;

// Definition of a node in a doubly linked list
class node
{
public:
    int data;       // Value stored in the node
    node *next;     // Pointer to the next node
    node *prev;     // Pointer to the previous node

    // Constructor to initialize node with a value
    node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

int main()
{
    node *head = NULL;  // Pointer to the first node (head) of the list
    node *tail = NULL;  // Pointer to the last node (tail) of the list

    int n;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;

    cout << "Enter the values of the nodes: ";
    // Loop to create n nodes and build the doubly linked list
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (head == NULL) // If the list is empty, create the first node
        {
            head = new node(val);
            tail = head;
        }
        else // Otherwise, add new nodes to the end of the list
        {
            node *temp = new node(val);
            tail->next = temp;    // Link new node after the current tail
            temp->prev = tail;    // Set previous pointer of new node
            tail = temp;          // Update tail to new node
        }
    }

    int pos;
    cout << "Enter the position of the node you want to delete: ";
    cin >> pos;

    // Deleting the first node (head)
    if (pos == 1)
    {
        if (head->next == NULL) // If there's only one node
        {
            delete head;
            head = NULL;
        }
        // If there are more than one nodes
        else
        {
            node *temp = head;
            head = head->next;   // Move head to next node
            delete temp;         // Delete original head
            head->prev = NULL;   // Remove backward link from new head
        }
    }
    // Deleting a node other than the first one
    else
    {
        node *curr = head;   // Start from the head
        // Traverse to the node at 'pos'
        while (--pos)
        {
            curr = curr->next;
        }
        // If it's the last node
        if (curr->next == NULL)
        {
            curr->prev->next = NULL; // Remove link to this node from previous node
            delete curr;             // Delete current node
        }
        // If it's a middle node
        else
        {
            node *back = curr->prev;   // Node before current
            node *front = curr->next;  // Node after current

            back->next = front;        // Link previous node to next node
            front->prev = back;        // Link next node back to previous node
            delete curr;               // Delete current node

            /*  Optimal solution (does the same as above)
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            */
        }
    }

    // Traverse and print the linked list after deletion
    node *trav = head;

    cout << "Linked List after Deletion : ";
    while (trav)
    {
        cout << trav->data << " "; // Print current node's data
        trav = trav->next;         // Move to next node
    }
}

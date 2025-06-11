#include <iostream>
using namespace std;

// Definition of a node in a doubly linked list
class node
{
public:
    int data;      // Value stored in the node
    node *next;    // Pointer to the next node in the list
    node *prev;    // Pointer to the previous node in the list

    // Constructor to initialize a node with a value
    node(int val)
    {
        data = val;
        next = prev = NULL; // Initialize next and prev to NULL
    }
};

int main()
{
    node *head = NULL; // Pointer to the first node of the list
    node *tail = NULL; // Pointer to the last node of the list

    int n; // Number of nodes to be created
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;

    cout << "Enter the values of the nodes: ";
    // Construct the doubly linked list by inserting n nodes
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (head == NULL)
        {
            // If the list is empty, create the first node
            head = new node(val);
            tail = head;
        }
        else
        {
            // For subsequent nodes, create a new node and link it at the end
            node *temp = new node(val);
            tail->next = temp;  // Link the last node to the new node
            temp->prev = tail;  // Link new node's prev to the old tail
            tail = temp;        // Update tail to the new last node
        }
    }

    int pos; // Position of the node to delete (1-based index)
    cout << "Enter the position of the node you want to delete: ";
    cin >> pos;

    if (pos == 1)
    {
        // If the first node (head) is to be deleted
        if (head->next == NULL)
        {
            // Only one node in the list, delete and set head to NULL
            delete head;
            head = NULL;
        }
        else
        {
            // If more than one node, update head and delete the old head
            node *temp = head;
            head = head->next; // Move head to next node
            delete temp;       // Delete the old head
            head->prev = NULL; // New head's prev should be NULL
        }
    }
    else
    {
        // Deleting from other positions (not the head)
        node *curr = head;
        // Advance curr to the node to be deleted (pos-1 times)
        while (--pos)
        {
            curr = curr->next;
        }
        if (curr->next == NULL)
        {
            // If last node is to be deleted
            curr->prev->next = NULL; // Previous node's next should be NULL
            delete curr;
        }
        else
        {
            // If a middle node is to be deleted
            node *back = curr->prev;   // Node before current
            node *front = curr->next;  // Node after current

            back->next = front;        // Link previous node to next node
            front->prev = back;        // Link next node back to previous node
            delete curr;               // Delete the target node

            /*  Optimal solution (commented):
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            */
        }
    }

    // Traverse and print the updated list after deletion
    node *trav = head;
    cout << "Linked List after Deletion : ";
    while (trav)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}

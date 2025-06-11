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
    int n;             // Number of nodes to be created
    
    // Prompt the user for the number of nodes
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;

    // Prompt the user to enter the node values
    cout << "Enter the values of the nodes: ";

    // Construct the doubly linked list by inserting n nodes
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val; // Read the value for the new node
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

    // Deletion at the end (delete the last node)
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            // Only one node in the list, delete it and set head to NULL
            delete head;
            head = NULL;
        }
        else
        {
            // More than one node: find the last node
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next; // Move to the next node
            }
            // temp now points to the last node
            temp->prev->next = NULL; // Set previous node's next to NULL
            delete temp;             // Delete the last node
        }
    }

    // Traverse and print the updated list after deletion
    node *trav = head;
    cout << "The linked list is: ";
    while (trav != NULL)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}

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
        next = prev = NULL; // Initialize both next and prev to NULL
    }
};

int main()
{
    node *head = NULL; // Pointer to the first node (head) of the list
    node *tail = NULL; // Pointer to the last node (tail) of the list
    int n;             // Number of nodes to create

    // Prompt user for number of nodes
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;
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
            tail->next = temp;  // Link the old tail to the new node
            temp->prev = tail;  // Link new node's prev to the old tail
            tail = temp;        // Update tail to the new last node
        }
    }

    // Deletion at the beginning (removing the head node)
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            // If there is only one node, delete it and set head to NULL
            delete head;
            head = NULL;
        }
        else
        {
            // If there are more than one nodes
            node *temp = head;      // Store pointer to the current head
            head = head->next;      // Move head to the next node
            delete temp;            // Delete the old head
            head->prev = NULL;      // Set new head's prev to NULL
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

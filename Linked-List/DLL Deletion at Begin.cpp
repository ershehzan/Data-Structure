<<<<<<< HEAD
#include <iostream>
using namespace std;

// Definition of the node class for a doubly linked list
class node
{
public:
    int data;       // Stores node data
    node *next;     // Pointer to the next node
    node *prev;     // Pointer to the previous node
    node(int val)   // Constructor to initialize node with a value
    {
        data = val;
        next = prev = NULL;
    }
};

int main()
{
    node *head = NULL;   // Pointer to the head (first node) of the list
    node *tail = NULL;   // Pointer to the tail (last node) of the list
    int n;

    // Input: Number of nodes to create
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;

    // Input: Node values
    cout << "Enter the values of the nodes: ";

    // Creating the doubly linked list
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;  // Read node value
        if (head == NULL)
        {
            // First node creation
            head = new node(val);
            tail = head;
        }
        else
        {
            // Subsequent nodes
            node *temp = new node(val);
            tail->next = temp;  // Link the previous node to the new node
            temp->prev = tail;  // Link the new node to the previous node
            tail = temp;        // Update the tail to the new node
        }
    }

    // Deletion at the beginning of the doubly linked list
    if (head != NULL)
    {
        // If there is only one node
        if (head->next == NULL)
        {
            delete head;   // Delete the only node
            head = NULL;   // Update head to NULL
        }
        // If there are more than one nodes
        else
        {
            node *temp = head;  // Temporary pointer to the node to be deleted
            head = head->next;  // Move head to the next node
            delete temp;        // Delete previous head
            head->prev = NULL;  // Set new head's previous pointer to NULL
        }
    }

    // Traverse and display the linked list
    node *trav = head;
    cout << "The linked list is: ";
    while (trav != NULL)
    {
        cout << trav->data << " ";  // Print node data
        trav = trav->next;          // Move to next node
    }
}
=======
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

int main()
{

    node *head = NULL;
    node *tail = NULL;
    int n;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;
    cout << "Enter the values of the nodes: ";

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (head == NULL)
        {
            head = new node(val);
            tail = head;
        }
        else
        {
            node *temp = new node(val);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    //Deletion at the beginning
    if (head != NULL)
    {
        // if there is only one node
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        // if there are more than one nodes
        else
        {
            node *temp = head;
            head = head->next;
            delete temp;
            head->prev = NULL;
        }
    }


    node *trav = head;
    cout << "The linked list is: ";
    while (trav != NULL)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}
>>>>>>> 549b0d8 (file update)

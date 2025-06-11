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
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    node *head = NULL; // Pointer to the first node (head) of the list
    node *tail = NULL; // Pointer to the last node (tail) of the list
    int n;             // Number of nodes to create

    // Prompt user for number of nodes
    cout << "Enter the number of Nodes: ";
    cin >> n;
    cout << "Enter the values: ";

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

    int pos; // Position to insert a new node (0-based index)
    cout << "Enter the position to insert a new node: ";
    cin >> pos;

    int val; // Value to insert
    cout << "Enter the value to insert: ";
    cin >> val;

    node *temp = new node(val); // New node to be inserted
    node *curr = head;          // Pointer to traverse the list

    // Insert at the beginning (position 0)
    if (pos == 0)
    {
        if (head == NULL)
        {
            // Linked list is empty, simply set head to the new node
            head = new node(val);
        }
        else
        {
            // Linked list is not empty, insert at the start
            temp->next = head;   // Point new node to old head
            head->prev = temp;   // Old head's prev points to new node
            head = temp;         // Update head to new node
        }
    }
    else
    {
        // Traverse to the (pos-1)-th node (node after which we insert)
        while (--pos)
        {
            curr = curr->next;
        }

        // Insert at the end
        if (curr->next == NULL)
        {
            curr->next = temp; // Last node's next points to new node
            temp->prev = curr; // New node's prev points to last node
        }
        // Insert in the middle
        else
        {
            temp->next = curr->next;     // New node's next points to next node
            temp->prev = curr;           // New node's prev points to current node
            curr->next = temp;           // Current node's next points to new node
            temp->next->prev = temp;     // Next node's prev points to new node
        }
    }

    // Traverse and print the updated list after insertion
    node *trav = head;
    cout << "Doubly Linked List: ";
    while (trav != NULL)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
}

#include <iostream>
using namespace std;

// Definition of a node in the doubly linked list
class node
{
public:
    int data;      // Stores the value of the node
    node *next;    // Pointer to the next node in the list
    node *prev;    // Pointer to the previous node in the list

    // Constructor to initialize the node with a value
    node(int val)
    {
        data = val;
        next = prev = NULL; // Set both next and prev to NULL initially
    }
};

int main()
{
    node *head = NULL; // Pointer to the first node of the list
    node *tail = NULL; // Pointer to the last node of the list
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

    // --- Insertion at any position in the doubly linked list ---
    int pos, val;
    cout << "Enter the position where you want to insert: ";
    cin >> pos;
    cout << "Enter the value to insert: ";
    cin >> val;

    // Case 1: Insert at the beginning (head)
    if (pos == 1)
    {
        node *temp = new node(val); // Create new node with input value
        temp->next = head;          // Next of new node points to old head
        if (head != NULL)
            head->prev = temp;      // Set old head's prev to new node (if list not empty)
        head = temp;                // Update head to new node
        if (tail == NULL)           // If list was empty, update tail too
            tail = temp;
    }
    // Case 2: Insert at the end (tail)
    else if (pos == n + 1)
    {
        node *temp = new node(val); // Create new node
        if (tail != NULL)
        {
            tail->next = temp;      // Current tail's next points to new node
            temp->prev = tail;      // New node's prev points to current tail
            tail = temp;            // Update tail to new node
        }
        else
        {
            head = tail = temp;     // If list was empty, new node is both head and tail
        }
    }
    // Case 3: Insert at any middle position
    else
    {
        node *curr = head;
        // Traverse to the node after which new node will be inserted
        for (int i = 1; i < pos - 1 && curr != NULL; i++)
        {
            curr = curr->next;
        }
        // Insert only if the position is valid
        if (curr != NULL)
        {
            node *temp = new node(val);
            temp->next = curr->next; // New node's next points to next node
            if (curr->next != NULL)
                curr->next->prev = temp; // Next node's prev points to new node
            curr->next = temp;        // Current node's next points to new node
            temp->prev = curr;        // New node's prev points to current node
            // If inserted at the end, update tail
            if (temp->next == NULL)
                tail = temp;
        }
        else
        {
            cout << "Invalid position for insertion." << endl;
        }
    }

    // Print the doubly linked list after insertion
    node *trav = head;
    cout << "The linked list is: ";
    while (trav != NULL)
    {
        cout << trav->data << " "; // Output the data of each node
        trav = trav->next;         // Move to the next node
    }
}

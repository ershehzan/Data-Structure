#include <iostream>
using namespace std;

// Definition of a node for a singly linked list
class node
{
public:
    int data;       // Value stored in the node
    node *next;     // Pointer to the next node

    // Constructor to initialize a node with a value
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    node *head = NULL; // Pointer to the first node (head) of the list
    node *tail = NULL; // Pointer to the last node (tail) of the list

    int arr[100];      // Array to store input values
    int n;             // Number of nodes for the linked list

    // Step 1: Input the number of nodes and their values
    cout << "Enter the number of Nodes for linked list: ";
    cin >> n;
    cout << "Enter the elements of Nodes in linked list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Step 2: Construct the singly linked list from input values
    for (int i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            // If the list is empty, create the first node
            head = new node(arr[i]);
            tail = head;
        }
        else
        {
            // Otherwise, append new nodes to the end of the list
            tail->next = new node(arr[i]);
            tail = tail->next;
        }
    }

    // Step 3: Input the position (1-based) of the node to be deleted
    int x;
    cout << "Enter the value of the node to be deleted: ";
    cin >> x;

    if (x == 1)
    {
        // If the first node is to be deleted
        node *temp = head;
        head = head->next; // Move head to the next node
        delete temp;       // Delete the original head
    }
    else
    {
        // If a node other than the first is to be deleted
        x--; // Convert to 0-based index for traversal
        node *current = head;
        node *prev = NULL;

        // Traverse to the node to be deleted
        while (x--)
        {
            prev = current;
            current = current->next;
        }
        // Skip over the node to be deleted
        prev->next = current->next;
        delete current;
    }

    // Step 4: Print the updated linked list after deletion
    node *curr = head;
    cout << "Enter the value of the node to be deleted: ";
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

#include <iostream>
using namespace std;

// Definition of Node class representing an element of the linked list
class Node
{
public:
    int data;    // Stores the data value of the node
    Node *next;  // Pointer to the next node in the list

    // Constructor to initialize a node with a given value
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    Node *head, *tail;
    tail = head = NULL; // Initialize head and tail pointers to NULL

    // Array of values to populate the linked list
    int arr[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++)
    {
        // If the list is empty, create the first node
        if (head == NULL)
        {
            head = new Node(arr[i]); // Create and assign the first node
            tail = head;             // Set tail to point to the first node
        }
        else
        {
            // Add new node to the end of the list
            tail->next = new Node(arr[i]);
            tail = tail->next; // Move tail to the newly added node
        }
    }

    // Delete the first node (head) of the linked list if it exists
    if (head != NULL)
    {
        Node *temp = head;   // Store pointer to the first node
        head = head->next;   // Move head to the second node
        delete temp;         // Free memory of the original first node
    }

    cout << "Linked List After First Node Deletion: ";

    // Print the linked list after deletion
    Node *current = head; // Create a pointer to traverse the list

    while (current != NULL)
    {
        cout << current->data << " "; // Output the data of the current node
        current = current->next;      // Move to the next node
    }
    cout << endl;

    return 0;
}

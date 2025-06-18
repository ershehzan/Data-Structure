#include <iostream>
using namespace std;

// Definition of the node class for singly linked list
class node
{
public:
    int data;      // Data stored in the node
    node *next;    // Pointer to the next node

    // Constructor to initialize a node with a given value
    node(int value)
    {
        data = value;
        next = NULL; // By default, next is set to NULL
    }
};

int main()
{
    node *head;        // Pointer to the head (first node) of the linked list
    node *tail = NULL; // Pointer to the tail (last node) of the linked list
    head = NULL;       // Initially, the list is empty

    int arr[] = {10, 20, 30, 40, 50}; // Array of values to insert into the linked list

    // Creating a linked list from the array
    for (int i = 0; i < 5; i++)
    {
        if (head == NULL)
        {
            // For the first element, create a new node and set both head and tail to it
            head = new node(arr[i]);
            tail = head;
        }
        else
        {
            // For subsequent elements, create a new node at the end and update the tail
            tail->next = new node(arr[i]);
            tail = tail->next;
        }
    }

    // Deleting the last node of the linked list
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            // If there is only one node in the list, delete head and set it to NULL
            node *temp = head;
            delete temp;
            head = NULL;
        }
        else
        {
            // If there are multiple nodes, traverse to the second last node
            node *prev = NULL;
            node *temp = head;

            while (temp->next != NULL)
            {
                prev = temp;         // prev will point to the second last node
                temp = temp->next;   // temp will point to the last node
            }
            delete temp;             // Delete the last node
            prev->next = NULL;       // Set the next of second last node to NULL
        }
    }

    // Print the linked list after deleting the last node
    cout << "Linked List After Last Node Deletion: ";

    node *current = head; // Pointer to traverse the list

    while (current)
    {
        cout << current->data << " "; // Print data of each node
        current = current->next;      // Move to the next node
    }
}

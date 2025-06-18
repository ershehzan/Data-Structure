#include <iostream>
using namespace std;

// Definition of the Node class for the singly linked list
class Node
{
public:
    int data;      // Data stored in the node
    Node *next;    // Pointer to the next node in the list

    // Constructor to initialize a node with a value
    Node(int value)
    {
        data = value;
        next = NULL; // By default, next is set to NULL
    }
};

int main()
{
    Node *head, *tail; // Pointers to the head and tail of the list
    tail = head = NULL; // Initially, the list is empty

    int arr[] = {10, 20, 30, 40, 50}; // Array of values to insert into the list

    // Creating the linked list from the array
    for (int i = 0; i < 5; i++)
    {
        if (head == NULL)
        {
            // For the first element, create a new node and set both head and tail to it
            head = new Node(arr[i]);
            tail = head;
        }
        else
        {
            // For subsequent elements, create a new node at the end and update the tail
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }

    // Deleting the first node of the linked list
    if (head != NULL)
    {
        Node *temp = head;     // temp points to the node to be deleted (the first node)
        head = head->next;     // Move head to the next node
        delete temp;           // Delete the original first node
    }

    cout << "Linked List After First Node Deletion: ";

    // Print the linked list after deletion
    Node *current = head; // Pointer to traverse the list
    while (current != NULL)
    {
        cout << current->data << " "; // Print data of each node
        current = current->next;      // Move to the next node
    }
    cout << endl;
    return 0;
}

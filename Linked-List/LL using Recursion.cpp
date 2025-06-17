#include <iostream>
using namespace std;

// Definition for a singly-linked list node
class node
{
public:
    int data;      // Value stored in the node
    node *next;    // Pointer to the next node

    // Constructor to initialize the node with a value
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Recursive function to create a linked list from an array
node *insertAtend(int arr[], int index, int size)
{
    // Base case: if all elements are added, return NULL
    if (index == size)
        return NULL;

    // Create a new node with the current array value
    node *temp = new node(arr[index]);
    // Recursively link the next node
    temp->next = insertAtend(arr, index + 1, size);
    return temp;
}

int main()
{
    node *head;
    head = NULL;

    int arr[] = {20, 30, 40, 50}; // Array to be converted into linked list
    int size = 4;
    head = insertAtend(arr, 0, size); // Build list recursively

    node *current = head;

    cout << "Linked List: ";
    while (current != NULL)
    {
        cout << current->data << " ";  // Print each node's data
        current = current->next;       // Move to the next node
    }
}

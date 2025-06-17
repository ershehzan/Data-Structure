#include <iostream>
using namespace std;

// Definition for singly-linked list node
class node
{
public:
    int data;      // Value stored in the node
    node *next;    // Pointer to the next node

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Recursively create a linked list from an array
node *insertAtend(int arr[], int index, int size)
{
    if (index == size)
        return NULL;

    node *temp = new node(arr[index]);
    temp->next = insertAtend(arr, index + 1, size);
    return temp;
}

int main()
{
    node *head;
    head = NULL;

    int arr[] = {10, 20, 40, 50}; // Initial values
    int size = 4;
    head = insertAtend(arr, 0, size); // Build list recursively

    int x = 2;        // Position to insert new node after (1-based index)
    node *temp = head;
    int value = 30;   // Value to insert
    x--;              // Adjust for 0-based traversal

    while (x--)
    {
        temp = temp->next; // Move to the node after which to insert
    }

    node *temp2 = new node(value); // Create new node
    temp2->next = temp->next;      // Link new node to next node
    temp->next = temp2;            // Insert new node after temp

    node *current = head;
    cout << "Linked List: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

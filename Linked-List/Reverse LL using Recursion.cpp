#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list node
class node
{
public:
    int data;      // Value stored in the node
    node *next;    // Pointer to the next node

    // Constructor to initialize node with a value
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Recursive function to reverse the linked list
// curr: current node being processed
// prev: previous node (to which current node's 'next' will point)
node* reverse(node* curr, node* prev)
{
    // Base case: if current node is NULL, prev is the new head
    if (curr == NULL)
        return prev;

    node* fut = curr->next; // Save the next node
    curr->next = prev;      // Reverse the pointer

    // Recursive call with the next node and current as new prev
    return reverse(fut, curr);
}

int main()
{
    node *head, *tail;
    tail = head = NULL; // Initialize both head and tail to NULL

    // Vector containing the initial values for the linked list
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();

    // Construct the linked list from the vector
    for (int i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            head = new node(arr[i]); // First node becomes head
            tail = head;
        }
        else
        {
            tail->next = new node(arr[i]); // Append new node at the end
            tail = tail->next;
        }
    }

    // Call the recursive reverse function
    // After this, head will point to the new head of the reversed list
    head = reverse(head, NULL);

    // Print the reversed linked list
    node *current = head;
    cout << "Reversed Linked List: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    return 0;
}

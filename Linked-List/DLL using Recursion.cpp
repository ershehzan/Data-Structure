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
        next = prev = NULL; // Initialize both next and prev to NULL
    }
};

// Recursive function to build a doubly linked list from an array
node *DLL(int arr[], int index, int size, node *back)
{
    // Base case: If index reaches the size, return NULL (end of list)
    if (index == size)
        return NULL;

    // Create a new node with the current array value
    node *temp = new node(arr[index]);
    temp->prev = back; // Set the previous pointer to the last node (back)

    // Recursively build the rest of the list and set temp's next pointer
    temp->next = DLL(arr, index + 1, size, temp);

    // Return the current node to be linked by the previous recursive call
    return temp;
}

int main()
{
    node *head = NULL; // Pointer to the first node (head) of the list
    int n;             // Number of nodes

    // Prompt user for number of nodes
    cout << "Enter the number of Nodes: ";
    cin >> n;

    int arr[100];      // Array to store node values (max 100 elements)
    cout << "Enter the values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read values from the user
    }

    // Build the doubly linked list using recursion starting from index 0
    head = DLL(arr, 0, n, head);

    // Traverse and print the doubly linked list
    node *curr = head;
    cout << "Doubly Linked List using Recursion: ";
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

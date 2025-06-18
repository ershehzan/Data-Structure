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
        next = NULL;
    }

    // Recursive function to insert elements at the beginning of the linked list
    // arr: array of values to insert
    // index: current index in the array
    // size: size of the array
    // prev: pointer to the already constructed portion of the list (initially NULL)
    node *insertAtbegin(int arr[], int index, int size, node *prev)
    {
        if (index == size)
            return prev; // Base case: end of array, return the head of the list

        node *temp = new node(arr[index]); // Create a new node with arr[index]
        temp->next = prev;                 // Insert at the beginning by pointing next to previous head
        // Recursive call with next index and updated head
        return insertAtbegin(arr, index + 1, size, temp);
    }
};

int main()
{
    node *head;
    head = NULL;
    int arr[] = {20, 30, 40, 50}; // Array of values to add at the beginning

    // Recursively insert elements at the beginning of the list
    head = head->insertAtbegin(arr, 0, 4, head);

    node *temp;
    temp = head;
    cout << "Linked List: ";
    // Print the linked list
    while (temp)
    {
        cout << temp->data << " "; // Print data of each node
        temp = temp->next;         // Move to the next node
    }
}

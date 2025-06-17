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

int main()
{
    node *head, *tail;
    tail = head = NULL; // Initialize both head and tail as NULL

    // Array containing the initial values for the linked list
    int arr[] = {20, 30, 40, 50};

    // Construct the linked list from the array
    for (int i = 0; i < 4; i++)
    {
        if (head == NULL)
        {
            head = new node(arr[i]); // First node becomes the head
            tail = head;
        }
        else
        {
            tail->next = new node(arr[i]); // Append new node at the end
            tail = tail->next;
        }
    }

    // Reverse the linked list values using an auxiliary vector (LC-206 style)
    vector<int> ans;          // Vector to store node values
    node* temp = head;        // Temporary pointer to traverse the list

    // Copy all node values to the vector
    while (temp != NULL)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }

    // Write the values back to the linked list in reverse order
    int i = ans.size() - 1;
    temp = head;
    while (temp)
    {
        temp->data = ans[i];  // Assign the value from the end of the vector
        i--;
        temp = temp->next;
    }

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

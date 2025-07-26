#include <iostream>
using namespace std;

// Definition for a node in a circular linked list
class node
{
public:
    int data;      // Stores the value of the node
    node *next;    // Pointer to the next node in the list

    // Constructor to initialize the node with a value
    node(int val)
    {
        data = val;
        next = NULL; // Initially, the next pointer is set to NULL
    }
};

int main() {
    node *head = NULL; // Pointer to the head (first node) of the list
    node *tail = NULL; // Pointer to the tail (last node) of the list
    int n;             // Number of nodes to be created

    // Prompt the user for the number of nodes in the circular linked list
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Prompt the user to enter the values for each node
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        // If the list is empty, create the first node and assign head and tail to it
        if (head == NULL) {
            head = new node(val);
            tail = head;
        }
        // For subsequent nodes, create a new node and link it to the tail
        else {
            node *temp = new node(val);
            tail->next = temp; // Link the current tail to the new node
            tail = temp;       // Update the tail pointer to the new node
        }
    }

    // Make the list circular by connecting the last node (tail) to the first node (head)
    tail->next = head;

    // Print the circular linked list
    cout << "The circular linked list is: ";
    node *curr = head;
    while (curr) {
        cout << curr->data << " "; // Output the data of the current node
        curr = curr->next;         // Move to the next node

        // Stop printing if we've come full circle back to the head
        if (curr == head) {
            break;
        }
    }
}

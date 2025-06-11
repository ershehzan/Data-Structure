#include <iostream>
using namespace std;

// Definition of a node in the circular linked list
class node
{
public:
    int data;      // Value stored in the node
    node *next;    // Pointer to the next node in the list

    // Constructor to initialize a node with a value
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

int main() {
    node *head = NULL; // Pointer to the first node (head) of the list
    node *tail = NULL; // Pointer to the last node (tail) of the list
    int n;             // Number of nodes to be inserted

    // Prompt the user to enter the number of nodes
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Prompt the user to enter the values of the nodes
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val; // Read the value for the new node

        // If the list is empty, create the first node
        if (head == NULL) {
            head = new node(val); // The new node is both head and tail
            tail = head;
        }
        else {
            // For subsequent nodes, create a new node and link it at the end
            node *temp = new node(val); // Create a new node with the given value
            tail->next = temp;          // Link the current tail to the new node
            tail = temp;                // Move the tail pointer to the new node
        }
    }

    // Make the linked list circular by connecting the last node to the head
    tail->next = head;

    // Print the circular linked list
    cout << "The circular linked list is: ";
    node *curr = head;

    // Traverse the list and print each node's data until we return to the head
    while (curr) {
        cout << curr->data << " "; // Print current node's data
        curr = curr->next;         // Move to the next node

        // If we've come back to the head, the traversal is complete (prevents infinite loop)
        if (curr == head) {
            break;
        }
    }
}

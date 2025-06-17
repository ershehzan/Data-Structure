// Program to search for a value in a singly linked list

#include <iostream>
using namespace std;

// Definition of a node in the linked list
struct Node
{
    int data;      // Stores the integer value for the node
    Node *next;    // Pointer to the next node in the list
};

int main()
{
    // Creating three nodes for the linked list
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();

    // Initializing data and linking the nodes together
    first->data = 10;         // Assign value 10 to the first node
    first->next = second;     // Link first node to second

    second->data = 20;        // Assign value 20 to the second node
    second->next = third;     // Link second node to third

    third->data = 30;         // Assign value 30 to the third node
    third->next = nullptr;    // Third node is the last node, so set next to nullptr

    int target;               // Variable to store the number to search for
    cout << "Enter the number to search :";
    cin >> target;            // Read the target value from the user

    Node *current = first;    // Start the search from the first node
    bool found = false;       // Flag to indicate if the value is found

    // Traverse the linked list to search for the target value
    while (current != nullptr)
    {
        if (current->data == target) // If current node's data matches the target
        {
            found = true;            // Set found flag to true
            break;                   // Exit the loop as value is found
        }
        current = current->next;     // Move to the next node in the list
    }

    // Output the result of the search
    if (found)
    {
        cout << "Number " << target << " is found in the linked list :" << endl;
    }
    else
    {
        cout << "Number " << target << " is not found in the linked list :" << endl;
    }
    return 0; // End of program
}

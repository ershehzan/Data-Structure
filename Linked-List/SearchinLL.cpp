// Search in LL
#include <iostream>
using namespace std;

<<<<<<< HEAD
// Definition of a node in the singly linked list
struct Node
{ 
    int data;      // The integer value stored in the node
    Node *next;    // Pointer to the next node in the list
};

int main()
{
    // Creating three nodes for the linked list
=======
struct Node
{ // holds the integer value
    int data;
    Node *next; // points to the next node
};
int main()
{

>>>>>>> 549b0d8 (file update)
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();

<<<<<<< HEAD
    // Assigning values and linking the nodes together
    first->data = 10;         // First node holds value 10
    first->next = second;     // First node points to second node

    second->data = 20;        // Second node holds value 20
    second->next = third;     // Second node points to third node

    third->data = 30;         // Third node holds value 30
    third->next = nullptr;    // Third node is the last node, points to NULL

    int target;
    cout << "Enter the number to search :";
    cin >> target;            // Input the number to search for

    Node *current = first;    // Start from the first node
    bool found = false;       // Flag to indicate if value is found

    // Traverse the linked list to search for the target value
    while (current != nullptr)
    {
        if (current->data == target) // Check if current node has the target value
        {
            found = true;
            break;                   // Exit loop if found
        }
        current = current->next;     // Move to the next node
    }

    // Output search result
=======
    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = nullptr;

    int target;
    cout << "Enter the number to search :";
    cin >> target;

    Node *current = first;
    bool found = false;
    while (current != nullptr)
    {
        if (current->data == target)
        {
            found = true;
            break;
        }
        current = current->next;
    }
>>>>>>> 549b0d8 (file update)
    if (found)
    {
        cout << "Number " << target << " is found in the linked list :" << endl;
    }
    else
    {
        cout << "Number " << target << " is not found in the linked list :" << endl;
    }
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> 549b0d8 (file update)

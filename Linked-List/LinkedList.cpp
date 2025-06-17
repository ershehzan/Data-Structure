// Linked list
#include <iostream>
using namespace std;

// Definition of a singly-linked list node
struct Node
{ 
    int data;      // Holds the integer value
    Node *next;    // Points to the next node
};

int main()
{
    // Create three nodes for the linked list
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();

    // Set up data and next pointers for each node
    first->data = 10;
    first->next = second;    // First node points to second

    second->data = 20;
    second->next = third;    // Second node points to third

    third->data = 30;
    third->next = nullptr;   // Third node is the last, points to nullptr

    // Traverse and print the linked list
    Node *current = first;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;   // Move to the next node
    }

    return 0;
}

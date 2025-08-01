#include <iostream>
using namespace std;

// Definition of a Node in the linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to next node

    // Constructor to initialize a node with given value
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Solution {
public:
    // Function to remove duplicates from a sorted linked list
    Node* removeDuplicates(Node* head) {
        if (!head) return head;  // If list is empty, return nullptr

        Node* prev = head;       // 'prev' points to last node having unique value
        Node* curr = head->next; // 'curr' traverses through list
        
        while (curr) {
            if (curr->data == prev->data) {
                // Duplicate detected: skip 'curr' node and delete it
                prev->next = curr->next;  // Link prev to the next of current (removes curr)
                delete curr;              // Free the memory of duplicate node
                curr = prev->next;       // Move curr forward
            } else {
                // No duplicate, move pointers ahead normally
                prev = prev->next;       // prev moves to curr
                curr = curr->next;       // curr moves to next node
            }
        }
        return head;                  // Return head of modified list
    }
};

// Utility function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";  // Print current node's data
        head = head->next;          // Move to next node
    }
    cout << endl;
}

// Utility function to create a linked list of n nodes
Node* createList(int n) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;                 // Read node value from input
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;           // First node becomes head
            tail = head;              // Tail is same as head initially
        } else {
            tail->next = newNode;     // Attach new node at the end
            tail = tail->next;        // Move tail pointer to new node
        }
    }
    return head;                      // Return head pointer to the linked list
}

int main() {
    Solution solution;
    int n;
    cout << "Enter number of nodes in sorted linked list: ";
    cin >> n;

    cout << "Enter elements of sorted linked list: ";
    Node* head = createList(n);        // Create a linked list from user input

    head = solution.removeDuplicates(head);  // Remove duplicates from the list

    cout << "List after removing duplicates: ";
    printList(head);                   // Print the resulting list

    return 0;
}

#include <iostream>
using namespace std;

// Definition for singly-linked list node
class Node {
public:
    int data;        // Value stored in the node
    Node* next;      // Pointer to the next node

    // Constructor to initialize node with a value
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Solution class containing the method to remove duplicates
class Solution {
public:
    // Function to remove duplicates from a sorted linked list
    Node* removeDuplicates(Node* head) {
        if (!head) return head; // If list is empty, return as is

        Node* prev = head;         // Pointer to track last unique node
        Node* curr = head->next;   // Pointer to traverse the list

        // Traverse the list
        while (curr) {
            if (curr->data == prev->data) {
                // Duplicate found. Remove current node.
                prev->next = curr->next;
                delete curr;            // Free memory of removed node
                curr = prev->next;      // Move to next node
            } else {
                // No duplicate, move both pointers forward
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head; // Return head of modified list
    }
};

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create linked list from user input
Node* createList(int n) {
    Node* head = NULL, *tail = NULL;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;                  // Read node value from input
        Node* newNode = new Node(value); // Create new node
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;      // Append new node at the end
            tail = tail->next;
        }
    }
    return head;
}

int main() {
    Solution solution;
    int n;
    cout << "Enter number of nodes in sorted linked list: ";
    cin >> n;
    cout << "Enter elements of sorted linked list: ";
    Node* head = createList(n);

    // Remove duplicates from the linked list
    head = solution.removeDuplicates(head);

    // Print the list after removing duplicates
    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}

#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;        // Data stored in the node
    Node* next;      // Pointer to the next node

    // Constructor to initialize node with a value
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Solution class contains method to remove loop from linked list
class Solution {
  public:
    // Function to detect and remove a loop in the linked list (if present)
    void removeLoop(Node* head) {
        Node* s = head; // Slow pointer
        Node* f = head; // Fast pointer

        // Step 1: Detect loop using Floyd’s Tortoise and Hare algorithm
        while (f != NULL && f->next != NULL) {
            s = s->next;            // Move slow pointer by one
            f = f->next->next;      // Move fast pointer by two

            if (s == f) {           // Loop detected
                break;
            }
        }

        // If no loop found, return
        if (f == NULL || f->next == NULL)
            return;

        // Step 2: Find the starting node of the loop
        s = head;
        while (s != f) {
            s = s->next;
            f = f->next;
        }

        // Step 3: Find the node just before the starting node of the loop
        while (s->next != f) {
            s = s->next;
        }

        // Step 4: Break the loop
        s->next = NULL;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Utility function to create a loop in the linked list for testing
void createLoop(Node* head, int pos) {
    if (pos == 0) return;         // No loop if position is 0

    Node* loopNode = head;
    // Move to the node at position `pos`
    for (int i = 1; i < pos; ++i) {
        loopNode = loopNode->next;
    }

    // Move to the last node
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    // Create loop by pointing last node's next to loopNode
    tail->next = loopNode;
}

int main() {
    int n, pos;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";

    Node* head = NULL;
    Node* tail = NULL;

    // Build linked list from user input
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!head) {          // If list is empty, initialize head and tail
            head = newNode;
            tail = head;
        } else {              // Otherwise, add new node at the end
            tail->next = newNode;
            tail = tail->next;
        }
    }

    cout << "Enter position to create loop (0 for no loop): ";
    cin >> pos;
    createLoop(head, pos);    // Optionally create a loop for testing

    Solution solution;
    solution.removeLoop(head);    // Remove loop if present

    cout << "Linked list after removing loop: ";
    printList(head);              // Print the list to confirm loop removal

    return 0;
}

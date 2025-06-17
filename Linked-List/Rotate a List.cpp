#include <iostream>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:
    int val;            // Value stored in the node
    ListNode* next;     // Pointer to the next node

    // Constructor to initialize the node with a value
    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

// Solution class containing the rotateRight function
class Solution {
public:
    // Rotates the linked list to the right by k places
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge cases: empty list, single node, or zero rotations
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // Count the length of the linked list
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Adjust k if it's more than the list length
        k = k % count;
        if (k == 0) return head; // No rotation needed

        // Find the node just before the new head after rotation
        count -= k;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        // Rotate the list
        prev->next = NULL;      // Break the list at the new end
        ListNode* tail = curr;
        while (tail->next) {    // Find the last node in the rotated part
            tail = tail->next;
        }
        tail->next = head;      // Link last node to the old head
        head = curr;            // Update head to the new head

        return head;
    }
};

int main() {
    Solution solution;

    // Input number of nodes
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = NULL; // Head of the linked list
    ListNode* tail = NULL; // Tail pointer for easier insertion

    // Input node values and construct the linked list
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (head == NULL) {
            head = new ListNode(value); // First node becomes head
            tail = head;
        } else {
            tail->next = new ListNode(value); // Append new node at the end
            tail = tail->next;
        }
    }

    // Input the number of rotations
    int k;
    cout << "Enter the number of rotations: ";
    cin >> k;

    // Rotate the linked list
    head = solution.rotateRight(head, k);

    // Print the rotated linked list
    cout << "Rotated linked list: ";
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}

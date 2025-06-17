#include <iostream>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:
    int val;           // Value stored in the node
    ListNode* next;    // Pointer to the next node

    // Constructor to initialize the node with a value
    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

// Solution class containing method to find the middle node
class Solution {
public:
    // Function to find the middle node of a linked list
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head; // Both pointers start at head

        // Move fast by 2 steps and slow by 1 step
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // Move slow pointer one step
            fast = fast->next->next;     // Move fast pointer two steps
        }
        // When fast reaches the end, slow is at the middle
        return slow;
    }
};

int main() {
    Solution solution;

    // Input number of nodes in the linked list
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = NULL; // Head pointer
    ListNode* tail = NULL; // Tail pointer for easy insertion

    // Input node values and build the linked list
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (head == NULL) {
            head = new ListNode(value); // First node is the head
            tail = head;
        } else {
            tail->next = new ListNode(value); // Append new node at the end
            tail = tail->next;
        }
    }

    // Find the middle node of the linked list
    ListNode* middle = solution.middleNode(head);
    if (middle != NULL) {
        cout << "The middle node value is: " << middle->val << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }

    return 0;
}

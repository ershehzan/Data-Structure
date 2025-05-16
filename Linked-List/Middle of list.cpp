#include <iostream>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:
    int val;            // Value stored in the node
    ListNode* next;     // Pointer to the next node

    // Constructor to initialize the node with a given value
    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

class Solution {
public:
    // Function to find the middle node of a singly linked list
    ListNode* middleNode(ListNode* head) {
        // Use two pointers: 'slow' advances one step, 'fast' advances two steps
        ListNode* slow = head, *fast = head;

        // Traverse the list. When 'fast' reaches the end, 'slow' will be in the middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // Move slow by one node
            fast = fast->next->next;     // Move fast by two nodes
        }
        // 'slow' now points to the middle node
        return slow;
    }
};

int main() {
    Solution solution;

    // Create a linked list based on user input
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = NULL;   // Pointer to the head of the list
    ListNode* tail = NULL;   // Pointer to the tail for appending new nodes

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (head == NULL) {
            // If the list is empty, initialize both head and tail
            head = new ListNode(value);
            tail = head;
        } else {
            // Add new node to the end of the list and update tail
            tail->next = new ListNode(value);
            tail = tail->next;
        }
    }

    // Find the middle node using the Solution class
    ListNode* middle = solution.middleNode(head);
    if (middle != NULL) {
        cout << "The middle node value is: " << middle->val << endl;
    } else {
        cout << "The linked list is empty." << endl;
    }

    return 0;
}

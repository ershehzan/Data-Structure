<<<<<<< HEAD
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
    // Function to rotate the linked list to the right by k places
    ListNode* rotateRight(ListNode* head, int k) {
        // Edge cases: empty list, single node, or zero rotations
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // Count the length of the list
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Perform modulo to avoid unnecessary full rotations
        k = k % count;
        if (k == 0) return head; // No rotation needed

        // Find the node where the rotation should occur
        count -= k;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        // prev now points to the node before the new head
        // curr points to the new head after rotation

        // Break the list at the rotation point
        prev->next = NULL;
        ListNode* tail = curr;
        
        // Find the end of the rotated part and connect it to the old head
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head; // Connect the old tail to the old head
        head = curr;       // Update the head to the new head

        return head;
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

    // Input the number of rotations
    int k;
    cout << "Enter the number of rotations: ";
    cin >> k;

    // Rotate the linked list using the Solution class
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
=======
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }

        // Count the length of the list
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Modulo operation to avoid unnecessary rotations
        k = k % count;
        if (k == 0) return head;

        count -= k;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (count--) {
            prev = curr;
            curr = curr->next;
        }

        // Rotate
        prev->next = NULL;
        ListNode* tail = curr;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;
        head = curr;

        return head;
    }
};

int main() {
    Solution solution;

    // Create a linked list
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if (head == NULL) {
            head = new ListNode(value);
            tail = head;
        } else {
            tail->next = new ListNode(value);
            tail = tail->next;
        }
    }

    // Input the number of rotations
    int k;
    cout << "Enter the number of rotations: ";
    cin >> k;

    // Rotate the linked list
    head = solution.rotateRight(head, k);

    // Print the updated linked list
    cout << "Rotated linked list: ";
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
>>>>>>> 549b0d8 (file update)

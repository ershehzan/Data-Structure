#include <iostream>
using namespace std;

// Node definition: represents a node in a singly-linked list
class Node
{
public:
    int data;      // Data stored in the node (a single digit)
    Node *next;    // Pointer to the next node in the list

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Solution class for adding two numbers represented as linked lists
class Solution
{
public:
    // Helper function to recursively reverse a linked list
    Node *reverse(Node *curr, Node *prev)
    {
        // Base case: If current node is null, prev is the new head
        if (curr == NULL)
            return prev;
        
        Node *front = curr->next; // Store next node
        curr->next = prev;        // Reverse the link
        // Recurse for the next node, passing the current node as prev
        return reverse(front, curr);
    }

    // Function to add two numbers represented by linked lists
    Node *addTwoLists(Node *first, Node *sec)
    {
        // Reverse both input lists to make addition easier (units digit first)
        first = reverse(first, NULL);
        sec = reverse(sec, NULL);

        Node *curr1 = first; // Pointer to current node in first list
        Node *curr2 = sec;   // Pointer to current node in second list
        Node *head = NULL;   // Head of the resultant list
        Node *tail = NULL;   // Tail pointer to add nodes at the end

        int carry = 0; // Variable to store carry-over during addition

        // Process both lists as long as there are nodes left in both
        while (curr1 && curr2)
        {
            int sum = curr1->data + curr2->data + carry; // Digit-wise addition plus carry
            carry = sum / 10;                            // Update carry

            // Create a new node for the units digit of the sum
            Node *newNode = new Node(sum % 10);

            // If this is the first node, initialize head and tail
            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode; // Append node to the result list
                tail = tail->next;    // Move tail pointer forward
            }

            // Move to next nodes in both lists
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        // If first list still has nodes left (list lengths are unequal)
        while (curr1)
        {
            int sum = curr1->data + carry;
            carry = sum / 10;
            tail->next = new Node(sum % 10); // Append new node
            tail = tail->next;
            curr1 = curr1->next;
        }

        // If second list still has nodes remaining
        while (curr2)
        {
            int sum = curr2->data + carry;
            carry = sum / 10;
            tail->next = new Node(sum % 10); // Append new node
            tail = tail->next;
            curr2 = curr2->next;
        }

        // If there is any carry left after processing both lists
        while (carry)
        {
            tail->next = new Node(carry % 10);
            tail = tail->next;
            carry /= 10;
        }

        // Result is currently reversed; reverse it again to get correct order
        return reverse(head, NULL);
    }
};

// Helper function to create a linked list from an array of digits
Node *createList(int arr[], int n)
{
    if (n == 0)
        return NULL;
    Node *head = new Node(arr[0]); // First node
    Node *tail = head;
    for (int i = 1; i < n; ++i)
    {
        tail->next = new Node(arr[i]); // Create next node and link
        tail = tail->next;             // Move tail
    }
    return head;
}

// Helper function to print a linked list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example: 1st list: 2 -> 4 -> 3 (represents number 243)
    //          2nd list: 5 -> 6 -> 4 (represents number 564)
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create two linked lists from arrays
    Node *first = createList(arr1, n1);
    Node *second = createList(arr2, n2);

    Solution sol;
    // Add the two linked lists
    Node *result = sol.addTwoLists(first, second);

    cout << "Resultant List: ";
    printList(result);

    // Free allocated memory for the result list
    while (result)
    {
        Node *temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}

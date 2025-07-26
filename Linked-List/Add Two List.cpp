#include <iostream>
using namespace std;

// Node definition for singly linked list
class Node
{
public:
    int data;      // Value stored in the node
    Node *next;    // Pointer to the next node

    // Constructor to initialize node with a value
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Class containing methods to manipulate linked lists
class Solution
{
public:
    // Function to reverse a linked list recursively
    // 'curr' is the current node, 'prev' is the previous node
    Node *reverse(Node *curr, Node *prev)
    {
        // Base case: if current node is NULL, return previous node as new head
        if (curr == NULL)
            return prev;
        Node *front = curr->next; // Store next node
        curr->next = prev;        // Reverse the link
        // Recursively call for the next node
        return reverse(front, curr);
    }

    // Function to add two numbers represented by linked lists
    // Each node contains a single digit, lists are in forward order
    Node *addTwoLists(Node *first, Node *sec)
    {
        // Step 1: Reverse both input lists to make addition easier (from least significant digit)
        first = reverse(first, NULL);
        sec = reverse(sec, NULL);

        Node *curr1 = first; // Pointer for first list
        Node *curr2 = sec;   // Pointer for second list
        Node *head = NULL;   // Head of the result list
        Node *tail = NULL;   // Tail of the result list

        int carry = 0;       // Initialize carry for addition

        // Step 2: Add corresponding digits of both lists while both are not NULL
        while (curr1 && curr2)
        {
            int sum = curr1->data + curr2->data + carry; // Add digits and carry
            carry = sum / 10;                            // Update carry
            Node *newNode = new Node(sum % 10);          // Create new node with single digit result

            // If result list is empty, initialize head and tail
            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode; // Append new node to the result list
                tail = tail->next;    // Move tail forward
            }

            curr1 = curr1->next; // Move to next node in first list
            curr2 = curr2->next; // Move to next node in second list
        }

        // Step 3: If first list has remaining digits, continue adding
        while (curr1)
        {
            int sum = curr1->data + carry;
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr1 = curr1->next;
        }

        // Step 4: If second list has remaining digits, continue adding
        while (curr2)
        {
            int sum = curr2->data + carry;
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr2 = curr2->next;
        }

        // Step 5: If there is any remaining carry, add new node(s)
        while (carry)
        {
            tail->next = new Node(carry % 10);
            tail = tail->next;
            carry /= 10;
        }

        // Step 6: Reverse the result list to restore original order
        return reverse(head, NULL);
    }
};

// Helper function to create a linked list from an array
Node *createList(int arr[], int n)
{
    if (n == 0)
        return NULL;
    Node *head = new Node(arr[0]);
    Node *tail = head;
    // Add each element of array as node to the list
    for (int i = 1; i < n; ++i)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
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
    // Example input:
    // 1st list: 2 -> 4 -> 3 (represents number 243)
    // 2nd list: 5 -> 6 -> 4 (represents number 564)
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create linked lists from arrays
    Node *first = createList(arr1, n1);
    Node *second = createList(arr2, n2);

    Solution sol;
    // Add two numbers represented by linked lists
    Node *result = sol.addTwoLists(first, second);

    // Print the resulting list
    cout << "Resultant List: ";
    printList(result);

    // Free memory allocated for the result list
    while (result)
    {
        Node *temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}

#include <iostream>
using namespace std;

// Node definition for singly linked list
class Node
{
public:
    int data;      // Value stored in the node
    Node *next;    // Pointer to the next node in the list

    // Constructor to initialize node with a value
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Solution class containing methods to add two linked lists
class Solution
{
public:
    // Helper function to reverse a linked list recursively
    // curr: current node pointer, prev: previous node pointer
    Node *reverse(Node *curr, Node *prev)
    {
        if (curr == NULL)
            return prev; // Base case: return new head after full reversal
        Node *front = curr->next; // Store next node
        curr->next = prev;        // Reverse the pointer
        return reverse(front, curr); // Recurse for next node
    }

    // Function to add two numbers represented by linked lists
    // Each node contains a single digit; numbers are stored in forward order
    Node *addTwoLists(Node *first, Node *sec)
    {
        // Step 1: Reverse both input lists to facilitate addition from least significant digit
        first = reverse(first, NULL);
        sec = reverse(sec, NULL);

        Node *curr1 = first; // Pointer to traverse first list
        Node *curr2 = sec;   // Pointer to traverse second list
        Node *head = NULL;   // Head of the result list
        Node *tail = NULL;   // Tail of the result list (for efficient appends)
        int carry = 0;       // Initialize carry for addition

        // Step 2: Add corresponding digits while both lists have nodes
        while (curr1 && curr2)
        {
            int sum = curr1->data + curr2->data + carry; // Sum current digits and carry
            carry = sum / 10;                            // Update carry
            Node *newNode = new Node(sum % 10);          // Create new node with single digit

            // Append newNode to result list
            if (head == NULL)
            {
                head = tail = newNode; // First node becomes head and tail
            }
            else
            {
                tail->next = newNode;  // Link new node to list
                tail = tail->next;     // Move tail pointer
            }
            curr1 = curr1->next; // Move to next nodes
            curr2 = curr2->next;
        }

        // Step 3: Process remaining nodes in first list, if any
        while (curr1)
        {
            int sum = curr1->data + carry;
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr1 = curr1->next;
        }

        // Step 4: Process remaining nodes in second list, if any
        while (curr2)
        {
            int sum = curr2->data + carry;
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
            curr2 = curr2->next;
        }

        // Step 5: If a carry remains after processing both lists, add a new node for it
        while (carry)
        {
            tail->next = new Node(carry % 10);
            tail = tail->next;
            carry /= 10;
        }

        // Step 6: The result is currently reversed; reverse it back to the original order
        return reverse(head, NULL);
    }
};

// Helper function to create a linked list from an array
Node *createList(int arr[], int n)
{
    if (n == 0)
        return NULL; // Empty list
    Node *head = new Node(arr[0]);
    Node *tail = head;
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
            cout << " -> "; // Print arrow between nodes
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example input: 1st list: 2 -> 4 -> 3 (represents number 243)
    //               2nd list: 5 -> 6 -> 4 (represents number 564)
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create linked lists from input arrays
    Node *first = createList(arr1, n1);
    Node *second = createList(arr2, n2);

    Solution sol;
    // Add the two lists
    Node *result = sol.addTwoLists(first, second);

    // Print the resulting list; should represent 243 + 564 = 807 (7 -> 0 -> 8)
    cout << "Resultant List: ";
    printList(result);

    // Free memory allocated for result list (good practice)
    while (result)
    {
        Node *temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}

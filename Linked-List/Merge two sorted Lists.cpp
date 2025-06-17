#include <iostream>
using namespace std;

// Definition for singly-linked list node
class Node
{
public:
    int data;        // Value stored in the node
    Node *next;      // Pointer to the next node

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Solution class containing merge logic
class Solution
{
public:
    // Function to merge two sorted linked lists
    Node *sortedMerge(Node *head1, Node *head2)
    {
        Node *head = new Node(0); // Dummy node to simplify logic
        Node *tail = head;        // Tail pointer for merged list

        // Merge nodes by comparing values
        while (head1 && head2)
        {
            if (head1->data <= head2->data)
            {
                tail->next = head1;     // Attach head1 node
                head1 = head1->next;    // Move head1 forward
                tail = tail->next;      // Move tail forward
                tail->next = NULL;      // Detach from old links
            }
            else
            {
                tail->next = head2;     // Attach head2 node
                head2 = head2->next;    // Move head2 forward
                tail = tail->next;      // Move tail forward
                tail->next = NULL;      // Detach from old links
            }
        }
        // Attach any remaining nodes
        if (head1)
        {
            tail->next = head1;
        }
        else
        {
            tail->next = head2;
        }

        Node *temp = head;
        head = head->next;   // Skip dummy node
        delete temp;         // Free dummy node memory

        return head;         // Return head of merged list
    }
};

// Function to print the linked list
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from user input
Node *createList(int n)
{
    Node *head = NULL;
    Node *tail = NULL;
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

int main()
{
    Solution solution;
    int n1, n2;
    cout << "Enter number of nodes in first sorted list: ";
    cin >> n1;
    cout << "Enter elements of first sorted list: ";
    Node *head1 = createList(n1);

    cout << "Enter number of nodes in second sorted list: ";
    cin >> n2;
    cout << "Enter elements of second sorted list: ";
    Node *head2 = createList(n2);

    // Merge the lists
    Node *mergedHead = solution.sortedMerge(head1, head2);

    cout << "Merged sorted list: ";
    printList(mergedHead);

    return 0;
}

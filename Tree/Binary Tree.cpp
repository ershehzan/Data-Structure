#include <iostream>
#include <queue>
using namespace std;

// Definition of a Node in the binary tree
class Node
{
public:
    int data;           // Value stored in the node
    Node *left, *right; // Pointers to left and right child nodes

    // Constructor to initialize node with a value and set children to NULL
    Node(int val)
    {
        data = val;         // Assign the provided value to the node
        left = right = NULL; // Initialize children as NULL (no children yet)
    }
};

int main()
{
    int n;
    cout << "Enter the Root: ";
    cin >> n; // Input value for the root node

    int first, second; // Variables to store the left and right child values

    queue<Node *> q;   // Queue to help build the tree level by level (BFS)

    // Create the root node with the user-provided value
    Node *root = new Node(n);
    q.push(root); // Push root node into queue for processing

    // Loop until all nodes have been processed from the queue
    while (!q.empty())
    {
        Node *temp = q.front(); // Retrieve the front node from the queue
        q.pop();                // Remove the node from the queue

        // Prompt the user to enter the left child value of the current node
        cout << "Enter the left child of " << temp->data << ": ";
        cin >> first;
        if (first != -1) // If input is not -1, create a new left child node
        {
            temp->left = new Node(first); // Link the new node as the left child
            q.push(temp->left);           // Add the left child to the queue for further processing
        }

        // Prompt the user to enter the right child value of the current node
        cout << "Enter the Right child of " << temp->data << ": ";
        cin >> second;
        if (second != -1) // If input is not -1, create a new right child node
        {
            temp->right = new Node(second); // Link the new node as the right child
            q.push(temp->right);            // Add the right child to the queue for further processing
        }
    }

    // At this point, the binary tree has been constructed in level order.
    // You can add tree traversal or other operations below as needed.

    return 0; // Indicate successful program termination
}

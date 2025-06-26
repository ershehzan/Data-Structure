#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;      // Value stored in the node
    Node *left;    // Pointer to the left child node
    Node *right;   // Pointer to the right child node

    // Constructor to initialize the node with a value
    Node(int x)
    {
        data = x;           // Set the node's value
        left = right = NULL; // Initialize left and right children to NULL
    }
};

// Helper function to perform a preorder traversal and calculate the sum of all nodes
// Parameters:
//   sum: reference to the total sum (accumulates the values)
//   root: current node being visited
void pre(int &sum, Node *root)
{
    if (root == NULL)
        return;             // Base case: if current node is NULL, do nothing

    sum += root->data;      // Add the current node's value to the sum

    pre(sum, root->left);   // Recursively traverse the left subtree
    pre(sum, root->right);  // Recursively traverse the right subtree
}

// Class containing method to sum all nodes in a binary tree
class Solution
{
public:
    // Function to return the sum of all nodes in the binary tree
    int sumBT(Node *root)
    {
        int sum = 0;            // Initialize sum to zero
        pre(sum, root);         // Call helper to calculate sum via traversal
        return sum;             // Return the final sum
    }
};

int main()
{
    // Manually constructing the following binary search tree:
    //         10
    //        /  \
    //       5    15
    //      / \     \
    //     2   7     20

    Node *root = new Node(10);             // Root node with value 10
    root->left = new Node(5);              // Left child of root (value 5)
    root->right = new Node(15);            // Right child of root (value 15)
    root->left->left = new Node(2);        // Left child of node 5 (value 2)
    root->left->right = new Node(7);       // Right child of node 5 (value 7)
    root->right->right = new Node(20);     // Right child of node 15 (value 20)

    Solution sol;
    int sum = sol.sumBT(root);             // Calculate the sum of all nodes
    cout << "Sum of all nodes in BST: " << sum << endl;

    // Free allocated memory to avoid memory leaks
    delete root->left->left;   // Delete node with value 2
    delete root->left->right;  // Delete node with value 7
    delete root->left;         // Delete node with value 5
    delete root->right->right; // Delete node with value 20
    delete root->right;        // Delete node with value 15
    delete root;               // Delete root node

    return 0; // Indicate successful program execution
}

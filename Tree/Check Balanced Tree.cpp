#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Definition of a binary tree node
class Node {
    public:
        int data;      // Value stored in the node
        Node* left;    // Pointer to left child
        Node* right;   // Pointer to right child

        // Constructor to initialize the node with a value
        Node(int val) {
            data = val;
            left = NULL;    // Initialize left child as NULL
            right = NULL;   // Initialize right child as NULL
        }
};

// Helper function to compute the height of the tree and check balance
// Parameters:
//   root: current node
//   valid: reference to a boolean flag indicating if the tree is balanced
// Returns: height of the current subtree
int h(Node* root, bool &valid) {
    if (!root)
        return 0; // Height of an empty subtree is 0

    int l = h(root->left, valid);   // Height of left subtree
    int r = h(root->right, valid);  // Height of right subtree

    // If the difference in heights is more than 1, tree is not balanced
    if (abs(l - r) > 1)
        valid = 0;

    // Height of current subtree is 1 + maximum of left and right subtree heights
    return 1 + max(l, r);
}

// Solution class to check if a tree is height-balanced
class Solution {
    public:
        // Returns true if the binary tree rooted at 'root' is balanced
        bool isBalanced(Node* root) {
            bool valid = 1;   // Start with the assumption the tree is balanced
            h(root, valid);   // Compute heights and update 'valid' if imbalance found
            return valid;     // Return whether the tree is balanced
        }
};

int main() {
    // Example 1: create a balanced binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol; // Create Solution object to check balance

    // Check if the first tree is balanced
    if (sol.isBalanced(root))
        cout << "Tree is balanced" << endl;
    else
        cout << "Tree is not balanced" << endl;

    // Example 2: create an unbalanced binary tree
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    // Check if the second tree is balanced
    if (sol.isBalanced(root2))
        cout << "Tree is balanced" << endl;
    else
        cout << "Tree is not balanced" << endl;

    // Note: Memory cleanup (deleting nodes) is not shown here,
    // as this is a simple example and the OS will reclaim memory on program exit.

    return 0; // Indicate successful termination
}

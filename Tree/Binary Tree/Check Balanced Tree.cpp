#include <iostream>
#include <algorithm>  // For max()
#include <cmath>      // For abs()
using namespace std;

// Binary tree node structure
class Node {
public:
    int data;      // Value stored in the node
    Node* left;    // Pointer to the left child
    Node* right;   // Pointer to the right child

    // Constructor to initialize a node with a value
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Helper function to compute the height of the tree
// and simultaneously check if the tree is height-balanced
int h(Node* root, bool &valid) {
    if (!root)
        return 0;  // Base case: height of empty subtree is 0

    // Recursively calculate height of left and right subtrees
    int l = h(root->left, valid);
    int r = h(root->right, valid);

    // If difference between left and right subtree heights > 1, mark tree as unbalanced
    if (abs(l - r) > 1)
        valid = 0;

    // Height of current node = 1 + max height of its children
    return 1 + max(l, r);
}

// Main solution class
class Solution {
public:
    // Function to check if a binary tree is height-balanced
    bool isBalanced(Node* root) {
        bool valid = 1;         // Start with assumption that the tree is balanced
        h(root, valid);         // Call the height function which checks balance
        return valid;           // Return result
    }
};

int main() {
    // --------- Example 1: Balanced Tree ---------
    // Constructing the following tree:
    //         1
    //       /   \
    //      2     3
    //     / \
    //    4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    // Check if the first tree is balanced
    if (sol.isBalanced(root))
        cout << "Tree is balanced" << endl;
    else
        cout << "Tree is not balanced" << endl;

    // --------- Example 2: Unbalanced Tree ---------
    // Constructing the following tree:
    //         1
    //        /
    //       2
    //      /
    //     3
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    // Check if the second tree is balanced
    if (sol.isBalanced(root2))
        cout << "Tree is balanced" << endl;
    else
        cout << "Tree is not balanced" << endl;

    // --------- Memory Cleanup (Optional) ---------
    // For a real-world application, you should deallocate memory to avoid memory leaks.
    // In competitive programming or small test cases, it’s often skipped for brevity.

    return 0;
}

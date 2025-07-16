#include <iostream>
#include <queue>
using namespace std;

// Node structure for Binary Tree
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Solution class that checks if a tree is a Max Heap
class Solution {
  public:

    // Counts the total number of nodes in the binary tree
    int count(Node* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }

    // Checks if the binary tree is a Complete Binary Tree (CBT)
    bool CBT(Node* root, int index, int nodes) {
        if (!root) return true;

        // If the index assigned is >= total nodes, it's not CBT
        if (index >= nodes) return false;

        // Recursively check left and right subtrees
        return CBT(root->left, 2 * index + 1, nodes) &&
               CBT(root->right, 2 * index + 2, nodes);
    }

    // Checks if the binary tree satisfies the Max-Heap property
    bool maxheap(Node* root) {
        if (root->left) {
            // If left child is greater than parent, not max heap
            if (root->data < root->left->data)
                return false;
            // Recursively check the left subtree
            if (!maxheap(root->left))
                return false;
        }

        if (root->right) {
            // If right child is greater than parent, not max heap
            if (root->data < root->right->data)
                return false;
            // Recursively check the right subtree
            return maxheap(root->right);
        }

        // If node has no children or only left child, it's valid so far
        return true;
    }

    // Main function to check if a binary tree is a valid Max Heap
    bool isHeap(Node* tree) {
        int num = count(tree);  // Total number of nodes
        if (!CBT(tree, 0, num)) // Check completeness
            return false;
        return maxheap(tree);   // Check heap property
    }
};

int main() {
    /*
        Construct the following binary tree:

                10
               /  \
              9    8
             / \  /
            7  6 5

        This is a valid Max Heap (complete and parent >= children).
    */

    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    Solution obj;

    // Check if the tree is a max heap
    if (obj.isHeap(root))
        cout << "The tree is a Max-Heap." << endl;
    else
        cout << "The tree is NOT a Max-Heap." << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Structure of a tree node
struct Node {
    int data;
    Node *left, *right;

    // Constructor to initialize the node with a value
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Class containing the conversion logic
class Solution {
  public:
    /**
     * Step 1: Perform an inorder traversal of the BST.
     * Inorder traversal of a BST gives nodes in sorted (ascending) order.
     * Store this sorted sequence in a vector.
     */
    void inorder(Node* root, vector<int>& ans) {
        if (!root)
            return;
        inorder(root->left, ans);      // Recursively traverse left subtree
        ans.push_back(root->data);     // Store current node’s value
        inorder(root->right, ans);     // Recursively traverse right subtree
    }

    /**
     * Step 2: Modify the tree to become a Max Heap using postorder traversal.
     * In postorder, we assign values from the sorted array (inorder result),
     * starting from the smallest (index 0) to the largest.
     * Postorder traversal ensures we update child nodes before their parent,
     * which is essential for building a Max Heap.
     */
    void postorder(Node* root, int& index, vector<int>& ans) {
        if (!root)
            return;
        postorder(root->left, index, ans);   // Recursively traverse left subtree
        postorder(root->right, index, ans);  // Recursively traverse right subtree
        root->data = ans[index];             // Replace node’s value with next value from sorted list
        index++;                             // Move to the next value in sorted list
    }

    /**
     * This function integrates both steps to convert BST to Max Heap:
     * - First, it gets sorted values using inorder traversal.
     * - Then, it assigns these values to the tree nodes using postorder traversal.
     */
    void convertToMaxHeapUtil(Node* root) {
        vector<int> ans;          // Vector to store sorted values from BST
        inorder(root, ans);       // Fill vector with inorder traversal (sorted values)

        int index = 0;            // Start from the beginning of the sorted list
        postorder(root, index, ans); // Assign values in postorder to create Max Heap
    }
};

// Helper function to print the tree in postorder traversal.
// Used to verify the final tree follows Max Heap property.
void printPostorder(Node* root) {
    if (!root) return;
    printPostorder(root->left);    // Visit left subtree
    printPostorder(root->right);   // Visit right subtree
    cout << root->data << " ";     // Print current node value
}

int main() {
    /*
        Construct the following Binary Search Tree (BST):

                  4
                /   \
               2     6
              / \   / \
             1   3 5   7
             
        Inorder (sorted): 1 2 3 4 5 6 7
        Postorder (used for assigning values): Left -> Right -> Root
        Resulting Max Heap (not a complete binary heap array):
        Structure remains the same, but values rearranged to follow Max Heap property
    */

    // Manually creating the BST
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Create Solution object
    Solution obj;

    // Convert the BST to Max Heap
    obj.convertToMaxHeapUtil(root);

    // Print postorder traversal of the converted tree
    // This verifies the Max Heap property: children < parent
    cout << "Postorder of the converted Max Heap: ";
    printPostorder(root);
    cout << endl;

    return 0;
}

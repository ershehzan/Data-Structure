#include <iostream>
#include <vector>
using namespace std;

// Structure of a tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Class containing the conversion logic
class Solution {
  public:
    // Step 1: Store the inorder traversal of the BST in a vector
    void inorder(Node* root, vector<int>& ans) {
        if (!root)
            return;
        inorder(root->left, ans);      // Visit left subtree
        ans.push_back(root->data);     // Visit current node
        inorder(root->right, ans);     // Visit right subtree
    }

    // Step 2: Replace the node values in postorder traversal with values from inorder array
    void postorder(Node* root, int& index, vector<int>& ans) {
        if (!root)
            return;
        postorder(root->left, index, ans);   // Visit left subtree
        postorder(root->right, index, ans);  // Visit right subtree
        root->data = ans[index];             // Assign value from inorder list
        index++;
    }

    // Function to convert BST to Max Heap
    void convertToMaxHeapUtil(Node* root) {
        vector<int> ans;

        // Get sorted values of BST using inorder traversal
        inorder(root, ans);

        // Assign values to nodes in postorder traversal to make it Max Heap
        int index = 0;
        postorder(root, index, ans);
    }
};

// Function to print the tree in postorder (used for verifying Max Heap structure)
void printPostorder(Node* root) {
    if (!root) return;
    printPostorder(root->left);    // Visit left
    printPostorder(root->right);   // Visit right
    cout << root->data << " ";     // Print current node
}

int main() {
    /*
        Construct the following BST:
        
                  4
                /   \
               2     6
              / \   / \
             1   3 5   7
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Create Solution object and convert BST to Max Heap
    Solution obj;
    obj.convertToMaxHeapUtil(root);

    // Print postorder traversal of the modified tree (should be a Max Heap)
    cout << "Postorder of the converted Max Heap: ";
    printPostorder(root);
    cout << endl;

    return 0;
}

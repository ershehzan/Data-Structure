#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;
    Node *left;
    Node *right;
    
    // Constructor to initialize a node with data and null left/right pointers
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Solution class that contains the Morris Inorder Traversal method
class Solution
{
public:
    // Function to perform Morris Inorder Traversal
    vector<int> inOrder(Node *root)
    {
        vector<int> ans;

        // Continue traversal until root becomes NULL
        while (root)
        {
            // Case 1: If there is no left subtree
            if (!root->left)
            {
                // Visit the current node
                ans.push_back(root->data);

                // Move to the right subtree
                root = root->right;
            }
            else
            {
                // Find the inorder predecessor of root (rightmost node in left subtree)
                Node *curr = root->left;
                while (curr->right && curr->right != root)
                {
                    curr = curr->right;
                }

                // Case 2: Establish a thread (temporary right pointer to root)
                if (curr->right == NULL)
                {
                    // Create the thread for backtracking
                    curr->right = root;

                    // Move to the left child
                    root = root->left;
                }
                // Case 3: Thread already exists (left subtree already visited)
                else
                {
                    // Remove the thread
                    curr->right = NULL;

                    // Visit the current node
                    ans.push_back(root->data);

                    // Move to the right subtree
                    root = root->right;
                }
            }
        }

        return ans;
    }
};

// Helper function to create a sample binary tree for demonstration
Node *buildSampleTree()
{
    /* Constructing the following binary tree:
             1
           /   \
          2     3
         / \      
        4   5
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

int main()
{
    // Build the sample tree
    Node *root = buildSampleTree();

    // Create Solution object and perform Morris Inorder Traversal
    Solution sol;
    vector<int> inorder = sol.inOrder(root);

    // Print the inorder traversal result
    cout << "Morris Inorder Traversal: ";
    for (int val : inorder)
    {
        cout << val << " ";
    }
    cout << endl;

    // Note: Memory cleanup is not shown here, but should be done in larger applications

    return 0;
}

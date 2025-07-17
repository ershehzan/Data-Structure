#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Tree node structure
struct Node
{
    int data;        // Value of the node
    Node *left;      // Pointer to left child
    Node *right;     // Pointer to right child

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Utility function to search for the position of a value in the inorder array
int search(vector<int> &arr, int target, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        if (arr[i] == target)
            return i; // Return the index where the target is found
    }
    return -1; // Not found (should not happen if input is valid)
}

class Solution
{
public:
    // Recursive function to build the tree from inorder and postorder traversals
    Node *tree(vector<int> &inorder, vector<int> &postorder, int start, int end, int &index)
    {
        // Base case: if the current subtree range is invalid
        if (start > end)
        {
            return NULL;
        }

        // Create the root node using the current postorder element
        Node *root = new Node(postorder[index]);
        index--; // Move to the next root in postorder (right-to-left)

        // Find the index of root in inorder to split left and right subtrees
        int pos = search(inorder, root->data, start, end);

        // Build right subtree before left since we’re traversing postorder from the end
        root->right = tree(inorder, postorder, pos + 1, end, index);

        // Build left subtree
        root->left = tree(inorder, postorder, start, pos - 1, index);

        return root;
    }

    // Main function to initiate tree construction
    Node *buildTree(vector<int> inorder, vector<int> postorder)
    {
        int idx = postorder.size() - 1; // Start from the last element in postorder
        return tree(inorder, postorder, 0, inorder.size() - 1, idx);
    }
};

// Helper function to print the tree in level order (BFS)
void printLevelOrder(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int sz = q.size(); // Number of nodes at current level

        // Process all nodes at current level
        while (sz--)
        {
            Node *curr = q.front();
            q.pop();

            cout << curr->data << " ";

            // Enqueue left child if it exists
            if (curr->left)
                q.push(curr->left);

            // Enqueue right child if it exists
            if (curr->right)
                q.push(curr->right);
        }
        cout << endl; // Move to next level
    }
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> inorder(n), postorder(n);

    // Read inorder traversal
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; ++i)
        cin >> inorder[i];

    // Read postorder traversal
    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; ++i)
        cin >> postorder[i];

    Solution sol;
    Node *root = sol.buildTree(inorder, postorder);

    // Print the constructed tree's level order traversal
    cout << "Level order traversal of constructed tree:" << endl;
    printLevelOrder(root);

    return 0;
}

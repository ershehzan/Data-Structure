#include <iostream>
#include <queue>
using namespace std;

// Definition of a node in the binary tree
class Node {
    public:
        int data;        // Value stored in the node
        Node *left;      // Pointer to the left child
        Node *right;     // Pointer to the right child

        // Constructor to initialize node data and child pointers
        Node(int val) {
            data = val;
            left = right = NULL;
        }
};

// Helper function to find the node with the given 'target' value in the tree.
// If found, the function sets the 'burnNode' pointer to point to this node.
void find(Node* root, int target, Node*& burnNode) {
    if (!root)
        return;
    if (root->data == target) {
        burnNode = root;
        return;
    }
    find(root->left, target, burnNode);   // Search in left subtree
    find(root->right, target, burnNode);  // Search in right subtree
}

// Computes the height of the binary tree rooted at 'root'.
// Height is the number of nodes on the longest path from root down to a leaf.
int height(Node* root) {
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Core recursive function to compute the minimum time to burn the tree
// starting from the node with value 'target'.
// 'timer' keeps track of the maximum time encountered in either subtree.
int Burn(Node* root, int &timer, int target) {
    if (!root)
        return 0;

    // If current node is the target node
    if (root->data == target) {
        int lh = height(root->left);   // Height of left subtree
        int rh = height(root->right);  // Height of right subtree
        timer = max(lh, rh);           // Maximum time to burn either side
        return 1;                      // Return distance from target (itself)
    }

    // Recurse on left subtree
    int left = Burn(root->left, timer, target);
    if (left > 0) {  // If target found in left subtree
        int rh = height(root->right);
        timer = max(timer, left + rh); // Update timer if right subtree is taller
        return left + 1;               // Increase distance from target
    }

    // Recurse on right subtree
    int right = Burn(root->right, timer, target);
    if (right > 0) { // If target found in right subtree
        int lh = height(root->left);
        timer = max(timer, right + lh); // Update timer if left subtree is taller
        return right + 1;               // Increase distance from target
    }

    // Target not found in either subtree
    return 0;
}

// Solution class encapsulating the burning tree logic
class Solution {
    public:
        // Returns the minimum time required to burn the entire tree from the target node
        int minTime(Node* root, int target) {
            int timer = 0;
            Burn(root, timer, target); // First, compute time considering subtree heights

            // Find the pointer to the target node
            Node* burnNode = NULL;
            find(root, target, burnNode);

            // Compute height under the target node (burnNode)
            int high = height(burnNode) - 1;

            // The final answer is the maximum between timer and height under target
            return max(timer, high);
        }
};

// Helper function to build a binary tree from level order input
// -1 is used as a sentinel for NULL nodes
Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return NULL;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        int leftVal, rightVal;
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

int main() {
    cout << "Enter tree in level order (use -1 for NULL nodes):" << endl;
    Node* root = buildTree(); // Build tree from user input

    int target;
    cout << "Enter target node value: ";
    cin >> target;            // Read the target node value

    Solution sol;
    int result = sol.minTime(root, target);  // Calculate minimum burn time

    cout << "Minimum time to burn the tree: " << result << endl;

    return 0;
}

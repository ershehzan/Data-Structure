#include <iostream>
using namespace std;

// Definition of the Node class for the binary tree
class Node
{
public:
    int data;           // Holds the value of the node
    Node *left, *right; // Pointers to left and right child nodes

    // Constructor to initialize the node with a value
    Node(int val)
    {
        data = val;
        left = right = NULL; // Children initialized as NULL
    }
};

// Function to recursively create a binary tree from user input
Node *BinaryTree()
{
    int n;

    cin >> n; // Take input for the current node value
    if (n == -1) // -1 is used as a sentinel value to indicate no node (NULL)
        return NULL;

    Node *temp = new Node(n); // Create a new node with the input value

    // Recursively create the left subtree
    cout << "Enter the left child of " << n << ": ";
    temp->left = BinaryTree();

    // Recursively create the right subtree
    cout << "Enter the right child of " << n << ": ";
    temp->right = BinaryTree();

    return temp; // Return the created node
}

// Preorder traversal: Node -> Left -> Right
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " "; // Visit the root node
    preorder(root->left);      // Traverse the left subtree
    preorder(root->right);     // Traverse the right subtree
}

// Inorder traversal: Left -> Node -> Right
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);       // Traverse the left subtree
    cout << root->data << " "; // Visit the root node
    inorder(root->right);      // Traverse the right subtree
}

// Postorder traversal: Left -> Right -> Node
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);     // Traverse the left subtree
    postorder(root->right);    // Traverse the right subtree
    cout << root->data << " "; // Visit the root node
}

int main()
{
    cout << "Enter the Root: ";
    Node *Root;
    Root = BinaryTree(); // Build the tree from user input
    cout << "Binary Tree created successfully." << endl;

    // Example usage: print the root node's data if tree is not empty
    if (Root != NULL)
    {
        cout << "Root node value: " << Root->data << endl;
    }

    // Display the tree traversals
    cout << "Preorder Traversal: ";
    preorder(Root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(Root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(Root);
    cout << endl;

    return 0;
}

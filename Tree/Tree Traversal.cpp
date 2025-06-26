#include <iostream>
using namespace std;

// Definition of a node in the binary tree
class Node
{
public:
    int data;           // Value stored at this node
    Node *left, *right; // Pointers to left and right child nodes

    // Constructor to initialize node with a value and set children to NULL
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Recursive function to create a binary tree from user input
Node *BinaryTree()
{
    int n;
    cin >> n; // Read the value for the current node

    // If user enters -1, this position is considered NULL (no node)
    if (n == -1)
        return NULL;

    // Create a new node with the entered value
    Node *temp = new Node(n);

    // Recursively build the left subtree
    cout << "Enter the left child of " << n << ": ";
    temp->left = BinaryTree();

    // Recursively build the right subtree
    cout << "Enter the right child of " << n << ": ";
    temp->right = BinaryTree();

    return temp; // Return the created subtree rooted at 'temp'
}

// Preorder traversal: Root -> Left -> Right
void preorder(Node *root)
{
    if (root == NULL)
        return;                  // Base case: empty subtree
    cout << root->data << " ";   // Visit the root node
    preorder(root->left);        // Traverse left subtree
    preorder(root->right);       // Traverse right subtree
}

// Inorder traversal: Left -> Root -> Right
void inorder(Node *root)
{
    if (root == NULL)
        return;                  // Base case: empty subtree
    inorder(root->left);         // Traverse left subtree
    cout << root->data << " ";   // Visit the root node
    inorder(root->right);        // Traverse right subtree
}

// Postorder traversal: Left -> Right -> Root
void postorder(Node *root)
{
    if (root == NULL)
        return;                  // Base case: empty subtree
    postorder(root->left);       // Traverse left subtree
    postorder(root->right);      // Traverse right subtree
    cout << root->data << " ";   // Visit the root node
}

int main()
{
    cout << "Enter the Root: ";
    Node *Root;
    Root = BinaryTree(); // Build the binary tree from user input
    cout << "Binary Tree created successfully." << endl;

    // If the tree is not empty, print the root node's value
    if (Root != NULL)
    {
        cout << "Root node value: " << Root->data << endl;
    }

    // Print all three types of tree traversals
    cout << "Preorder Traversal: ";
    preorder(Root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(Root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(Root);
    cout << endl;

    return 0; // Successful program execution
}

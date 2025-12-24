#include <iostream>
using namespace std;

// Definition of a Node in the binary tree
class Node{
public:
    int data;         // Value stored in the node
    Node *left, *right; // Pointers to the left and right child nodes

    // Constructor to initialize the node with a value and null children
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// Function to build the binary tree recursively
Node *BinaryTree(){
    int n;

    cin >> n; // Read the value for the current node from user input
    if (n == -1) // Use -1 as a sentinel value to indicate no node (NULL)
        return NULL;

    // Create a new node with the entered value
    Node *temp = new Node(n);

    // Recursively build the left subtree
    cout << "Enter the left child of " << n << ": ";
    temp->left = BinaryTree();

    // Recursively build the right subtree
    cout << "Enter the right child of " << n << ": ";
    temp->right = BinaryTree();

    // Return the constructed subtree root
    return temp;
}

// Preorder traversal: visit root, then left subtree, then right subtree
void preorder(Node *root){
    if (root == NULL)
        return;
    cout << root->data << " "; // Print current node's data
    preorder(root->left);      // Traverse left subtree
    preorder(root->right);     // Traverse right subtree
}

// Inorder traversal: visit left subtree, then root, then right subtree
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);       // Traverse left subtree
    cout << root->data << " "; // Print current node's data
    inorder(root->right);      // Traverse right subtree
}

// Postorder traversal: visit left subtree, then right subtree, then root
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);     // Traverse left subtree
    postorder(root->right);    // Traverse right subtree
    cout << root->data << " "; // Print current node's data
}

int main(){
    cout << "Enter the Root: ";
    Node *Root;
    // Start building the binary tree from the root
    Root = BinaryTree();
    cout << "Binary Tree created successfully." << endl;

    // Example usage: print the root node's data if tree is not empty
    if (Root != NULL){
        cout << "Root node value: " << Root->data << endl;
    }

    // Perform and print preorder traversal of the tree
    cout << "Preorder Traversal: ";
    preorder(Root);
    cout << endl;

    // Perform and print inorder traversal of the tree
    cout << "Inorder Traversal: ";
    inorder(Root);
    cout << endl;

    // Perform and print postorder traversal of the tree
    cout << "Postorder Traversal: ";
    postorder(Root);
    cout << endl;

    return 0; // Indicate successful program termination
}

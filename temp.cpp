#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes in the binary tree: ";
    cin >> n;
    queue<Node *> q;
    Node *root = new Node(n);
    q.push(root);

    int first, sec;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter the value of left child of " << temp->data << ": ";
        cin >> first;
        if (first != -1)
        {
            temp->left = new Node(first);
            q.push(temp->left);
        }
        cout << "Enter the value of Right child of " << temp->data << ": ";
        cin >> sec;
        if (sec != -1)
        {
            temp->right = new Node(sec);
            q.push(temp->right);
        }
    }

    return 0;
}

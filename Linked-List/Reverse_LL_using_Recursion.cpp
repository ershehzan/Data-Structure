#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int value) {
        data = value;
        next = NULL;
    }
};

// Recursive Reverse Function
node* reverseList(node* head) {
    if (!head || !head->next)
        return head;

    node* newHead = reverseList(head->next);

    head->next->next = head;  // reverse link
    head->next = NULL;        // break old link

    return newHead;
}

int main(){

    node *head = NULL, *tail = NULL;
    
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    cout<<"Enter the elements: ";

    for (int i = 0; i < n; i++) {   // fixed here
        int val;
        cin>>val;

        if (head == NULL)
        {
            head = new node(val);
            tail = head;
        }
        else
        {
            tail->next = new node(val);
            tail = tail->next;
        }
    }

    cout << "Original Linked List: ";
    node *current = head;
    while (current != NULL)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL" << endl;

    // Reverse the list
    head = reverseList(head);

    cout << "Reversed Linked List: ";
    current = head;
    while (current != NULL)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL" << endl;

    return 0;
}

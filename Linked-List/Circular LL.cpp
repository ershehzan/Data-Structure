#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

int main() {
    node* head = NULL;
    node* tail = NULL;

    int n;
    cout << "Enter the Number of Nodes: ";
    cin >> n;
    cout << "Enter the Value: ";

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        if (head == NULL) {
            head = new node(val);
            tail = head;
        } else {
            node* temp = new node(val);
            tail->next = temp;
            tail = temp;
        }
    }

    // Make the list circular
    if (tail != NULL) {
        tail->next = head;
    }

    // Display the circular linked list
    node* curr = head;
    cout << "Circular Linked List: ";
    if (curr != NULL) {
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
    }

    return 0;
}

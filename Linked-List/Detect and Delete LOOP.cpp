#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
    void removeLoop(Node* head) {
        Node* s = head;
        Node* f = head;
        while (f != NULL && f->next != NULL) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                break;
            }
        }
        if (f == NULL || f->next == NULL)
            return;
        s = head;
        while (s != f) {
            s = s->next;
            f = f->next;
        }
        while (s->next != f) {
            s = s->next;
        }
        s->next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Utility to create a loop for testing
void createLoop(Node* head, int pos) {
    if (pos == 0) return;
    Node* loopNode = head;
    for (int i = 1; i < pos; ++i) {
        loopNode = loopNode->next;
    }
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = loopNode;
}

int main() {
    int n, pos;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter node values: ";
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    cout << "Enter position to create loop (0 for no loop): ";
    cin >> pos;
    createLoop(head, pos);

    Solution solution;
    solution.removeLoop(head);

    cout << "Linked list after removing loop: ";
    printList(head);

    return 0;
}
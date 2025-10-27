// Linked list
#include <iostream>
using namespace std;

struct Node{ // holds the integer value
    int data;
    Node *next; // points to the next node
};
int main(){

    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = nullptr;

    Node *current = first;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}

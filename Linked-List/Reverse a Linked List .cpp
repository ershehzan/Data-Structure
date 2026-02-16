#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int value){
        data = value;
        next = NULL;
    }
};

int main(){

    node *head = NULL, *tail = NULL;

    int arr[] = {20, 30, 40, 50};

    // Creating Linked List
    for (int i = 0; i < 4; i++)
    {
        if (head == NULL) {
            head = new node(arr[i]);
            tail = head;
        }
        else
        {
            tail->next = new node(arr[i]);
            tail = tail->next;
        }
    }

    // 🔹 Reverse Linked List (3 Pointer Method)

    node* curr = head;
    node* prev = NULL;
    node* fut = NULL;

    while (curr != NULL) {
        fut = curr->next;   // store next
        curr->next = prev;  // reverse link
        prev = curr;        // move prev
        curr = fut;         // move curr
    }

    head = prev;  // update head

    // Printing Reversed List
    node *current = head;
    cout << "Reversed Linked List: ";
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}

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

int main(){

    node *head, *tail;
   tail= head = NULL;
    
   int n;
    cout<<"Enter the number of elements: ";
    cin>>n;


    cout<<"Enter the elements: ";

    for (int i = 0; i < 4; i++) {
        int val;
        cin>>val;

        if (head == NULL)
        {
            head = new node(val);
            tail=head;
        }
        else
        {
            tail->next = new node(val);
            tail = tail->next;
        }
    }

    node *current;
    current = head;
    cout << "Linked List: ";
    while (current != NULL)
    {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "NULL" << endl;
    return 0;
}





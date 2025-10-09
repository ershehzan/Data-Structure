#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
int main(){
    node*head=NULL;
    node*tail=NULL;
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

cout<<"Enter the values of the nodes: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;

        if(head==NULL){
            head=new node(val);
            tail=head;
        }
        else{
            node*temp=new node(val);
            tail->next=temp;
            tail=temp;
        }
    }

    tail->next=head;
    cout<<"The circular linked list is: ";
    node*curr=head;
    while(curr){
        cout<<curr->data<<" ";
        curr=curr->next;
        if(curr==head){
            break;
        }
    }
}

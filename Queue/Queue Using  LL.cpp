#include <iostream>
using namespace std;

// Node class for singly linked list node
class Node
{
public:
    int data;       // Data stored in the node
    Node *next;     // Pointer to the next node in the list

    // Constructor to initialize node with a value
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Queue class using linked list
class Queue
{
    Node *front;    // Pointer to the front node
    Node *rear;     // Pointer to the rear node

public:
    // Constructor to initialize an empty queue
    Queue()
    {
        front = rear = NULL;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == NULL;
    }

    // Enqueue operation: add value to the rear of the queue
    void push(int val)
    {
        if (isEmpty())
        {
            // If queue is empty, create the first node
            front = rear = new Node(val);
            cout << "Queue is now initialized with value: " << val << endl;
        }
        else
        {
            // If queue is not empty, create a new node and add it to the end
            Node *temp = new Node(val);
            rear->next = temp;
            cout << "Value " << val << " added to the queue" << endl;
            rear = temp;
        }
    }

    // Dequeue operation: remove value from the front of the queue
    void pop()
    {
        if (isEmpty())
        {
            // If queue is empty, do nothing
            cout << "Queue is empty" << endl;
            return;
        }
        else if (front == rear)
        {
            // If only one node was present, delete it and reset the queue
            delete front;
            front = rear = NULL;
            cout << "Queue is now empty after pop" << endl;
        }
        else
        {
            // Remove the front node and update the front pointer
            Node *temp = front;
            cout << "Popped: " << temp->data << endl;
            front = front->next;
            delete temp;
        }
    }

    // Peek operation: get the value at the front without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, no front element" << endl;
            return -1; // Or throw an exception if preferred
        }
        else
        {
            return front->data;
        }
    }
};

int main()
{
    Queue q;         // Create a Queue object

    // Insert elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Check and display the front element
    cout << "Front element is: " << q.peek() << endl;

    // Remove the front element and display the new front
    q.pop();
    cout << "Front element after pop is: " << q.peek() << endl;

    // Remove again and show front element
    q.pop();
    cout << "Front element after another pop is: " << q.peek() << endl;
}

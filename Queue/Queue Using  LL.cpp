#include <iostream>
using namespace std;

// Node class representing each element in the linked list
class Node {
public:
    int data;      // Data part of node
    Node *next;    // Pointer to next node

    // Constructor to initialize node with data
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Queue class using linked list
class Queue {
    Node *front;  // Pointer to front of the queue
    Node *rear;   // Pointer to rear of the queue

public:
    // Constructor initializes empty queue
    Queue() {
        front = rear = NULL;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Enqueue operation - insert element at rear
    void push(int val) {
        if (isEmpty()) {
            // If queue is empty, front and rear both point to new node
            front = rear = new Node(val);
            cout << "Queue is now initialized with value: " << val << endl;
        } else {
            // Create new node, link to current rear, and update rear
            Node *temp = new Node(val);
            rear->next = temp;
            rear = temp;
            cout << "Value " << val << " added to the queue" << endl;
        }
    }

    // Dequeue operation - remove element from front
    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        } else if (front == rear) {
            // Only one element in queue
            cout << "Popped: " << front->data << " (last element)" << endl;
            delete front;
            front = rear = NULL;
            cout << "Queue is now empty after pop" << endl;
        } else {
            // More than one element
            Node *temp = front;
            cout << "Popped: " << temp->data << endl;
            front = front->next;
            delete temp;
        }
    }

    // Peek operation - get front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty, no front element" << endl;
            return -1; // Could also throw exception
        } else {
            return front->data;
        }
    }

    // Display entire queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            pop(); // Repeatedly delete nodes from front
        }
    }
};

// Driver code to test queue
int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display(); // Output: 10 20 30

    cout << "Front element is: " << q.peek() << endl;

    q.pop();  // Pops 10
    cout << "Front element after pop is: " << q.peek() << endl;

    q.pop();  // Pops 20
    cout << "Front element after another pop is: " << q.peek() << endl;

    q.pop();  // Pops 30
    q.pop();  // Attempting to pop from empty queue

    return 0;
}

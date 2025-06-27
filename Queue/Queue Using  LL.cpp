#include <iostream>
using namespace std;

// Node class for the linked list
class Node {
public:
    int data;      // The value stored in the queue node
    Node* next;    // Pointer to the next node in the queue

    // Constructor to initialize a node with a value
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Queue class implemented using a singly linked list
class Queue {
    Node* front;   // Pointer to the front node of the queue
    Node* rear;    // Pointer to the rear node of the queue

public:
    // Constructor: initially, the queue is empty
    Queue() {
        front = rear = NULL;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Add an element at the rear of the queue
    void push(int x) {
        Node* temp = new Node(x); // Create a new node
        if (rear == NULL) {
            // If queue is empty, both front and rear are the new node
            front = rear = temp;
        } else {
            // Attach new node at the end and update rear
            rear->next = temp;
            rear = temp;
        }
    }

    // Remove the front element from the queue
    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to pop." << endl;
            return;
        }
        // Save the current front, move front to next node, delete old front
        Node* temp = front;
        front = front->next;
        delete temp;
        // If the queue becomes empty, set rear to NULL
        if (front == NULL) {
            rear = NULL;
        }
    }

    // Get the value at the front of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing at the front." << endl;
            return -1; // Indicates empty queue
        }
        return front->data;
    }

    // Display all elements in the queue from front to rear
    void display() {
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Example usage
int main() {
    Queue q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    // Display queue contents
    q.display(); // Output: 10 20 30

    // Show front element
    cout << "Front element: " << q.peek() << endl; // Output: 10

    // Dequeue an element
    q.pop();

    // Display queue contents after pop
    q.display(); // Output: 20 30

    // Show new front element
    cout << "Front element: " << q.peek() << endl; // Output: 20

    return 0;
}

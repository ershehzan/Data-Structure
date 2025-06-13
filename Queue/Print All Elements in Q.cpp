#include <iostream>
using namespace std;

// Simple linear Queue implementation using array
class Queue
{
    int front, rear; // Indices for the front and rear ends of the queue
    int *arr;        // Pointer to dynamically allocated array for storing queue elements
    int size;        // Maximum size of the queue

public:
    // Constructor to initialize the queue with a given size
    Queue(int n)
    {
        arr = new int[n];     // Allocate memory for the queue
        size = n;             // Set the maximum size
        front = rear = -1;    // Initialize front and rear to -1 (queue is empty)
    }

    // Get the current number of elements in the queue
    int getSize() const {
        // If the queue is empty, return 0
        if (front == -1 && rear == -1) return 0;
        // Otherwise, return the number of elements
        return rear - front + 1;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    // Check if the queue is full
    bool isFull()
    {
        return (rear == size - 1);
    }

    // Add an element to the rear of the queue
    void push(int x)
    {
        if (isEmpty())
        {
            // If the queue is empty, insert the first element
            front = rear = 0;
            arr[0] = x;
        }
        else if (isFull())
        {
            // If the queue is full, do not insert and display a message
            cout << "Queue is Full" << endl;
            return;
        }
        else
        {
            // Otherwise, increment rear and insert the new element
            rear++;
            arr[rear] = x;
        }
    }

    // Remove an element from the front of the queue
    void pop()
    {
        if (isEmpty())
        {
            // If the queue is empty, do nothing
            cout << "Queue is Empty" << endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                // If only one element was present, reset the queue to empty
                front = rear = -1;
            }
            else
            {
                // Otherwise, increment front to remove the front element
                front++;
            }
        }
    }

    // Get the front element of the queue
    int peek(){
        if(isEmpty()){
            // If the queue is empty, return -1
            return -1;
        }
        else{
            // Otherwise, return the front element
            return arr[front];
        }
    }
};

int main(){
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n;          // Read queue size from user
    Queue q(n);        // Create a queue of size n

    cout << "Enter element to enqueue: ";
    // Insert n elements into the queue
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;      // Read each element from user
        q.push(x);     // Enqueue the element
    }

    int p = q.getSize(); // Get the number of elements in the queue

    cout << "Queue Elements are:";
    // Print all elements of the queue in order
    while (p--)
    {
        cout << q.peek() << " "; // Print the front element
        q.push(q.peek());        // Re-enqueue the front element to the rear, maintaining order
        q.pop();                 // Remove the front element
    }
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Queue class using a dynamically allocated array
class Queue
{
    int front, rear; // Indices to track the front and rear of the queue
    int *arr;        // Pointer to the array that stores queue elements
    int size;        // Maximum size of the queue

public:
    // Constructor: Initializes the queue with given size
    Queue(int n)
    {
        arr = new int[n];   // Allocate memory for the array
        size = n;
        front = rear = -1;  // Both front and rear start as -1 (queue is empty)
    }

    // Returns the current number of elements in the queue
    int getSize() const {
        if (front == -1 && rear == -1) return 0; // Queue is empty
        return rear - front + 1;                 // Number of elements
    }

    // Checks if the queue is empty
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    // Checks if the queue is full
    bool isFull()
    {
        return (rear == size - 1);
    }

    // Adds an element to the rear of the queue
    void push(int x)
    {
        if (isEmpty())
        {
            front = rear = 0;
            arr[0] = x;
        }
        else if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
    }

    // Removes an element from the front of the queue
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                // Only one element was present; now the queue becomes empty
                front = rear = -1;
            }
            else
            {
                // Move front forward
                front++;
            }
        }
    }

    // Returns the front element of the queue without removing it
    int peek(){
        if(isEmpty()){
            return -1; // Indicate that queue is empty
        }
        else{
            return arr[front];
        }
    }
};

int main(){
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n;
    Queue q(n);

    // Input elements to enqueue
    cout << "Enter element to enqueue: ";
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(x);
    }

    int p = q.getSize();

    // Print all queue elements without changing their order
    cout << "Queue Elements are:";
    while (p--)
    {
        cout << q.peek() << " ";   // Print front element
        q.push(q.peek());          // Re-enqueue the front element to the rear
        q.pop();                   // Remove the front element
        // This combination keeps the queue's order unchanged after the loop
    }
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Circular Queue implementation using class
class Queue
{
    int front, rear; // Pointers to track the front and rear positions
    int *arr;        // Dynamic array to store queue elements
    int size;        // Maximum size of the queue

public:
    // Constructor to initialize queue
    Queue(int n)
    {
        arr = new int[n];  // Allocate memory dynamically
        size = n;          // Set the size of the queue
        front = rear = -1; // Initially, queue is empty
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return (front == -1);
    }

    // Check if queue is full (circular condition)
    bool isFull()
    {
        return ((rear + 1) % size == front);
    }

    // Add an element to the queue (enqueue operation)
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty())
        {
            // First element being inserted
            front = rear = 0;
            arr[rear] = x;
        }
        else
        {
            // Insert in circular manner
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
        cout << "Inserting " << x << " in Queue" << endl;
    }

    // Remove an element from the queue (dequeue operation)
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Removing " << arr[front] << " from Queue" << endl;

        // If only one element was present
        if (front == rear)
        {
            front = rear = -1;
            cout << "Queue is now Empty" << endl;
        }
        else
        {
            // Move front in circular manner
            front = (front + 1) % size;
        }
    }

    // Return the front element of the queue
    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        cout << "Front element is: " << arr[front] << endl;
        return arr[front];
    }
};

// Main function to demonstrate queue operations
int main()
{
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n;

    // Create a queue of given size
    Queue q(n);

    cout << "Enter " << n << " elements to enqueue: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    // You can also call other methods here like:
    // q.dequeue();
    // q.start();

    return 0;
}

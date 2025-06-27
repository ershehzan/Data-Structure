#include <iostream>
using namespace std;

// Queue class using a dynamically-allocated array
class Queue
{
    int front, rear; // Indices for the front and rear of the queue
    int *arr;        // Pointer to the array holding the elements
    int size;        // Maximum size of the queue

public:
    // Constructor to initialize the queue with a given size
    Queue(int n)
    {
        arr = new int[n];   // Allocate memory for the array
        size = n;
        front = rear = -1;  // Both front and rear are -1 when the queue is empty
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
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty())
        {
            // If queue is empty, set front and rear to 0
            front = rear = 0;
            arr[rear] = x;
        }
        else
        {
            // Otherwise, increment rear and insert the element
            rear++;
            arr[rear] = x;
        }
    }

    // Remove an element from the front of the queue
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        else if (front == rear)
        {
            // Only one element present, so queue becomes empty
            front = rear = -1;
        }
        else
        {
            // Move front to the next element
            front++;
        }
    }

    // Get the front element without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1; // Indicates the queue is empty
        }
        else
        {
            return arr[front];
        }
    }

    // Display all elements in the queue from front to rear
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n;
    Queue q(n);

    // Insert elements into the queue
    cout << "Enter elements to enqueue: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    // Display the queue
    q.display();

    // Show the front element
    cout << "Front element: " << q.peek() << endl;

    // Remove an element from the front
    q.pop();
    cout << "Queue after one pop: ";
    q.display();

    return 0;
}

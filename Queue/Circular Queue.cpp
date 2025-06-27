#include <iostream>
using namespace std;

// Definition of a Circular Queue class
class Queue
{
    int front, rear;  // Indices to track the front and rear of the queue
    int *arr;         // Pointer to dynamically allocate the queue array
    int size;         // Maximum size of the queue

public:
    // Constructor to initialize the queue with given size
    Queue(int n)
    {
        arr = new int[n];  // Allocate memory for the queue
        size = n;          // Set the size
        front = rear = -1; // Initialize both front and rear as -1 (queue is empty)
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return (front == -1);
    }

    // Check if the queue is full (circular condition)
    bool isFull()
    {
        // If incrementing rear in a circular fashion meets front, queue is full
        return ((rear + 1) % size == front);
    }

    // Add an element to the queue
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty())
        {
            // If queue is empty, initialize front and rear to 0
            front = rear = 0;
            arr[rear] = x; // Insert element at rear
        }
        else
        {
            // Move rear to next position in circular fashion
            rear = (rear + 1) % size;
            arr[rear] = x; // Insert element at new rear
        }
        cout << "Inserting " << x << " in Queue" << endl;
    }

    // Remove an element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Removing " << arr[front] << " from Queue" << endl;

        if (front == rear)
        {
            // Only one element was present, now queue will be empty
            front = rear = -1;
            cout << "Queue is now Empty" << endl;
        }
        else
        {
            // Move front to next element in circular fashion
            front = (front + 1) % size;
        }
    }

    // Retrieve the front element of the queue
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

int main()
{
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n;         // Take queue size from user
    Queue q(n);       // Create a queue of specified size
    
    cout << "Enter element to enqueue: ";
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;     // Take element from user
        q.enqueue(x); // Insert element into queue
    }

    return 0;
}

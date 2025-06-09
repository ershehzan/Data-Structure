#include <iostream>
using namespace std;

// Class for implementing a simple linear Queue using array
class Queue
{
    int front, rear; // Indices to keep track of the front and rear of the queue
    int *arr;        // Dynamic array for storing queue elements
    int size;        // Maximum size of the queue

public:
    // Constructor to initialize the queue with a given size
    Queue(int n)
    {
        arr = new int[n];   // Dynamically allocate array
        size = n;           // Set queue size
        front = rear = -1;  // Initialize queue as empty
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    // Check if the queue is full
    bool isFull()
    {
        // The queue is full if rear reaches the last index
        return (rear == size - 1);
    }

    // Add an element to the rear of the queue
    void enqueue(int x)
    {
        if (isEmpty())
        {
            cout << "Inserting " << x << " in Queue" << endl;
            front = rear = 0;  // Set front and rear to 0 since queue was empty
            arr[0] = x;        // Insert element at 0th position
        }
        else if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else
        {
            cout << "Inserting " << x << " in Queue" << endl;
            rear++;            // Move rear forward
            arr[rear] = x;     // Insert element at the new rear
        }
    }

    // Remove an element from the front of the queue
    void dequeue()
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
                // Only one element in the queue
                cout << "Removing " << arr[front] << " from Queue" << endl;
                cout << "Queue is now Empty" << endl;
                front = rear = -1; // Reset queue to empty state
            }
            else
            {
                // More than one element
                cout << "Removing " << arr[front] << " from Queue" << endl;
                front++; // Move front forward to remove the element
            }
        }
    }

    // Get the front element of the queue
    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
        {
            cout << "Front element is: " << arr[front] << endl;
            return arr[front];
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n;             // Input the size of the queue from user
    Queue q(n);           // Create a queue of specified size

    cout << "Enter element to enqueue: ";
    // Enqueue n elements into the queue
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    cout << q.start() << endl; // Print the front element

    // The program does not include dequeue or further interaction, but you can add more operations as needed

    return 0;
}

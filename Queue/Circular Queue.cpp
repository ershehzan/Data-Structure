#include <iostream>
using namespace std;

// Class representing a circular queue
class Queue
{
    int front, rear; // Indices to track the front and rear positions in the queue
    int *arr;        // Dynamic array to store queue elements
    int size;        // Maximum size of the queue

public:
    // Constructor to initialize the queue with a given size
    Queue(int n)
    {
        arr = new int[n]; // Allocate memory for the queue
        size = n;         // Set the size
        front = rear = -1; // Initialize front and rear indices as empty
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return (front == -1);
    }

    // Check if the queue is full
    bool isFull()
    {
        // The queue is full if moving rear forward by one wraps to the front
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
        // If the queue is empty, set both front and rear to 0
        else if (isEmpty())
        {
            front = rear = 0;
            arr[rear] = x; // Place the element at the rear
        }
        else
        {
            // Move rear pointer forward circularly and add the element
            rear = (rear + 1) % size;
            arr[rear] = x;
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

        // If there is only one element, reset the queue to empty state
        if (front == rear)
        {
            front = rear = -1;
            cout << "Queue is now Empty" << endl;
        }
        else
        {
            // Move front pointer forward circularly
            front = (front + 1) % size;
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
        cout << "Front element is: " << arr[front] << endl;
        return arr[front];
    }
};

int main()
{
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n; // Take the size of the queue from the user
    Queue q(n); // Create a queue of the given size
    
    cout << "Enter element to enqueue: ";
    // Read n elements from the user and enqueue them
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.enqueue(x);
    }

    return 0;
}

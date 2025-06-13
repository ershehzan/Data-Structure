#include <iostream>
using namespace std;

// Queue implementation using a simple array
class Queue
{
    int front, rear; // front: index of front element, rear: index of last element
    int *arr;        // dynamic array to store queue elements
    int size;        // maximum size of the queue

public:
    // Constructor to initialize the queue with given size
    Queue(int n)
    {
        arr = new int[n];       // dynamically allocate memory for the queue
        size = n;               // assign size
        front = rear = -1;      // initialize front and rear pointers to -1 (queue is empty)
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

    // Insert an element into the queue
    void enqueue(int x)
    {
        if (isEmpty())
        {
            // If queue is empty, insert the first element
            cout << "Inserting " << x << " in Queue" << endl;
            front = rear = 0;
            arr[0] = x;
        }
        else if (isFull())
        {
            // If queue is full, display a message and do not insert
            cout << "Queue is Full" << endl;
            return;
        }
        else
        {
            // Insert element at next rear position
            cout << "Inserting " << x << " in Queue" << endl;
            rear++;
            arr[rear] = x;
        }
    }

    // Remove an element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            // If queue is empty, display a message and do nothing
            cout << "Queue is Empty" << endl;
            return;
        }
        else
        {
            if (front == rear)
            {
                // If only one element was present, queue becomes empty after removal
                cout << "Removing " << arr[front] << " from Queue" << endl;
                cout << "Queue is now Empty" << endl;
                front = rear = -1;
            }
            else
            {
                // Remove the front element and move front to the next position
                cout << "Removing " << arr[front] << " from Queue" << endl;
                front++;
            }
        }
    }

    // View the element at the front of the queue
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
    cin >> n;          // Read queue size from user
    Queue q(n);        // Create a queue of size n

    cout << "Enter element to enqueue: ";
    // Loop to insert n elements into the queue
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;      // Read element from user
        q.enqueue(x);  // Insert element into the queue
    }

    // Display the front element of the queue
    cout << q.start() << endl;

    return 0;
}

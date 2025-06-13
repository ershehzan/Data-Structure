#include <iostream>
using namespace std;

// Circular Queue implementation using array
class Queue
{
    int front, rear; // front: index of front element, rear: index of last element
    int *arr;        // dynamic array to store queue elements
    int size;        // maximum size of the queue

public:
    // Constructor to initialize the queue with given size
    Queue(int n)
    {
        arr = new int[n]; // dynamically allocate memory for the queue
        size = n;         // assign size
        front = rear = -1; // initialize front and rear pointers to -1 (empty queue)
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return (front == -1);
    }

    // Check if the queue is full (circular condition)
    bool isFull()
    {
        return ((rear + 1) % size == front);
    }

    // Insert an element into the queue
    void enqueue(int x)
    {
        if (isFull())
        {
            // If queue is full, display a message and do not insert
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty())
        {
            // If queue is empty, insert the first element
            front = rear = 0;
            arr[rear] = x;
        }
        else
        {
            // Insert element at next rear position in circular manner
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
            // If queue is empty, display a message and do nothing
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Removing " << arr[front] << " from Queue" << endl;

        if (front == rear)
        {
            // If only one element was present, queue becomes empty after removal
            front = rear = -1;
            cout << "Queue is now Empty" << endl;
        }
        else
        {
            // Move front to the next position in circular manner
            front = (front + 1) % size;
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
        cout << "Front element is: " << arr[front] << endl;
        return arr[front];
    }
};

int main()
{
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n; // Read queue size from user
    Queue q(n); // Create a queue of size n
    
    cout << "Enter element to enqueue: ";
    // Loop to insert n elements into the queue
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x; // Read element from user
        q.enqueue(x); // Insert element into the queue
    }

    // Program ends here (could add more operations as needed)
    return 0;
}

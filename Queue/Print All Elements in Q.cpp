#include <iostream>
using namespace std;

// Linear Queue class
class Queue {
    int front, rear;  // Indices to track front and rear positions
    int *arr;         // Dynamic array for queue storage
    int size;         // Maximum size of the queue

public:
    // Constructor to initialize the queue
    Queue(int n) {
        arr = new int[n];      // Allocate array dynamically
        size = n;
        front = rear = -1;     // Initially empty
    }

    // Get current number of elements in queue
    int getSize() const {
        if (front == -1 && rear == -1)
            return 0; // Empty
        return rear - front + 1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == size - 1);
    }

    // Insert an element at rear
    void push(int x) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (isEmpty()) {
            front = rear = 0;  // First element
        }
        else {
            rear++;  // Increment rear to add next element
        }
        arr[rear] = x;  // Store element
    }

    // Remove front element from queue
    void pop() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        else if (front == rear) {
            // Only one element left
            front = rear = -1;
        }
        else {
            front++;  // Move front ahead
        }
    }

    // Get front element without removing it
    int peek() {
        if (isEmpty()) {
            return -1;  // Indicates empty queue
        }
        else {
            return arr[front];
        }
    }
};

// Driver code to test the Queue
int main() {
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n;

    Queue q(n);

    // Input elements into the queue
    cout << "Enter elements to enqueue: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // Get current number of elements in queue
    int p = q.getSize();

    // Display queue elements in order without disturbing them
    cout << "Queue Elements are: ";
    while (p--) {
        cout << q.peek() << " ";  // Print front
        q.push(q.peek());         // Re-insert front at rear to preserve order
        q.pop();                  // Remove front
    }
    cout << endl;

    return 0;
}

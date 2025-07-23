#include <iostream>
using namespace std;

class Queue {
    int front, rear;
    int *arr;
    int size;

public:
    // Constructor
    Queue(int n) {
        arr = new int[n]; // dynamically allocate memory
        size = n;
        front = rear = -1; // initially queue is empty
    }

    // Destructor to deallocate memory
    ~Queue() {
        delete[] arr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == size - 1);
    }

    // Enqueue operation
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
        cout << "Inserting " << x << " in Queue\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Removing " << arr[front] << " from Queue\n";

        if (front == rear) {
            // Only one element was present
            front = rear = -1;
            cout << "Queue is now Empty\n";
        } else {
            front++;
        }
    }

    // Return front element
    int start() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        cout << "Front element is: " << arr[front] << endl;
        return arr[front];
    }

    // Display current queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Driver code
int main() {
    int n;
    cout << "Enter the size of the Queue: ";
    cin >> n;

    Queue q(n);

    cout << "Enter elements to enqueue:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    q.start();      // Peek front
    q.display();    // Display queue
    q.dequeue();    // Remove one
    q.start();      // Peek again
    q.display();    // Display updated queue

    return 0;
}

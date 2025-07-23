#include<iostream>
using namespace std;

// Dequeue class using circular array
class dequeue {
    int front, rear;  // Indices to track the front and rear
    int *arr;         // Array to store elements
    int size;         // Maximum capacity

public:
    // Constructor to initialize the queue
    dequeue(int n) {
        size = n;
        arr = new int[size];   // Allocate array dynamically
        front = rear = -1;     // Initially empty
    }

    // Check if dequeue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if dequeue is full using circular condition
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Insert element at front
    void push_front(int x) {
        if (isFull()) {
            cout << "Dequeue is full\n";
            return;
        } else if (isEmpty()) {
            front = rear = 0;  // First insertion
            arr[front] = x;
        } else {
            front = (front - 1 + size) % size;  // Circular move left
            arr[front] = x;
        }
    }

    // Insert element at rear
    void push_back(int x) {
        if (isFull()) {
            cout << "Dequeue is full\n";
            return;
        } else if (isEmpty()) {
            front = rear = 0;
            arr[rear] = x;
        } else {
            rear = (rear + 1) % size;  // Circular move right
            arr[rear] = x;
        }
    }

    // Remove element from front
    void pop_front() {
        if (isEmpty()) {
            cout << "Dequeue is Empty\n";
            return;
        } else if (front == rear) {
            front = rear = -1;  // Single element removed → empty
        } else {
            front = (front + 1) % size;  // Move front forward circularly
        }
    }

    // Remove element from rear
    void pop_back() {
        if (isEmpty()) {
            cout << "Dequeue is Empty\n";
            return;
        } else if (front == rear) {
            front = rear = -1;  // Single element removed → empty
        } else {
            rear = (rear - 1 + size) % size;  // Move rear back circularly
        }
    }

    // Return element at the front
    int start() {
        if (isEmpty()) {
            cout << "Dequeue is Empty\n";
            return -1;
        } else {
            return arr[front];
        }
    }

    // Return element at the rear
    int end() {
        if (isEmpty()) {
            cout << "Dequeue is Empty\n";
            return -1;
        } else {
            return arr[rear];
        }
    }

    // Display all elements in dequeue
    void display() {
        if (isEmpty()) {
            cout << "Dequeue is Empty\n";
            return;
        }

        cout << "Dequeue contents: ";
        int i = front;

        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    // Destructor to free dynamic memory
    ~dequeue() {
        delete[] arr;
    }
};

// Driver code to test the Dequeue
int main() {
    dequeue d(5);               // Create dequeue of size 5

    d.push_back(10);           // Add 10 to rear
    d.push_back(20);           // Add 20 to rear
    d.push_front(5);           // Add 5 to front
    d.push_front(1);           // Add 1 to front

    d.display();               // Expected: 1 5 10 20

    cout << "Front: " << d.start() << endl; // Output: 1
    cout << "Rear: " << d.end() << endl;    // Output: 20

    d.pop_front();             // Remove 1
    cout << "Front after pop: " << d.start() << endl; // Output: 5

    d.pop_back();              // Remove 20
    cout << "Rear after pop: " << d.end() << endl;    // Output: 10

    return 0;
}

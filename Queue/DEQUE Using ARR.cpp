#include<iostream>
using namespace std;

// Class representing a Double-Ended Queue (DEQUE) using a circular array
class dequeue{
    int front, rear; // Indices to track the front and rear of the deque
    int *arr;        // Pointer to dynamically allocated array for storage
    int size;        // Maximum size of the deque

public:
    // Constructor: Initializes the deque with given size
    dequeue(int n){
        size = n;
        arr = new int[size]; // Allocate memory for the array
        front = rear = -1;   // Both front and rear are set to -1 (deque is empty)
    }

    // Checks if the deque is empty
    bool isEmpty(){
        return front == -1;
    }

    // Checks if the deque is full (circular queue property)
    bool isFull(){
        return (rear + 1) % size == front;
    }

    // Inserts an element at the front of the deque
    void push_front(int x){
        if(isFull()){
            cout << "Dequeue is full\n";
            return;
        }
        else if(isEmpty()){
            // First element being inserted
            front = rear = 0;
            arr[0] = x;
        }
        else{
            // Circularly decrement front and insert
            front = (front - 1 + size) % size;
            arr[front] = x;
        }
    }

    // Inserts an element at the rear of the deque
    void push_back(int x){
        if(isFull()){
            cout << "Dequeue is full\n";
            return;
        }
        else if(isEmpty()){
            // First element being inserted
            front = rear = 0;
            arr[0] = x;
        }
        else{
            // Circularly increment rear and insert
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }

    // Removes an element from the front of the deque
    void pop_front(){
        if(isEmpty()){
            cout << "Dequeue is Empty\n";
            return;
        }
        else if(front == rear){
            // Only one element was present; now deque will be empty
            front = rear = -1;
        }
        else{
            // Move front forward circularly
            front = (front + 1) % size;
        }
    }

    // Removes an element from the rear of the deque
    void pop_back(){
        if(isEmpty()){
            cout << "Dequeue is Empty\n";
            return;
        }
        else if(front == rear){
            // Only one element was present; now deque will be empty
            front = rear = -1;
        }
        else{
            // Move rear backward circularly
            rear = (rear - 1 + size) % size;
        }
    }

    // Returns the front element of the deque
    int start(){
        if(isEmpty()){
            cout << "Dequeue is Empty";
            return -1;
        }
        else{
            return arr[front];
        }
    }

    // Returns the rear element of the deque
    int end(){
        if(isEmpty()){
            cout << "Dequeue is Empty";
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    // Displays all elements in the deque from front to rear
    void display(){
        if (isEmpty()) {
            cout << "Dequeue is Empty\n";
            return;
        }
        cout << "Dequeue contents: ";
        int i = front;
        // Loop from front to rear using circular traversal
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    // Destructor: frees the dynamically allocated array
    ~dequeue(){
        delete[] arr;
    }
};

int main(){
    dequeue d(5);           // Create a deque of size 5
    d.push_back(10);        // Insert 10 at rear
    d.push_back(20);        // Insert 20 at rear
    d.push_front(5);        // Insert 5 at front
    d.push_front(1);        // Insert 1 at front
    d.display();            // Output: Dequeue contents: 1 5 10 20

    cout << "Front: " << d.start() << endl;         // Output: 1
    cout << "Rear: " << d.end() << endl;            // Output: 20

    d.pop_front();          // Remove element from front
    cout << "Front after pop: " << d.start() << endl; // Output: 5

    d.pop_back();           // Remove element from rear
    cout << "Rear after pop: " << d.end() << endl;   // Output: 10

    return 0;
}

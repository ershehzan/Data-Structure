#include <iostream>
#include <stack>
using namespace std;

// Class to implement a Queue using two stacks
class MyQueue {
    stack<int> st1; // Primary stack for enqueue operation
    stack<int> st2; // Secondary stack for dequeue and peek operations

public:
    // Constructor
    MyQueue() {}

    // Check if the queue is empty
    bool empty() {
        // Queue is empty only if both stacks are empty
        return st1.empty() && st2.empty();
    }

    // Insert an element into the queue
    void push(int x) {
        // Always push new element onto st1
        st1.push(x);
    }

    // Remove the front element from the queue and return it
    int pop() {
        if (empty())
            // If both stacks are empty, return 0 (could also throw an exception)
            return 0;

        // If st2 is empty, transfer all elements from st1 to st2
        // This reverses the order and makes the oldest element accessible at the top of st2
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        // The top of st2 is the front of the queue
        int element = st2.top();
        st2.pop();
        return element;
    }

    // Get the front element of the queue without removing it
    int peek() {
        if (empty())
            // If both stacks are empty, return 0
            return 0;

        // If st2 is empty, transfer all elements from st1 to st2, reversing their order
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        // The top of st2 is the front of the queue
        return st2.top();
    }
};

int main() {
    MyQueue q;
    q.push(1); // Enqueue 1
    q.push(2); // Enqueue 2
    q.push(3); // Enqueue 3

    cout << "Front element: " << q.peek() << endl; // Should print 1
    cout << "Pop: " << q.pop() << endl;            // Should print 1
    cout << "Front element: " << q.peek() << endl; // Should print 2
    cout << "Is empty: " << (q.empty() ? "Yes" : "No") << endl; // Should print No

    q.pop(); // Remove 2
    q.pop(); // Remove 3
    cout << "Is empty after popping all: " << (q.empty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}

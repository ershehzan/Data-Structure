#include <iostream>
#include <stack>
using namespace std;

// MyQueue implements FIFO queue using two LIFO stacks
class MyQueue {
    stack<int> st1; // Stack for enqueue operation
    stack<int> st2; // Stack for dequeue/peek operation

public:
    // Constructor: nothing to initialize explicitly
    MyQueue() {}

    // Check if the queue is empty
    bool empty() {
        return st1.empty() && st2.empty();
    }

    // Push element x to the back of queue
    void push(int x) {
        st1.push(x);  // Always push into st1
    }

    // Removes the element from the front of queue and returns it
    int pop() {
        if (empty())
            return 0;

        // If st2 is empty, move elements from st1 to st2 to reverse order
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        // Now the top of st2 is the front of the queue
        int element = st2.top();
        st2.pop();
        return element;
    }

    // Get the front element
    int peek() {
        if (empty())
            return 0;

        // Same logic as pop(), but just return the top without removing
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }

        return st2.top();
    }
};

// Driver code to test the MyQueue class
int main() {
    MyQueue q;

    // Enqueue elements
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // Should print 1
    cout << "Pop: " << q.pop() << endl;            // Should print 1
    cout << "Front element: " << q.peek() << endl; // Should print 2
    cout << "Is empty: " << (q.empty() ? "Yes" : "No") << endl; // Should print No

    // Pop remaining elements
    q.pop();
    q.pop();

    // Check if queue is empty now
    cout << "Is empty after popping all: " << (q.empty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}

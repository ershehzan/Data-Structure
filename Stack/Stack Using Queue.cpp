#include <iostream>
#include <queue>
using namespace std;

// MyStack class implements a stack using a single queue
class MyStack {
public:
    queue<int> q; // Internal queue used to simulate stack behavior

    // Constructor: initializes an empty stack
    MyStack() {}

    // Returns true if the stack is empty, false otherwise
    bool empty() 
    { 
        return q.empty(); 
    }

    // Push operation: adds an element to the top of the stack
    void push(int x) {
        q.push(x); // Enqueue new element at the back of the queue

        // Rotate the queue to bring the new element to the front
        // This ensures LIFO order for stack behavior
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front()); // Move front element to the back
            q.pop();           // Remove the moved element from the front
        }
    }

    // Pop operation: removes and returns the top element of the stack
    int pop() {
        int top = q.front(); // Get the element at the front (top of stack)
        q.pop();             // Remove it from the queue
        return top;          // Return the popped element
    }

    // Top operation: returns the top element of the stack without removing it
    int top() { 
        return q.front(); // The front of the queue is always the stack's top
    }
};

int main() {
    MyStack st; // Create a stack object

    // Push elements onto the stack
    st.push(10); // Stack: 10
    st.push(20); // Stack: 20 (top), 10
    st.push(30); // Stack: 30 (top), 20, 10

    // Show the top element
    cout << "Top element: " << st.top() << endl; // Outputs 30

    // Pop the top element and show it
    cout << "Pop element: " << st.pop() << endl; // Pops and shows 30

    // Show the new top element
    cout << "Top element: " << st.top() << endl; // Outputs 20

    // Check if the stack is empty
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // Outputs No

    // Pop remaining elements
    st.pop(); // Pops 20
    st.pop(); // Pops 10

    // Check if the stack is empty again
    cout << "Is stack empty after popping all? " << (st.empty() ? "Yes" : "No") << endl; // Outputs Yes

    return 0;
}

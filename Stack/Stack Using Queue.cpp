#include <iostream>
#include <queue>
using namespace std;

// Class to implement a stack using a single queue
class MyStack {
public:
    queue<int> q; // The queue used to simulate stack operations

    // Constructor
    MyStack() {}

    // Returns true if the stack is empty
    bool empty() 
    { 
        return q.empty(); 
    }

    // Pushes an element onto the stack
    void push(int x) {
        // Step 1: Add the new element to the back of the queue
        q.push(x);
        // Step 2: Move all elements before the new element to the back of the queue,
        // so the new element comes to the front (top of the stack)
        for (int i = 0; i < q.size() - 1; i++)
        {
            // Push the front element to the back, effectively rotating the queue
            q.push(q.front());
            q.pop();
        }
    }

    // Removes and returns the top element of the stack
    int pop() {
        // The front of the queue is the top of the stack
        int top = q.front();
        q.pop();
        return top;
    }

    // Returns (but does not remove) the top element of the stack
    int top() { 
        return q.front();
    }
};

int main() {
    MyStack st;

    // Push elements onto the stack: 10, 20, 30
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl; // Should print 30
    cout << "Pop element: " << st.pop() << endl; // Should print 30
    cout << "Top element: " << st.top() << endl; // Should print 20
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // Should print No

    // Pop remaining elements
    st.pop();
    st.pop();

    cout << "Is stack empty after popping all? " << (st.empty() ? "Yes" : "No") << endl; // Should print Yes

    return 0;
}

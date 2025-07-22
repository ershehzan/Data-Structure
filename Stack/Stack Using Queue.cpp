#include <iostream>
#include <queue>
using namespace std;

// Stack implemented using a single queue
class MyStack {
public:
    queue<int> q; // Queue to simulate stack operations

    MyStack() {} // Constructor

    // Check if stack is empty
    bool empty() 
    { 
        return q.empty(); 
    }

    // Push operation
    void push(int x) {
        // Push the new element to the queue
        q.push(x);

        // Rotate the queue to move the new element to the front
        // This ensures the newest element is always at the front
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front()); // Push front to back
            q.pop();           // Remove front
        }
    }

    // Pop the top element (which is at the front of the queue)
    int pop() {
        int top = q.front();
        q.pop(); // Remove front (top of stack)
        return top;
    }

    // Return the top element without removing it
    int top() { 
        return q.front();
    }
};

int main() {
    MyStack st;

    // Push elements into stack
    st.push(10);
    st.push(20);
    st.push(30);

    // Top of stack (should be 30)
    cout << "Top element: " << st.top() << endl;

    // Pop top element (should remove 30)
    cout << "Pop element: " << st.pop() << endl;

    // Top of stack now should be 20
    cout << "Top element: " << st.top() << endl;

    // Check if stack is empty
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    // Pop remaining elements
    st.pop(); // Removes 20
    st.pop(); // Removes 10

    // Stack should now be empty
    cout << "Is stack empty after popping all? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}

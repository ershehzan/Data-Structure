#include <iostream>
#include <stack>
using namespace std;

// Solution class that supports stack operations and retrieving minimum in O(1)
class Solution {
    stack<int> s1; // Main stack to store encoded values

public:
    // Constructor
    Solution() {}

    // Pushes an element onto the stack
    void push(int x) {
        if (s1.empty()) {
            // For the first element, both value and min are x
            // Encoded as x * 101 + x (where 101 is a constant larger than possible stack values)
            s1.push(x * 101 + x);
        } else {
            // Decode the current minimum from the top element
            int currentMin = s1.top() % 101;
            // Push the new value and the new minimum (whichever is smaller)
            s1.push(x * 101 + min(x, currentMin));
        }
    }

    // Removes the top element from the stack
    void pop() {
        if (s1.empty())
            return; // If stack is empty, do nothing
        s1.pop();
    }

    // Returns the value of the top element (without removing it)
    int peek() {
        if (s1.empty())
            return -1; // Return -1 if stack is empty
        return s1.top() / 101; // Retrieve the value part (before encoding)
    }

    // Returns the minimum element in the stack in O(1) time
    int getMin() {
        if (s1.empty())
            return -1; // Return -1 if stack is empty
        return s1.top() % 101; // Retrieve the minimum part (after encoding)
    }
};

int main() {
    Solution stack;
    int q;
    cout << "Enter number of operations: ";
    cin >> q;
    cout << "Operations:\n1 x (push x)\n2 (pop)\n3 (peek)\n4 (getMin)\n";
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            stack.push(x); // Push operation
        } else if (op == 2) {
            stack.pop(); // Pop operation
        } else if (op == 3) {
            cout << "Top element: " << stack.peek() << endl; // Peek operation
        } else if (op == 4) {
            cout << "Minimum element: " << stack.getMin() << endl; // Get minimum
        }
    }
    return 0;
}

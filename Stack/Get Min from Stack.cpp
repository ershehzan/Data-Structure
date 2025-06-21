#include <iostream>
#include <stack>
using namespace std;

// Solution class to implement stack with getMin in O(1) time
class Solution {
    stack<int> s1; // Main stack to store encoded values

public:
    // Constructor
    Solution() {}

    // Pushes an element onto the stack
    void push(int x) {
        if (s1.empty()) {
            // For the first element, both value and min are x. Encode as x*101 + x.
            s1.push(x * 101 + x);  // Here, 101 is used as a base for encoding, allowing separation of value and min.
        } else {
            // For subsequent elements, retrieve current min from the encoded value
            int currentMin = s1.top() % 101;
            // Encode current value (x) and new min (smaller of x and current min)
            s1.push(x * 101 + min(x, currentMin));
        }
    }

    // Removes the top element from the stack
    void pop() {
        if (s1.empty())
            return; // Do nothing if stack is empty
        s1.pop();
    }

    // Returns the top element of the stack
    int peek() {
        if (s1.empty())
            return -1; // Return -1 if stack is empty
        return s1.top() / 101; // Retrieve the value part from the encoded integer
    }

    // Retrieves the minimum element in the stack in O(1) time
    int getMin() {
        if (s1.empty())
            return -1; // Return -1 if stack is empty
        return s1.top() % 101; // Retrieve the min part from the encoded integer
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
            stack.push(x); // Push x onto the stack
        } else if (op == 2) {
            stack.pop(); // Pop the top element
        } else if (op == 3) {
            cout << "Top element: " << stack.peek() << endl; // Print the top element
        } else if (op == 4) {
            cout << "Minimum element: " << stack.getMin() << endl; // Print the minimum element
        }
    }
    return 0;
}

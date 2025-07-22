#include <iostream>
#include <stack>
using namespace std;

class Solution {
    stack<int> s1; // Main stack to store encoded values

public:
    // Constructor
    Solution() {}

    // Push a new element onto the stack
    void push(int x) {
        if (s1.empty()) {
            // If stack is empty, store x as both value and min
            // Encode: x * 101 + x
            s1.push(x * 101 + x);
        } else {
            // Extract the current minimum value from the top of the stack
            int currentMin = s1.top() % 101;

            // Encode new element with new min
            // x * 101 stores value, min(x, currentMin) stores updated min
            s1.push(x * 101 + min(x, currentMin));
        }
    }

    // Remove the top element
    void pop() {
        if (!s1.empty())
            s1.pop();  // Pop top encoded value
    }

    // Return the top element (actual value, not encoded)
    int peek() {
        if (s1.empty())
            return -1;
        return s1.top() / 101;  // Decode the original value
    }

    // Return the current minimum element in O(1)
    int getMin() {
        if (s1.empty())
            return -1;
        return s1.top() % 101;  // Decode the stored minimum
    }
};

int main() {
    Solution stack;
    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    cout << "Operations:\n";
    cout << "1 x : push x\n";
    cout << "2   : pop\n";
    cout << "3   : peek (top element)\n";
    cout << "4   : getMin (current minimum)\n";

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            stack.push(x);
        } else if (op == 2) {
            stack.pop();
        } else if (op == 3) {
            cout << "Top element: " << stack.peek() << endl;
        } else if (op == 4) {
            cout << "Minimum element: " << stack.getMin() << endl;
        }
    }

    return 0;
}

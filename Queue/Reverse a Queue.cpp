#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    // Function to reverse the queue using a stack
    queue<int> reverseQueue(queue<int> &q) {
        stack<int> st;

        // Step 1: Transfer all queue elements to the stack
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Transfer back from stack to queue (reversed)
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        return q;
    }
};

int main() {
    Solution solution;
    int n;
    
    cout << "Enter the number of elements in the queue: ";
    cin >> n;

    queue<int> q;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // Reverse the queue
    q = solution.reverseQueue(q);

    // Print reversed queue
    cout << "Reversed queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    return 0;
}

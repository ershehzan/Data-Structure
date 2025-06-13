#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Solution class encapsulating the reverseQueue function
class Solution {
  public:
    // Function to reverse the elements of a queue using a stack
    queue<int> reverseQueue(queue<int> &q) {
        stack<int> st; // Temporary stack to hold queue elements

        // Step 1: Remove all elements from the queue and push them onto the stack
        while (!q.empty()) {
            st.push(q.front()); // Push the front element of queue onto the stack
            q.pop();            // Remove the element from queue
        }

        // Step 2: Pop all elements from the stack and push them back into the queue
        // This reverses the order of elements in the queue
        while (!st.empty()) {
            q.push(st.top());   // Push the top element of the stack into the queue
            st.pop();           // Remove the element from the stack
        }

        // Return the reversed queue
        return q;
    }
};

int main() {
    Solution solution;     // Create Solution object
    int n;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;             // Read the number of elements

    queue<int> q;         // Create an empty queue

    cout << "Enter the elements: ";
    // Input n elements and add them to the queue
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // Reverse the queue using the solution class
    q = solution.reverseQueue(q);

    cout << "Reversed queue: ";
    // Output the elements of the reversed queue
    while (!q.empty()) {
        cout << q.front() << " "; // Print the front element
        q.pop();                  // Remove the element from the queue
    }
    cout << endl;

    return 0;
}

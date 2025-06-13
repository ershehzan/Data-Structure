#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Solution class containing the function to reverse first K elements of a queue
class Solution
{
public:
    // Function to reverse first k elements of a queue
    queue<int> reverseFirstK(queue<int> q, int k)
    {
        // Guard condition: if k is invalid, return the original queue
        if (k > q.size() || k < 0)
            return q;

        stack<int> st;

        // Step 1: Push first k elements from queue to stack
        for (int i = 0; i < k; ++i)
        {
            st.push(q.front()); // Push the front element to the stack
            q.pop();            // Remove the element from queue
        }

        // Step 2: Pop elements from stack and enqueue back to queue
        // This reverses the first k elements
        while (!st.empty())
        {
            q.push(st.top());   // Add the top element of stack to the rear of queue
            st.pop();           // Remove the element from stack
        }

        // Step 3: Move the remaining (size - k) elements (which are in correct order) to the back
        int rem = q.size() - k;
        for (int i = 0; i < rem; ++i)
        {
            q.push(q.front());  // Move front element to the rear
            q.pop();            // Remove front element
        }

        // Return the queue with the first k elements reversed
        return q;
    }
};

int main()
{
    queue<int> q;
    int n, k, val;
    cout << "Enter number of elements in queue: ";
    cin >> n; // Read the number of elements

    cout << "Enter the elements: ";
    // Read n elements and enqueue them
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        q.push(val);
    }

    cout << "Enter value of k: ";
    cin >> k; // Read k

    Solution sol;
    queue<int> res = sol.reverseFirstK(q, k); // Reverse first k elements

    cout << "Queue after reversing first " << k << " elements: ";
    // Print the final queue
    while (!res.empty())
    {
        cout << res.front() << " ";
        res.pop();
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
    queue<int> reverseFirstK(queue<int> q, int k)
    {
        // Edge case: k is invalid
        if (k > q.size() || k < 0)
            return q;

        stack<int> st;

        // Step 1: Push first k elements into stack
        for (int i = 0; i < k; ++i)
        {
            st.push(q.front());
            q.pop();
        }

        // Step 2: Add stack elements (reversed) back into queue
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }

        // Step 3: Move remaining elements (after first k) to the back
        int rem = q.size() - k;
        for (int i = 0; i < rem; ++i)
        {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};

int main()
{
    queue<int> q;
    int n, k, val;

    cout << "Enter number of elements in queue: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        q.push(val);
    }

    cout << "Enter value of k: ";
    cin >> k;

    Solution sol;
    queue<int> res = sol.reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!res.empty())
    {
        cout << res.front() << " ";
        res.pop();
    }
    cout << endl;

    return 0;
}

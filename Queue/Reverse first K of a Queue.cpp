#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse the first k elements of a queue
void reverseFirstK(queue<int> &q, int k) {
    if (q.empty() || k > q.size() || k <= 0) {
        // Edge case: do nothing if k is invalid
        return;
    }

    stack<int> s;

    // Step 1: Push the first k elements from the queue onto the stack
    for (int i = 0; i < k; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue the elements from the stack back into the queue (they are now reversed)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the remaining elements (n-k) to the back to preserve their order
    int t = q.size() - k;
    for (int i = 0; i < t; ++i) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, k;

    // Input: number of elements, followed by elements, then k
    cout << "Enter the number of elements in the queue: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q.push(x);
    }

    cout << "Enter k (number of elements to reverse): ";
    cin >> k;

    cout << "Original Queue: ";
    queue<int> temp = q; // Copy for displaying
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

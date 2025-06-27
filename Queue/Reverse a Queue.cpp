#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse the elements of a queue using a stack
void reverseQueue(queue<int> &q) {
    stack<int> s; // Stack to help reverse the queue

    // Step 1: Dequeue all elements from the queue and push them onto the stack
    while (!q.empty()) {
        s.push(q.front()); // Push the front element of the queue onto the stack
        q.pop();           // Remove the front element from the queue
    }

    // Step 2: Pop all elements from the stack and enqueue them back into the queue
    while (!s.empty()) {
        q.push(s.top());  // Push the top element of the stack into the queue
        s.pop();          // Remove the top element from the stack
    }
    // Now the queue is reversed
}

int main() {
    queue<int> q;

    // Insert elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Original Queue: ";
    // Print elements before reversing
    queue<int> temp = q; // Make a copy to print without modifying the original
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the queue
    reverseQueue(q);

    cout << "Reversed Queue: ";
    // Print elements after reversing
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

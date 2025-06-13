#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Solution class encapsulating the logic for the ticket buying problem (LeetCode 2073)
class Solution {
public:
    // Function to calculate the time required for the person at position k to buy all their tickets
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;                // Queue to keep track of ticket buyers' positions
        int n = tickets.size();
        // Initialize the queue with indices of all people
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        int time = 0;                // Counter for total time (tickets bought)

        // Continue until the person at position k has bought all their tickets
        while (tickets[k] != 0) {
            // The person at the front of the queue buys 1 ticket
            tickets[q.front()]--;

            // If the person at the front still needs tickets, put them at the end of the queue
            if (tickets[q.front()])
                q.push(q.front());

            // Remove the person from the front (whether or not they go to the back)
            q.pop();
            time++;                  // Increment time for this transaction
        }
        return time;                 // Return the total time taken
    }
};

int main() {
    vector<int> tickets = {2, 3, 2};   // Example: 3 people with 2, 3, and 2 tickets to buy respectively
    int k = 2;                         // We want the time for person at position 2 (0-based)
    Solution sol;
    int result = sol.timeRequiredToBuy(tickets, k);
    cout << "Time required to buy tickets: " << result << endl;
    return 0;
}

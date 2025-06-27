#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// Function to find the maximum in every window of size k in the array
vector<int> slidingWindowMaximum(const vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> result;    // Stores the result (maximums for each window)
    deque<int> dq;         // Stores indices of useful elements (potential maximums) for the current window

    for (int i = 0; i < n; ++i) {
        // Remove indices that are out of the current window
        // dq.front() is out of this window if it is <= i - k
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove indices whose corresponding values are less than the current element
        // They cannot be the maximum if current element is greater
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        // Add current index to the back of the deque
        dq.push_back(i);

        // The largest element for this window is at the front of the deque
        // Start adding to result when we have the first full window (i >= k - 1)
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter elements of array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter window size (k): ";
    cin >> k;

    // Find and print the maximum in each sliding window
    vector<int> max_in_windows = slidingWindowMaximum(arr, k);
    cout << "Maximum of each window: ";
    for (int val : max_in_windows) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

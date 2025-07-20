#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Max-heap for the K1 smallest elements
        priority_queue<long long> p1;

        // Max-heap for the (K2 - 1) smallest elements
        priority_queue<long long> p2;

        // Fill the first heap with the first K1 elements
        for (long long i = 0; i < K1; i++)
            p1.push(A[i]);

        // Fill the second heap with the first (K2 - 1) elements
        for (long long i = 0; i < K2 - 1; i++)
            p2.push(A[i]);

        // For the rest of the array, maintain top K1 smallest elements in p1
        for (long long i = K1; i < N; i++) {
            if (A[i] < p1.top()) {
                p1.pop();           // Remove the largest among the smallest K1
                p1.push(A[i]);      // Add the smaller element
            }
        }

        // For the rest of the array, maintain top (K2 - 1) smallest elements in p2
        for (long long i = K2 - 1; i < N; i++) {
            if (A[i] < p2.top()) {
                p2.pop();           // Remove the largest among the smallest K2-1
                p2.push(A[i]);      // Add the smaller element
            }
        }

        // Calculate sum of K1 smallest elements
        long long sum1 = 0;
        while (!p1.empty()) {
            sum1 += p1.top();
            p1.pop();
        }

        // Calculate sum of (K2 - 1) smallest elements
        long long sum2 = 0;
        while (!p2.empty()) {
            sum2 += p2.top();
            p2.pop();
        }

        // The difference gives the sum of elements between K1-th and K2-th smallest
        return sum2 - sum1;
    }
};

int main() {
    long long arr[] = {1, 3, 12, 5, 15, 11};
    long long N = sizeof(arr) / sizeof(arr[0]);
    long long K1 = 3, K2 = 6;

    Solution sol;
    long long result = sol.sumBetweenTwoKth(arr, N, K1, K2);

    // Output the result
    cout << "Sum between " << K1 << "-th and " << K2 << "-th smallest elements is: " << result << endl;

    return 0;
}

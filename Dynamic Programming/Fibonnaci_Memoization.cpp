//Top-down Dynamic Programming approach to find the nth Fibonacci number
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fibo(int n, vector<int>& dp) {
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> dp(n + 1, -1);
    cout << "Fibonacci of " << n << " = " << sol.fibo(n, dp) << endl;

    return 0;
}

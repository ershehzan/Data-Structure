//Bottom-Up Dynamic Programming approach to find the nth Fibonacci number
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;

        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is " << sol.fib(n) << endl;

    return 0;
}

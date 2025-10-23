//Bottom up
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 2, -1);
        dp[n] = 1;
        dp[n + 1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + dp[i + 2];
        }
        return dp[0];
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    int result = sol.climbStairs(n);
    cout << "Number of distinct ways to climb " << n << " stairs: " << result << endl;

    return 0;
}

//top down approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(int i, int n, vector<int>& dp) {
        if (i == n)
            return 1;
        if (i > n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = count(i + 1, n, dp) + count(i + 2, n, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 2, -1);
        return count(0, n, dp);
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

//bottom up approach with memoization
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ways(int n, vector<int>& cost, vector<int>& dp) {
        if (n <= 1)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = min(cost[n - 1] + ways(n - 1, cost, dp),
                           cost[n - 2] + ways(n - 2, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return ways(n, cost, dp);
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter number of steps: ";
    cin >> n;

    vector<int> cost(n);
    cout << "Enter cost for each step:\n";
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    cout << "Minimum cost to climb stairs: " << obj.minCostClimbingStairs(cost) << endl;

    return 0;
}

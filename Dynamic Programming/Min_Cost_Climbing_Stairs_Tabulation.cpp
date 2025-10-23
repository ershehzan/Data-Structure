//Top down approach (Tabulation) to find the minimum cost to climb stairs
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++) {
            dp[i] = min(cost[i - 1] + dp[i - 1],
                        cost[i - 2] + dp[i - 2]);
        }

        return dp[n];
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

    cout << "Minimum cost to climb stairs: " 
         << obj.minCostClimbingStairs(cost) << endl;

    return 0;
}

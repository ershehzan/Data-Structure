            #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int curr = 0, prev = 0, prev1 = 0;

        for (int i = 2; i <= n; i++) {
            curr = min(cost[i - 1] + prev, cost[i - 2] + prev1);
            prev1 = prev;
            prev = curr;
        }

        return curr;
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

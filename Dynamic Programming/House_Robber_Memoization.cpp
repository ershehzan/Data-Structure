//top Down approach with memoization
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robbery(int i, vector<int> nums, vector<int>& dp) {
        if (i == 0)
            return nums[0];

        if (i == 1)
            return max(nums[0], nums[1]);

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = max(nums[i] + robbery(i - 2, nums, dp), robbery(i - 1, nums, dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robbery(n - 1, nums, dp);
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter amount in each house: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Maximum money that can be robbed: " << obj.rob(nums) << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to rob houses in a given linear range
    int robbery(vector<int>& nums, int start, int end) {
        int prev = nums[start], prev1 = 0, curr = 0;

        for (int i = start + 1; i <= end; i++) {
            curr = max(nums[i] + prev1, prev);
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        // Case 1: Rob houses from 0 to n-2
        int case1 = robbery(nums, 0, n - 2);

        // Case 2: Rob houses from 1 to n-1
        int case2 = robbery(nums, 1, n - 1);

        // Return the best of both cases
        return max(case1, case2);
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

    cout << "Maximum money that can be robbed (circular): " << obj.rob(nums) << endl;

    return 0;
}

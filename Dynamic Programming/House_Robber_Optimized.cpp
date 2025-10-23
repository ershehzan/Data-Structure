#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);

        int curr, prev = max(nums[0], nums[1]), prev1 = nums[0];

        for (int i = 2; i < n; i++) {
            curr = max(nums[i] + prev1, prev);
            prev1 = prev;
            prev = curr;
        }
        return curr;
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

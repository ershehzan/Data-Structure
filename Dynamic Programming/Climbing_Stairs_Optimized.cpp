#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int curr, next = 1, next1 = 0;

        for (int i = n - 1; i >= 0; i--) {
            curr = next + next1;
            next1 = next;
            next = curr;
        }
        return curr;
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

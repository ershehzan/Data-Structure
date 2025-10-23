#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long T(int n, vector<long long>& dp) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = T(n - 1, dp) + T(n - 2, dp) + T(n - 3, dp);
    }

    int tribonacci(int n) {
        vector<long long> dp(n + 1, -1);
        return T(n, dp);
    }
};

int main() {
    int n;
    cin >> n;  // Input the value of n

    Solution obj;
    cout << obj.tribonacci(n) << endl;  // Output the nth Tribonacci number

    return 0;
}

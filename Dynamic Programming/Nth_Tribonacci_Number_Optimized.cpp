#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        int prev3 = 0, prev2 = 1, prev1 = 1, curr = 0;

        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};

int main() {
    int n;
    cin >> n;  // Input the value of n

    Solution obj;
    cout << obj.tribonacci(n) << endl;  // Output nth Tribonacci number

    return 0;
}

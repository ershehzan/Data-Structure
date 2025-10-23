#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;

        int curr, prev = 1, prev1 = 0;

        for (int i = 2; i <= n; i++) {
            curr = prev + prev1;
            prev1 = prev;
            prev = curr;
        }
        return curr;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is " << obj.fib(n) << endl;

    return 0;
}

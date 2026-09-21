#include <iostream>
using namespace std;
bool isprime(int n)
{
    if (n < 2)
    {
        return 0;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cout << "Enter the Number:";
    cin >> n;
    int ans = 0;
    while (n)
    {
        int rem = n % 10;
        n /= 10;
        ans += rem;
    }
    cout << "Good prime:" << isprime(ans);

    return 0;
}
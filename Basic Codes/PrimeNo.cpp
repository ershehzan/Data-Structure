// Prime Number
#include <iostream>
using namespace std;

int main()
{
    int n;
    // Prompt the user to enter a number
    cout << "Enter a number: ";
    cin >> n;

    // Prime numbers are greater than 1
    if (n < 2)
    {
        cout << "Number is not prime";
        return 0;
    }

    // Check divisibility from 2 to n/2
    for (int i = 2; i <= n/2; i++) 
    {
        // If n is divisible by any number in this range, it's not prime
        if (n % i == 0)
        {
            cout << "Number is not prime";
            return 0;
        }
    }

    // If no divisors found, n is prime
    cout << "Number is prime";
    return 0;
}

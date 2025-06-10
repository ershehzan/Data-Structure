#include <iostream>
using namespace std;

// Recursive function to check if a number is prime
// n: the number to check for primality
// i: the current divisor being tested (starts from 2)
bool isPrimeRecursive(int n, int i = 2)
{
    if (n <= 1)
        return false;                   // Numbers less than or equal to 1 are not prime

    if (i == n)
        return true;                    // No divisors found; n is prime

    if (n % i == 0)
        return false;                   // n is divisible by i; not prime

    // Recursively check for next possible divisor
    return isPrimeRecursive(n, i + 1);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Check if n is prime using the recursive function and print result
    if (isPrimeRecursive(n))
        cout << n << " is a prime number." << endl;
    else
        cout << n << " is not a prime number." << endl;

    return 0;
}

// Prime Number
#include <iostream>
using namespace std;

int main()
{
    int n;
<<<<<<< HEAD
    // Prompt the user to enter a number
    cout << "Enter a number: ";
    cin >> n;

    // Prime numbers are greater than 1
=======
    cout << "Enter a number: ";
    cin >> n;

>>>>>>> 549b0d8 (file update)
    if (n < 2)
    {
        cout << "Number is not prime";
        return 0;
    }

<<<<<<< HEAD
    // Check divisibility from 2 to n/2
    for (int i = 2; i <= n/2; i++) 
    {
        // If n is divisible by any number in this range, it's not prime
=======
    for (int i = 2; i <= n/2; i++) 
    {
>>>>>>> 549b0d8 (file update)
        if (n % i == 0)
        {
            cout << "Number is not prime";
            return 0;
        }
    }

<<<<<<< HEAD
    // If no divisors found, n is prime
=======
>>>>>>> 549b0d8 (file update)
    cout << "Number is prime";
    return 0;
}

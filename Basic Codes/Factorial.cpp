// factorial
#include <iostream>
using namespace std;
<<<<<<< HEAD
=======

>>>>>>> 549b0d8 (file update)
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;
    double fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    cout << "Factorial of " << n << " is " << fact;

    return 0;
}

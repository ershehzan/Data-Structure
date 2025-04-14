// Leap year
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a year: ";
    cin >> n;

    if (n % 400 == 0 && n % 100 != 0)
    {
        cout << "The year is a leap year";
    }
    else if (n % 4 == 0)
    {
        cout << "The year is a leap year";
    }
    else
    {
        cout << "The year is not a leap year";
    }
    return 0;
}
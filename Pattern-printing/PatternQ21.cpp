#include <iostream>
using namespace std;

int main()
{
    int n, i, j;

    // Prompt the user to enter the number of rows for the pattern
    cout << "Enter the number : ";
    cin >> n; // Read the value of n from user input

    // Loop for each row from 1 to n
    for (i = 1; i <= n; i++)
    {
        // First inner loop: print spaces for right alignment
        // For row i, print (n - i) sets of two spaces
        for (j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }

        // Second inner loop: print letters from 'A' up to the i-th letter
        for (j = 1; j <= i; j++)
        {
            char name = 'A' + j - 1; // Calculate the current character
            cout << name << " ";
        }

        // Move to the next line after completing the current row
        cout << endl;
    }

    return 0; // Indicate successful program execution
}

/* Output Example for n = 5

        A 
      A B 
    A B C 
  A B C D 
A B C D E

*/

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
        // For row i, print (n - i) sets of two spaces to align the letters
        for (j = 1; j <= n - i; j++)
        {
            cout << "  "; // Two spaces for each slot to match the output format
        }

        // Calculate the character to print ('A' for first row, 'B' for second, etc.)
        char name = 'A' + (i - 1);
        // If you use 'j' instead of 'i' here, output will be reversed

        // Second inner loop: print the character for the current row, i times
        for (j = 1; j <= i; j++)
        {
            cout << name << " ";
        }

        // Move to the next line after completing the current row
        cout << endl;
    }

    return 0; // Indicate successful program execution
}

/* Output Example for n = 5

        A 
      B B 
    C C C 
  D D D D 
E E E E E

*/

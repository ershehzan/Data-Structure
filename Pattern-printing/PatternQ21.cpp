#include <iostream>
using namespace std;
<<<<<<< HEAD

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
=======
int main()
{
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        // space print
>>>>>>> 549b0d8 (file update)
        for (j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }

<<<<<<< HEAD
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
=======
        for (j = 1; j <= i; j++)
        {
            char name = 'A' + j - 1; 

            cout << name << " ";
        }
        cout << endl;
    }
    return 0;
}
/* Output
>>>>>>> 549b0d8 (file update)

        A 
      A B 
    A B C 
  A B C D 
A B C D E
<<<<<<< HEAD

*/
=======
   */
>>>>>>> 549b0d8 (file update)

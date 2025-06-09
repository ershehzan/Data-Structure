<<<<<<< HEAD
#include <iostream> // Include the input/output stream library for using cout and cin
using namespace std; // Use the standard namespace

int main()
{
    // i = row index, j = column index
    int n, i, j; // Declare variables: n for size of the pattern, i/j as loop counters

    cout << "Enter the number : "; // Prompt the user to enter the size of the pattern
    cin >> n; // Read and store the user's input in n

    // First part: upper half of the pattern (including the middle row)
    for (i = 1; i <= n; i++)
    {
        // Print leading spaces to center the stars
        for (j = 1; j <= n - i; j++)
            cout << " ";

        // Print stars with spaces
        for (j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl; // Move to the next line after each row is printed
    }

    // Second part: lower half of the pattern (excluding the middle row)
    for (i = n-1; i >= 1; i--)
    {
        // Print leading spaces to center the stars
        for (j = 1; j <= n - i; j++)
            cout << " ";

        // Print stars with spaces
        for (j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl; // Move to the next line after each row is printed
    }
    return 0; // Indicate successful program execution
}

/* Output Example for n = 10:
=======
#include <iostream>
using namespace std;
int main()
{
    // i=row   j= column
    int n, i, j;
    cout << "Enter the number : ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        // space print
        for (j = 1; j <= n - i; j++)

            cout << " ";
        // star print
        for (j = 1; j <= i; j++)
        {

            cout << "* ";
        }
        cout << endl;
    }

    for (i = n-1; i >= 1; i--)
    {
        // space print
        for (j = 1; j <= n - i; j++)

            cout << " ";
        // star print
        for (j = 1; j <= i; j++)
        {

            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
/* Output

>>>>>>> 549b0d8 (file update)
         * 
        * *         
       * * *        
      * * * *       
     * * * * *      
    * * * * * *     
   * * * * * * *    
  * * * * * * * *   
 * * * * * * * * *  
* * * * * * * * * * 
 * * * * * * * * *  
  * * * * * * * *   
   * * * * * * *    
    * * * * * *     
     * * * * *      
      * * * *       
       * * * 
        * *  
         *   
<<<<<<< HEAD
*/
=======

   */
>>>>>>> 549b0d8 (file update)

#include <iostream>
using namespace std;
int main()
{
    // i=row    j=column
    int n, i, j;
    cout << "Enter a number :";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        // Nested loop
        // loop N to 1
        for (j = n; j >= 1; j--)// Opposite Loop
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
/*Output
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
5 4 3 2 1 
<<<<<<< HEAD
5 4 3 2 1 
*/
=======
5 4 3 2 1  */
>>>>>>> 549b0d8 (file update)

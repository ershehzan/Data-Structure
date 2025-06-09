#include <iostream>
using namespace std;
<<<<<<< HEAD

int main()
{
    // Declare an array of integers with some initial values
    int arr[1000] = {6, 4, 12, -3, 7, 14, 28};
    
    // Variable 'n' represents the number of elements in the array
    int n = 7;
    
    // Declare another array to store the prefix sum of 'arr'
    int prefix[1000];

    // Initialize the first element of the prefix sum array
    // The first prefix sum is the same as the first element of the original array
    prefix[0] = arr[0];

    // Loop to calculate the prefix sum for the rest of the elements
    for (int i = 1; i < n; i++)
    {
        // Each element in the prefix sum array is the sum of the current element
        // in the original array and the previous element in the prefix sum array
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Output the calculated prefix sum array
    cout << "Prefix sum array: ";
    for (int i = 0; i < n; i++)
    {
        // Print each element of the prefix sum array
        cout << prefix[i] << " ";
    }

    return 0; // Indicate that the program executed successfully
}
=======
int main()
{

    int arr[1000] = {6, 4, 12, -3, 7, 14, 28};
    int n = 7;
    int prefix[1000];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    cout << "Prefix sum array: ";
    for (int i = 0; i < n; i++)
    {
        cout << prefix[i] << " ";
    }

    return 0;
}
>>>>>>> 549b0d8 (file update)

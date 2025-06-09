#include <iostream>
using namespace std;

int main()
{
    int n;
<<<<<<< HEAD
    // Prompt the user to enter the number of elements in the array
=======
>>>>>>> 549b0d8 (file update)
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
<<<<<<< HEAD
    // Prompt the user to enter the elements of the array
=======
>>>>>>> 549b0d8 (file update)
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

<<<<<<< HEAD
    // Initialize two pointers: start (beginning of the array) and end (end of the array)
    int start = 0, end = n - 1;
    // Loop until the start pointer crosses the end pointer
    while (start < end)
    {
        // If the current element at start is 0, move start forward
=======
    int start = 0, end = n - 1;
    while (start < end)
    {
>>>>>>> 549b0d8 (file update)
        if (arr[start]  == 0)
        {
            start++;
        }
<<<<<<< HEAD
        // If the current element at end is 0, swap it with arr[start] and move start forward
=======
>>>>>>> 549b0d8 (file update)
        else if (arr[end] == 0)
        {
            swap(arr[start], arr[end]);
            start++;
        }
        else
        {
<<<<<<< HEAD
            // If arr[end] is 1, move end backward
=======

>>>>>>> 549b0d8 (file update)
            end--;
        }
    }

<<<<<<< HEAD
    // Print the final array after segregating 0s and 1s
=======
    // Print the final array after moving zeros to the right
>>>>>>> 549b0d8 (file update)
    cout << "Array after moving zeros to the right: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

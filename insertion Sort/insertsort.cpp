// Implementation of the Insertion Sort algorithm in C++
#include <iostream>  // Include the input-output stream library for console input and output
using namespace std; // Use the standard namespace to avoid prefixing standard functions with "std::"

int main()
{
    // Variable declarations
    int i, j, key; // Loop counters `i` and `j`, and the `key` to temporarily hold the element being sorted
    int arr[6] = {10, 41, 64, 29, 11, 9}; // Initialize an array of 6 integers with sample unsorted values

    /*
     * Outer loop traverses the array starting from the second element (index 1) 
     * because the first element (index 0) is trivially sorted.
    */
    for (i = 1; i < 6; i++)
    {
        key = arr[i]; // The current element to be sorted
        j = i - 1;    // Start comparing with the previous element in the sorted portion of the array

        /*
         * Inner loop: Shift elements of the sorted portion of the array (to the left of `i`) 
         * that are greater than `key` to one position ahead of their current position.
        */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Move the larger element one position to the right
            j = j - 1;           // Move to the previous element in the sorted portion
        }
        arr[j + 1] = key; // Insert the `key` into its correct position within the sorted portion
    }

    // Output the sorted array
    cout << "Sorted Array is: ";
    for (i = 0; i < 6; i++)
    {
        cout << arr[i] << " "; // Output each sorted element separated by a space
    }

    return 0; // Indicate that the program executed successfully
}

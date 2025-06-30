#include <iostream>    // Include the input/output stream library
using namespace std;

// Bubble sort implementation with optimization for early exit
int main()
{
    int arr[1000];     // Declare an array to store up to 1000 elements
    int n;             // Variable to store the number of elements

    // Prompt the user to enter the size of the array
    cout << "Enter the size of array: ";
    cin >> n;          // Read the size from the user

    // Prompt the user to enter the array elements
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read each element into the array
    }

    // Bubble Sort Algorithm
    // Outer loop goes from the second-last element down to the first
    for (int i = n - 2; i >= 0; i--)
    {
        bool swapped = false; // Track if any elements were swapped in this pass

        // Inner loop compares adjacent elements up to the i-th index
        for (int j = 0; j <= i; j++)
        {
            // If the current element is greater than the next, swap them
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]); // Swap elements
                swapped = true;           // Mark that a swap occurred
            }
        }

        // If no two elements were swapped in the inner loop, the array is sorted
        if (!swapped)
            break; // Exit early as the array is already sorted
    }

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Print each element
    }
    cout << endl;

    return 0; // Indicate successful program termination
}

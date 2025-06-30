#include <iostream> // For standard input and output operations
using namespace std;

// Bubble Sort implementation
int main()
{
    int arr[1000]; // Declare an array with a capacity for 1000 integers
    int n;         // Variable to store the number of elements in the array

    // Prompt the user to enter the size of the array
    cout << "Enter the size of array: ";
    cin >> n; // Read the size from user input

    // Ask the user to input the elements of the array
    cout << "Enter the elements of array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read each element into the array
    }

    // Bubble Sort Algorithm:
    // Outer loop iterates over the array from the end to the beginning
    for (int i = n - 2; i >= 0; i--)
    {
        bool swapped = false; // Flag to track if any elements were swapped during this pass

        // Inner loop compares adjacent elements up to the i-th position
        for (int j = 0; j <= i; j++)
        {
            // If the current element is greater than the next, swap them
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]); // Swap the elements
                swapped = true;           // Set the flag to true since a swap occurred
            }
        }

        // If no elements were swapped in the inner loop, the array is sorted
        if (!swapped)
            break; // Exit the loop early as the array is now sorted
    }

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Print each element of the sorted array
    }
    cout << endl; // Print a newline at the end

    return 0; // Indicate successful program completion
}

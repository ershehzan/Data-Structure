#include <iostream>      // For input and output operations
#include <algorithm>     // For the swap function
using namespace std;

// This function partitions the array around a pivot element
// All elements less than or equal to the pivot are moved to its left
// All elements greater are moved to its right
int partition(int arr[], int start, int end)
{
    int pos = start; // Position to place the next smaller element

    // Iterate through the array from start to end
    for (int i = start; i <= end; i++)
    {
        // If current element is less than or equal to pivot (chosen as arr[end])
        if (arr[i] <= arr[end])
        {
            swap(arr[i], arr[pos]); // Place it at the correct position
            pos++;                  // Move position forward
        }
    }
    // Return the final position of the pivot
    return pos-1;
};

// QuickSort function recursively sorts the array using divide-and-conquer
void QuickSort(int arr[], int start, int end)
{
    // Base case: If the array has one or no elements, it's already sorted
    if (start >= end)
    {
        return;
    }

    // Partition the array and get the pivot's final position
    int pivot = partition(arr, start, end);

    // Recursively sort the elements before the pivot
    QuickSort(arr, start, pivot - 1);
    // Recursively sort the elements from the pivot onwards
    QuickSort(arr, pivot, end);
};

int main()
{
    // Initialize an array with unsorted values
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3};
    int n = 8; // Number of elements in the array

    // Call QuickSort on the entire array
    QuickSort(arr, 0, n - 1);

    cout << "Sorted array: " << endl;
    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

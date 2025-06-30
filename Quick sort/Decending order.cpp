#include <iostream>      // For standard input and output
#include <algorithm>     // For the swap function
using namespace std;

// Partition function for QuickSort in descending order
// Rearranges elements so all elements greater than or equal to the pivot
// are on the left, and those less are on the right
int partition(int arr[], int start, int end)
{
    int pos = start; // Position to place the next larger element

    // Iterate through the subarray from start to end
    for (int i = start; i <= end; i++)
    {
        // If current element is greater than or equal to pivot (arr[end])
        if (arr[i] >= arr[end])
        {
            swap(arr[i], arr[pos]); // Move the element to the correct position
            pos++;                  // Increment position
        }
    }
    // Return the final position of the pivot
    return pos - 1;
};

// QuickSort function (recursive) for sorting array in descending order
void QuickSort(int arr[], int start, int end)
{
    // Base case: If subarray has less than two elements, do nothing
    if (start >= end)
    {
        return;
    }

    // Partition the array and get the correct position of the pivot
    int pivot = partition(arr, start, end);

    // Recursively sort elements before the pivot
    QuickSort(arr, start, pivot - 1);

    // Recursively sort elements after the pivot
    QuickSort(arr, pivot + 1, end);
};

int main()
{
    // Initialize an array with unsorted values
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3};
    int n = 8; // Size of the array

    // Call QuickSort to sort the array in descending order
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

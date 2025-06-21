#include <iostream>
#include <algorithm>
using namespace std;

// Partition function that reorders elements for descending order quick sort
int partition(int arr[], int start, int end)
{
    int pos = start; // Position of the next larger element (for descending order)

    // Loop through the array from start to end
    for (int i = start; i <= end; i++)
    {
        // If current element is greater than or equal to pivot (arr[end]), swap it to the front
        if (arr[i] >= arr[end])
        {
            swap(arr[i], arr[pos]); // Move element to its correct position
            pos++; // Move position pointer forward
        }
    }
    // Return the final position of the pivot element after partitioning
    return pos - 1;
}

// Recursive QuickSort function for sorting in descending order
void QuickSort(int arr[], int start, int end)
{
    // Base case: if the subarray has one or no elements, it's already sorted
    if (start >= end)
    {
        return;
    }

    // Partition the array and get the pivot index
    int pivot = partition(arr, start, end);

    // Recursively sort the elements before and after the pivot
    QuickSort(arr, start, pivot - 1);
    QuickSort(arr, pivot + 1, end);
}

int main()
{
    // Example array to be sorted
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3};
    int n = 8; // Number of elements in the array

    // Call QuickSort on the entire array for descending order
    QuickSort(arr, 0, n - 1);

    // Output the sorted array
    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

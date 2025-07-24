#include <iostream>
#include <algorithm> // For swap function
using namespace std;

// Partition function - rearranges the array such that elements <= pivot are to its left and others to its right
int partition(int arr[], int start, int end)
{
    int pos = start; // This keeps track of the final position of the pivot

    // Loop through the array from start to end
    for (int i = start; i <= end; i++)
    {
        // If current element is less than or equal to pivot (which is arr[end])
        if (arr[i] >= arr[end])
        {
            // Place it at the current 'pos' position and increment 'pos'
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    // Return the position of the pivot (one position before 'pos' as 'pos' was incremented last)
    return pos - 1;
}

// Recursive QuickSort function
void QuickSort(int arr[], int start, int end)
{
    // Base case: if the subarray has 0 or 1 element, it's already sorted
    if (start >= end)
    {
        return;
    }

    // Partition the array and get the pivot index
    int pivot = partition(arr, start, end);

    // Recursively sort the subarrays before and after the pivot
    QuickSort(arr, start, pivot - 1); // Left subarray
    QuickSort(arr, pivot, end);       // Right subarray
}

int main()
{
    // Sample array
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3};
    int n = 8; // Size of array

    // Call QuickSort on the entire array
    QuickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

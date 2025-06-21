#include <iostream>
#include <algorithm>
using namespace std;

// Partition function for Quick Sort (sorts in ascending order)
int partition(int arr[], int start, int end)
{
    int pos = start; // Tracks the position to place the next smaller or equal element

    // Traverse the array from start to end
    for (int i = start; i <= end; i++)
    {
        // If the current element is less than or equal to the pivot (arr[end]), swap it to the correct position
        if (arr[i] <= arr[end])
        {
            swap(arr[i], arr[pos]); // Move smaller/equal element to front
            pos++; // Increment the position pointer
        }
    }
    // Return the final position of the pivot element after partitioning
    return pos - 1;
}

// Recursive QuickSort function for sorting in ascending order
void QuickSort(int arr[], int start, int end)
{
    // Base case: if the subarray has one or zero elements, it's already sorted
    if (start >= end)
    {
        return;
    }

    // Partition the array and get the pivot's final position
    int pivot = partition(arr, start, end);

    // Recursively sort the elements before the pivot
    QuickSort(arr, start, pivot - 1);
    // Recursively sort the elements from pivot onwards (since this partition function includes all elements <= pivot up to 'pos')
    QuickSort(arr, pivot, end);
}

int main()
{
    // Initialize the array to be sorted
    int arr[] = {9, 7, 5, 11, 12, 2, 14, 3};
    int n = 8; // Number of elements in the array

    // Sort the array using QuickSort
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

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 8, 5}; // Example array (mountain/bitonic array)
    int size = sizeof(arr) / sizeof(arr[0]); // Determine the number of elements in the array
    int start = 0, end = size - 1; // Initialize pointers for binary search

    // Binary search to find the peak index
    while (start < end)
    {
        int mid = start + (end - start) / 2; // Calculate the middle index

        // Check if mid is the peak element (greater than neighbors)
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            cout << "Peak Element is at index: " << mid << endl;
            return 0; // Exit after finding the peak
        }

        // If right neighbor is larger, move to the right half
        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else // Otherwise, move to the left half
        {
            end = mid - 1;
        }
    }

    // After the loop, start and end converge at the peak element
    cout << "Peak Element is at index " << start << " is : " << arr[start] << endl;

    return 0;
}

<<<<<<< HEAD
#include <iostream>
using namespace std;

/**
 * Searches for a target value in a rotated sorted array.
 * @param arr   The input array (rotated and sorted).
 * @param size  The size of the array.
 * @param target The value to search for.
 * @return      Index of target if found, otherwise -1.
 */
int searchInRotatedArray(int arr[], int size, int target)
{
    int start = 0, end = size - 1, mid;

    // Perform binary search while the range is valid
    while (start <= end)
    {
        // Calculate the middle index to avoid overflow
        mid = start + (end - start) / 2;

        // Check if the middle element is the target
        if (arr[mid] == target)
            return mid;

        // Determine if the left half is sorted
        if (arr[start] <= arr[mid])
        {
            // Target is in the left (sorted) half
            if (arr[start] <= target && target < arr[mid])
                end = mid - 1;
            else // Target is in the right half
                start = mid + 1;
        }
        else
        { 
            // Right half is sorted
            // Target is in the right (sorted) half
            if (arr[mid] < target && target <= arr[end])
                start = mid + 1;
            else // Target is in the left half
                end = mid - 1;
        }
    }
    return -1; // Target not found
}

int main()
{
    // Example rotated sorted array
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int target;

    cout << "Enter the Target: ";
    cin >> target;

    // Call search function and get index of target
    int index = searchInRotatedArray(arr, 7, target);

    // Output the result
    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}
=======
#include <iostream>
using namespace std;

int searchInRotatedArray(int arr[], int size, int target)
{
    int start = 0, end = size - 1, mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid;

        // Determine if the left half is sorted
        if (arr[start] <= arr[mid])
        {
            if (arr[start] <= target && target < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        { // Right half is sorted
            if (arr[mid] < target && target <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1; // Target not found
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int target;

    cout << "Enter the Target: ";
    cin >> target;

    int index = searchInRotatedArray(arr, 7, target);

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found" << endl;

    return 0;
}
>>>>>>> 549b0d8 (file update)

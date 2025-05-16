#include <iostream>
using namespace std;

int main()
{
    // Initialize an array with a rotated sorted sequence.
    int arr[1000] = {4, 5, 6, 7, 8, 10, 1, 2};
    int start = 0, end = 7, ans = arr[0]; // 'ans' will store the minimum element found.

    // Perform binary search to find the minimum element in the rotated sorted array.
    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Calculate middle index to avoid overflow.

        // If the middle element is greater than or equal to the first element,
        // then the minimum must be in the right half (or could be the first element itself).
        if (arr[mid] >= arr[0])
        {
            start = mid + 1; // Move start pointer to the right.
        }
        else
        {
            // If arr[mid] is less than arr[0], this could be the minimum.
            // Update 'ans' and move the end pointer to the left to check for smaller elements.
            ans = arr[mid];
            end = mid - 1;
        }
    }

    // Output the minimum element found in the rotated sorted array.
    cout << ans;
    return 0;
}

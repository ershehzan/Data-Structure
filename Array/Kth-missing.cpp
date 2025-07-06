#include <iostream>
using namespace std;

int main()
{
    // Define an array of integers containing sorted positive integers with missing numbers
    int arr[1000];
    int n, i;
    cout << "Enter the index: ";
    cin >> n;
    cout << "Enter the Elements: ";
    for (i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    int k;
    cout << "Enter the position of missing element: ";
    cin >> k;

    // Initialize variables for binary search
    int start = 0, end = n - 1, mid, ans = n;

    // Perform binary search to determine the position of the k-th missing number
    while (start <= end)
    {
        // Calculate the middle index to split the search range
        mid = start + (end - start) / 2;

        // Check how many numbers are missing up to the index `mid`
        // The count of missing numbers is calculated as `arr[mid] - mid - 1`
        if (arr[mid] - mid - 1 >= k)
        {
            ans = mid;     // Update the answer to the current index `mid`
            end = mid - 1; // Narrow the search to the left side
        }
        else
        {
            start = mid + 1; // Narrow the search to the right side
        }
    }

    // Calculate the k-th missing number using `ans` and `k`
    // `ans` is the index where the k-th missing number lies, and we add `k` to adjust for the missing offset
    cout << "The Kth Missing Positive Integer is : " << ans + k << endl;

    return 0;
}

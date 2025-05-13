#include <iostream> // Include the iostream library for input and output operations
#include <algorithm> // Include the algorithm library for sorting the array
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1, mid; // Initialize the left, right, and mid pointers

    // Loop until the search space is exhausted
    while (left <= right)
    {
        mid = left + (right - left) / 2; // Calculate the mid index (avoiding potential integer overflow)

        // Check if the mid element matches the target
        if (arr[mid] == target)
        {
            return mid; // Element found, return its index
        }
        // If the target is greater than the mid element, search in the right half
        else if (arr[mid] < target)
        {
            left = mid + 1; // Adjust the left pointer to narrow the search space
        }
        // If the target is smaller than the mid element, search in the left half
        else
        {
            right = mid - 1; // Adjust the right pointer to narrow the search space
        }
    }
    // If the target is not found, return -1
    return -1;
}

int main()
{
    int n, target; // Variables for the size of the array and the target element to search
    int arr[1000]; // Declare an array of maximum size 1000

    // Prompt the user to input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Prompt the user to input the elements of the array
    cout << "Enter " << n << " elements (sorted order recommended for correct results): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Ensure the array is sorted before performing binary search
    sort(arr, arr + n); // Sort the array using the standard sort function

    // Display the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Prompt the user to input the target element to search
    cout << "Enter the number to search: ";
    cin >> target;

    // Perform binary search to find the target element
    int result = binarySearch(arr, n, target);

    // Check and display the result of the binary search
    if (result != -1)
    {
        cout << "Element is present at index: " << result << endl; // Element found
    }
    else
    {
        cout << "Element is not present in the array." << endl; // Element not found
    }

    return 0; // Indicate successful program execution
}

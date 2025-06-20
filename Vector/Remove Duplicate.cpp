#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Initialize a vector with some integers, including duplicates
    vector<int> arr = {5, 3, 8, 6, 2, 9, 10, 7, 4, 10};
    int n = 10; // Number of elements in the vector

    // Sort the array using bubble sort so that duplicates are adjacent
    // (You could also use sort(arr.begin(), arr.end()); for simplicity)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]); // Swap if the current element is greater than the next
            }
        }
    }

    // Remove duplicates from the sorted array
    int i;
    for (i = 0; i < n - 1; i++)
    {
        // If two adjacent elements are the same
        if (arr[i] == arr[i + 1])
        {
            arr.erase(arr.begin() + i); // Remove the duplicate element
            i--; // Step back to check the new element at this position
            n--; // Reduce the size of the array
        }
    }

    // Print the array after removing duplicates
    cout << "After removing duplicates: ";
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }

    return 0; // Program finished successfully
}

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[1000], n; // Declare an array of size 1000 and a variable n for length

    // Input array size
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input array elements from the user
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Sort the array to bring duplicate elements together
    sort(arr, arr + n);

    // Removing duplicates by comparing adjacent elements
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n;)
        {
            if (arr[i] == arr[j])
            {
                // If duplicate found, shift all elements left to overwrite arr[j]
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--; // Reduce array size since a duplicate was removed
            }
            else
            {
                j++; // Only increase j if no deletion occurred
            }
        }
    }

    // Output the array after removing duplicates
    cout << "Array after deletion of duplicate elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

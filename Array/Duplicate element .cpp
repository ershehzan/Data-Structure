#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[1000], n;

    // Input array size
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    // Removing duplicates
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n;)
        {
            if (arr[i] == arr[j])
            {
                // Shift elements to the left
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--; // Reduce array size
            }
            else
            {
                j++; // Move to the next element only if no deletion occurs
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
 // LC-26
//  int n = arr.size();
//         if (n == 0) return 0; // Edge case: empty array
        
//         int index = 1; // Pointer for placing unique elements
        
//         for (int i = 1; i < n; i++) {
//             if (arr[i] != arr[i - 1]) {
//                 arr[index] = arr[i]; // Place unique element at index
//                 index++;
//             }
//         }
//         return index; // New length of the array
//     }
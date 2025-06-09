#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
<<<<<<< HEAD

int main()
{
    // Initialize a vector with some integer values
    // The vector may contain duplicate elements
    vector<int> arr = {5, 3, 8, 6, 2, 9, 10, 7, 4, 10};
    
    // Variable 'n' holds the size of the vector
    int n = 10;

    // Step 1: Sort the vector in ascending order using Bubble Sort
    // Note: The STL `sort` function (commented out below) can also be used for this purpose
    // sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        // Inner loop to compare adjacent elements and swap them if they are out of order
=======
int main()
{

    vector<int> arr = {5, 3, 8, 6, 2, 9, 10, 7, 4, 10};
    int n = 10;

    // sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {

>>>>>>> 549b0d8 (file update)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
<<<<<<< HEAD
                // Swap elements to arrange them in ascending order
=======
>>>>>>> 549b0d8 (file update)
                swap(arr[j], arr[j + 1]);
            }
        }
    }

<<<<<<< HEAD
    // Step 2: Remove duplicate elements from the sorted vector
    int i;
    for (i = 0; i < n - 1; i++)
    {
        // Check if the current element is equal to the next element
        if (arr[i] == arr[i + 1])
        {
            // Remove the duplicate element by erasing it from the vector
            arr.erase(arr.begin() + i);

            // Adjust the index and size variables to reflect the removal
            i--;  // Step back to check the new element at index 'i'
            n--;  // Decrease the size of the vector
        }
    }

    // Step 3: Output the vector after removing duplicates
    cout << "After removing duplicates: ";
    for (int j = 0; j < n; j++)
    {
        // Print each element of the updated vector
        cout << arr[j] << " ";
    }

    return 0; // Exit the program successfully
}
=======
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            arr.erase(arr.begin() + i);
            i--;
            n--;
        }
    }
    cout<<"After removing duplicates: ";
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}
>>>>>>> 549b0d8 (file update)

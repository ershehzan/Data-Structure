// Binary Search Implementation

#include <iostream> // Include the iostream library for input and output operations
using namespace std;

int main()
{
    int n, l = 0, r, m; // Variables for the number to search, left index, right index, and mid index

    // Prompt the user to input the number they want to search
    cout << "Enter the Number to search: ";
    cin >> n;

    // Array of sorted integers for performing binary search
    int arr[] = {1, 2, 4, 6, 7, 9, 10, 21, 34, 45, 65, 78, 99, 100, 107};

    // Calculate the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Set r to the last index of the array
    r = size - 1;

    // Begin binary search
    while (l <= r)
    {
        m = l + (r - l) / 2; // Calculate the mid index to avoid integer overflow

        // Check if the middle element matches the search key
        if (arr[m] == n)
        {
            cout << "Element is present at index " << m << endl; // Output the index of the found element
            return 0; // Exit the program since the element is found
        }
        // If the search key is greater than the middle element, search the right half
        else if (arr[m] < n)
        {
            l = m + 1; // Adjust the left index to narrow the search space
        }
        // If the search key is smaller than the middle element, search the left half
        else
        {
            r = m - 1; // Adjust the right index to narrow the search space
        }
    }

    // If the element is not found, output a message
    cout << "Element is not present in the array" << endl;

    return 0; // Indicate successful program execution
}

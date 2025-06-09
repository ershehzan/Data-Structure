<<<<<<< HEAD
#include <iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std::

// Function to perform Binary Search in a sorted array
int BinarySearch(int arr[], int key, int n)
{
    int start = 0, end = n - 1, mid; // Initialize the start, end, and mid variables

    // Loop until the search space is exhausted
    while (start <= end)
    {
        int mid = (start + end) / 2; // Calculate the middle index of the current search space

        // Check if the middle element matches the key
        if (arr[mid] == key)
        {
            cout << "Element found at index "; // Inform the user about the found element
            return mid; // Return the index of the found element
        }
        // If the key is larger than the middle element, search the right half
        else if (arr[mid] < key)
        {
            start = mid + 1; // Adjust the start index to narrow the search space
        }
        // If the key is smaller than the middle element, search the left half
        else
        {
            end = mid - 1; // Adjust the end index to narrow the search space
        }
    }
    // If the key is not found, return -1
=======
#include <iostream>
using namespace std;

int BinarySearch(int arr[], int key, int n)
{
    int start = 0, end = n - 1, mid;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            cout << "Element found at index ";
            return mid;
        }
        else if (arr[mid] < key)
        {

            start = mid + 1;
        }
        else
        {

            end = mid - 1;
        }
    }
>>>>>>> 549b0d8 (file update)
    return -1;
}

int main()
{
<<<<<<< HEAD
    int arr[1000]; // Declare an array of size 1000
    int n; // Variable to store the size of the array

    // Prompt the user to input the size of the array
    cout << "Enter the index of array: ";
    cin >> n;

    // Prompt the user to input the elements of the array
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key; // Variable to store the key to be searched

    // Prompt the user to input the key they want to search
    cout << "Enter the number to search: " << endl;
    cin >> key;

    // Perform Binary Search and display the result
    cout << BinarySearch(arr, key, n) << endl;

    return 0; // Indicate successful program execution
}
=======
    int arr[1000];
    int n;
    cout << "Enter the index of array : ";
    cin >> n;
    cout << "Enter the elements of array : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter the number to search : " << endl;
    cin >> key;

    cout << BinarySearch(arr, key, n) << endl;
    return 0;
}
>>>>>>> 549b0d8 (file update)

<<<<<<< HEAD
// LeetCode 34: Find First and Last Position of Element in Sorted Array using Binary Search
#include <iostream>
using namespace std;

/*
 * This function attempts to find the first and last occurrence of a key in a sorted array using binary search.
 * However, as currently implemented, it only returns -1, and doesn't output the positions found.
 * The function demonstrates the binary search approach for both first and last occurrence.
 */
int BinarySearch(int arr[], int key, int n)
{
    // Initialize variables for binary search
    int start = 0, end = n - 1;
    int first = -1, last = -1; // To store the results

    // Find the first occurrence of the key
    while (start <= end)
    {
        int mid = start + (end - start) / 2; // Calculate mid to avoid overflow
        if (arr[mid] == key)
        {
            first = mid;      // Update first occurrence
            end = mid - 1;    // Continue searching on the left half
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;  // Move to the right half
        }
        else
        {
            end = mid - 1;    // Move to the left half
        }
    }

    // Reset search range for finding the last occurrence
    start = 0;
    end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            last = mid;        // Update last occurrence
            start = mid - 1;   // (This should be start = mid + 1) - currently a bug
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;   // Move to the right half
        }
        else
        {
            end = mid - 1;     // Move to the left half
        }
    }

    // As written, the function only returns -1. Typically, you'd want to return or print first and last.
    // For demonstration and consistency with original code, return -1.
    // To actually return positions, you could modify as:
    // cout << "First Occurrence: " << first << ", Last Occurrence: " << last << endl;
    return -1;
}

int main()
{
    int arr[1000]; // Array to hold up to 1000 elements
    int n;

    // Input: size of the array
    cout << "Enter the index of array : ";
    cin >> n;

    // Input: elements of the array (should be sorted for binary search to work correctly)
    cout << "Enter the elements of array : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    // Input: the key to search for
    cout << "Enter the number to search : " << endl;
    cin >> key;

    // Perform binary search and print result
    cout << BinarySearch(arr, key, n) << endl;

    return 0;
}
=======

//first and last occurrance in binary search problem of leet code 34.
#include <iostream>
using namespace std;

int BinarySearch(int arr[], int key, int n)
{

int start=0,end=n-1,first=-1,last=-1,mid;
        while (start <= end)
    {
        int mid = start + (end-start) / 2;
        if (arr[mid] == key)
        {
            first=mid;
            end=mid-1;
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
    start=0,end=n-1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
           last=mid;
           start=mid-1;
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
    return -1;
}
int main()
{
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

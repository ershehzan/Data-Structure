<<<<<<< HEAD
// Selection Sort implementation in C++
// This program sorts an array using the Selection Sort algorithm.

#include <iostream>
using namespace std;

int main()
{
    int arr[1000]; // Array to store elements (max size 1000)
    int n;

    // Prompt user for the number of elements
    cout << "Enter the Index: ";
    cin >> n;

    // Prompt user to input the array elements
=======

#include <iostream>
using namespace std;
int main()
{

    int arr[1000];
    int n;
    cout << "Enter the Index: ";
    cin >> n;
>>>>>>> 549b0d8 (file update)
    cout << "Enter the Elements of Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

<<<<<<< HEAD
    // Selection Sort algorithm
    for (int i = 0; i < n - 1; i++)
    {
        int index = i; // Assume the current index is the minimum
        for (int j = i + 1; j < n; j++)
        {
            // Find the smallest element in the unsorted part
            if (arr[j] < arr[index])
                index = j;
        }
        // Swap the found minimum with the first unsorted element
        swap(arr[i], arr[index]);
    }

    // Output the sorted array
    cout << "Sorted Array are: ";
=======
    for (int i = 0; i < n - 1; i++)
    {

        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index])
                index = j;
        }
        swap(arr[i], arr[index]);
    }

    cout<<"Sorted Array are: ";
>>>>>>> 549b0d8 (file update)
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

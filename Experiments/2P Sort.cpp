// Bubble Sort Algorithm
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[8] = {10, 8, 15, 11, 14, 19, 27, 44};
    int n = 8;

    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {

            if (arr[start] > arr[end])
            {
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
            else if (arr[start] < arr[end])
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    // Display sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

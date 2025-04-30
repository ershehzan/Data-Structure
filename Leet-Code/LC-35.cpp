// Leet code 35

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int key)
{
    int start = 0, end = 6, ans, mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    return ans;
    // end here
}

int main()
{
    int arr[1000]={2,4,4,4,4,5,6};
    int key;
    cout << "Enter the number to search : ";
    cin >> key;

    cout << BinarySearch(arr, key) << endl;
    return 0;
}
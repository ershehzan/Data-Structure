#include <iostream>
#include <vector>
using namespace std;

// Function to check if the array can be divided into two subarrays with equal sum
bool divide(vector<int> arr)
{
    int n = arr.size();
    int prefix = 0, total_sum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++)
    {
        total_sum += arr[i];
    }

    // Check if the total sum is even (only even sums can be split equally)
    if (total_sum % 2 != 0)
    {
        cout << "The array cannot be divided into two equal sum subarrays" << endl;
        return false;
    }

    // Calculate the prefix sum and check if it equals half of the total sum at any point
    for (int i = 0; i < n; i++)
    {
        prefix += arr[i];
        // If prefix sum equals half the total sum, a split is possible here
        if (prefix == total_sum / 2)
        {
            cout << "The array can be divided into two equal sum subarrays" << endl;
            return true;
        }
    }

    // If no such prefix is found, the split is not possible
    cout << "The array cannot be divided into two equal sum subarrays" << endl;
    return false;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n; // Read the size of the array

    vector<int> v(n);
    cout << "Enter the elements in array: ";
    // Read all elements into the vector
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // Call the divide function to check if the array can be split
    divide(v);
    return 0;
}

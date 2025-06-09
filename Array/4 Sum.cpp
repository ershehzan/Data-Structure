<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Initialize a vector with unsorted elements
    vector<int> arr = {1, 8, 6, 4, 10, 45};

    int x; // Variable to store the target sum
    cout << "Enter the target sum: ";
    cin >> x;

    int n = arr.size(); // Get the size of the vector

    // Sort the array to use the two-pointer approach effectively
    sort(arr.begin(), arr.end());

    // Loop through each element as the first element of the quadriplet
    for (int i = 0; i < n - 2; i++)
    {
        int target = x - arr[i]; // Needed sum from the remaining three elements
        int k = i + 1;           // Second element's index for the quadriplet
        int start = i + 2;       // Third element's index for the quadriplet
        int end = n - 1;         // Fourth element's index for the quadriplet

        // Use two-pointer technique for the last two elements
        while (start < end)
        {
            int sum = arr[start] + arr[end] + arr[k]; // Calculate the sum of three elements

            if (sum == target)
            {
                // If the sum matches the target, print out the quadriplet and their indices
                cout << "Quadriplet found: [" << arr[i] << ", " << arr[start] << ", " << arr[end] << ", " << arr[k] << "]" << endl;
                cout << "Quadriplet found at Index: [" << i << ", " << start << ", " << end << ", " << k << "]" << endl;
                return 0; // Exit after finding the first valid quadriplet
            }
            else if (sum < target)
            {
                // If sum is less than target, move the 'start' pointer forward to increase the sum
                start++;
            }
            else
            {
                // If sum is greater than target, move the 'end' pointer backward to decrease the sum
                end--;
            }
        }
    }

    // If no quadriplet found, print the message
    cout << "No Quadriplet found." << endl;
    return 0;
}
=======
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Initialize a vector with unsorted elements
    vector<int> arr = {1, 8, 6, 4, 10, 45};

    int x; // Variable to store the target sum
    cout << "Enter the target sum: ";
    cin >> x;

    int n = arr.size(); // Get the size of the vector

    // Sort the array to use the two-pointer approach effectively
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++)
    {
        int target = x - arr[i];
        int k = i + 1;
        int start = i + 2;
        int end = n - 1;

        while (start < end)
        {
            int sum = arr[start] + arr[end] + arr[k];
            if (sum == target)
            {
                cout << "Quadriplet found: [" << arr[i] << ", " << arr[start] << ", " << arr[end] << ", " << arr[k] << "]" << endl;
                cout << "Quadriplet found at Index: [" << i << ", " << start << ", " << end << ", " << k << "]" << endl;
                return 0;
            }
            else if (sum < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    cout << "No Quadriplet found." << endl;
    return 0;
}
>>>>>>> 549b0d8 (file update)

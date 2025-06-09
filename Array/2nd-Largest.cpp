<<<<<<< HEAD
#include <iostream>
#include <climits> // For INT_MIN, representing the minimum integer value
using namespace std;

int main()
{
    // Array to store user input
    int arr[1000];
    int n;
    int ans = INT_MIN; // Initialize largest value to the smallest possible integer

    // Prompt user for the number of elements in the array
    cout << "Enter the index: ";
    cin >> n;

    // Prompt user to enter the elements of the array
    cout << "Enter the Elements: ";
    for (int i = 0; i < n; i++)  // Loop to take 'n' inputs
    {
        cin >> arr[i];
    }

    // Find the largest element in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > ans) // If current element is greater than 'ans', update 'ans'
        {
            ans = arr[i];
        }
    }

    // Find the second largest element in the array
    int sec = INT_MIN; // Initialize second largest to the smallest possible integer
    for (int i = 0; i < n; i++)
    {
        // Check if current element is different from the largest and greater than 'sec'
        if (arr[i] != ans && arr[i] > sec)
        {
            sec = arr[i];
        }
    }

    // Output the results
    cout << "Largest Element is : " << ans << endl;
    cout << "Second Largest Element is : " << sec << endl;
    return 0; // End of program
}
=======
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // Largest
    int arr[1000];
    int n;
    int ans = INT_MIN;
    cout << "Enter the index: ";
    cin >> n;

    cout << "Enter the Elements: ";
    for (int i = 0; i < n; i++)  // Fixed loop condition
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)  // Moved max calculation outside input loop
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }

    // Second Largest
    int sec = INT_MIN;
    for (int i = 0; i < n; i++)  
    {
        if (arr[i] != ans && arr[i] > sec)  
        {
            sec = arr[i];
        }
    }

    cout << "Largest Element is : " << ans << endl;
    cout << "Second Largest Element is : " << sec << endl;
    return 0;
}
>>>>>>> 549b0d8 (file update)

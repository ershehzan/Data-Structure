#include <iostream>
#include <vector>
using namespace std;

// Recursive function to compute the sum of all possible subsets of the array
// arr: input array
// index: current position in the array
// n: total number of elements in the array
// sum: sum of the current subset being considered
// ans: vector to store the sum of each subset
void subsetsum(int arr[], int index, int n, int sum, vector<int>& ans)
{
    // Base case: if we've considered all elements
    if (index == n)
    {
        ans.push_back(sum); // Store the sum of the current subset
        return;
    }

    // Recurse without including the current element
    subsetsum(arr, index + 1, n, sum, ans);

    // Recurse including the current element in the sum
    subsetsum(arr, index + 1, n, sum + arr[index], ans);
}

int main()
{
    int arr[] = {3, 4, 5};             // Example input array
    int n = 3;                         // Number of elements in the array
    vector<int> ans;                   // Vector to store the sums of all subsets

    cout << "The sum of all subsets is: " << endl;
    subsetsum(arr, 0, n, 0, ans);      // Generate all subset sums starting from index 0 and sum 0

    // Print all the subset sums
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

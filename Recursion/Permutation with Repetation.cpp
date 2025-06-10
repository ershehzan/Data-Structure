#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// This function generates all unique permutations with possible repetition in the input array.
// arr: input array (may contain repeated elements)
// ans: stores all unique permutations
// index: current index to fix an element
// n: length of the array to permute
void permute(vector<int> &arr, vector<vector<int>> &ans, int index, int n)
{
    // Base case: if the current index reaches the end, store the permutation
    if (index == n)
    {
        ans.push_back(arr);
        return;
    }

    // Boolean vector to track which values have been used at this recursion depth
    // Offset by +10 to handle negative numbers (if any), assumes values in [-10,10]
    vector<bool> use(21, 0);

    // Try each possible value at the current position
    for (size_t i = index; i < arr.size(); i++)
    {
        // Only use each unique value once per recursion depth
        if (use[arr[i] + 10] == 0)
        {
            swap(arr[i], arr[index]);               // Fix arr[i] at the current index
            permute(arr, ans, index + 1, n);        // Recurse for the next index
            swap(arr[i], arr[index]);               // Backtrack to restore original order
            use[arr[i] + 10] = 1;                   // Mark value as used at this depth
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 2, 1};                // Example input array with repeated elements
    int n = arr.size();
    vector<vector<int>> ans;                        // Stores all unique permutations

    permute(arr, ans, 0, n);                        // Generate permutations

    // Print all unique permutations
    for (size_t i = 0; i < ans.size(); i++) {
        for (size_t j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Power set

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all subsequences (the power set) of the input array
// arr: input array
// index: current position in the array
// n: length of the array
// ans: vector to store all generated subsequences
// temp: current subsequence being built
void subseq(int arr[], int index, int n, vector<vector<int>> &ans, vector<int>& temp)
{
    // Base case: if index reaches the end of the array, store the current subsequence
    if (index == n)
    {
        ans.push_back(temp);
        return;
    }

    // Exclude the current element and move to the next index
    subseq(arr, index + 1, n, ans, temp);

    // Include the current element in the subsequence and move to the next index
    temp.push_back(arr[index]);
    subseq(arr, index + 1, n, ans, temp);
    temp.pop_back(); // Backtrack to remove the last added element
}

int main()
{
    int arr[] = {1, 2, 3};                 // Example input array
    int n = 3;                             // Number of elements in the array
    vector<vector<int>> ans;                // Stores all subsequences (the power set)
    vector<int> temp;                       // Temporary vector to build subsequences

    subseq(arr, 0, n, ans, temp);           // Generate all subsequences

    cout << "The power set is: " << endl;
    // Print all subsequences
    for (size_t i = 0; i < ans.size(); i++)
    {
        for (size_t j = 0; j < ans[i].size(); j++)
        {
            cout << "{" << ans[i][j] << "}, ";
        }
        cout << endl; // Optional: print each subsequence on a new line
    }
}

#include <iostream>
#include <vector>
using namespace std;

// Solution class contains methods to generate all permutations of an array
class Solution {
public:
    // Recursive helper function to generate permutations
    // arr: Current array being permuted
    // ans: Stores all generated permutations
    // index: The current index at which to fix an element
    void permute(vector<int>& arr, vector<vector<int>>& ans, int index) {
        // Base case: If the index has reached the end of the array,
        // store the current permutation in ans
        if (arr.size() == index) {
            ans.push_back(arr); // Save the current permutation
            return;
        }

        // Iterate through all possible choices for the current index
        for (int i = index; i < arr.size(); i++) {
            swap(arr[index], arr[i]);                 // Swap the current element to the "fixed" position
            permute(arr, ans, index + 1);             // Recurse for the next index
            swap(arr[index], arr[i]);                 // Backtrack: Restore the original configuration
        }
    }

    // Main function to be called for generating all permutations
    // Takes the input array nums and returns a vector of all permutations
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;                      // Vector to store all permutations
        permute(nums, ans, 0);                        // Start recursion from index 0
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};                    // Example input array

    // Generate all permutations of the input array
    vector<vector<int>> result = solution.permute(nums);

    cout << "Permutations of the array are:" << endl;
    // Print all generated permutations
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

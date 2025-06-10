#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Recursive function to generate all subsequences (the power set) of the input string
// s: input string
// index: current position in the string
// n: length of the string
// ans: vector to store all generated subsequences
// temp: current subsequence being built
void subseq(string &s, int index, int n, vector<string>& ans, string temp)
{
    // Base case: if index reaches the end of the string, store the current subsequence
    if (index == n)
    {
        ans.push_back(temp);
        return;
    }

    // Exclude the current character and move to the next index
    subseq(s, index + 1, n, ans, temp);

    // Include the current character in the subsequence and move to the next index
    temp.push_back(s[index]);
    subseq(s, index + 1, n, ans, temp);
}

int main()
{
    string s = "abc";              // Example input string
    vector<string> ans;            // Stores all subsequences (the power set)
    string temp = "";              // Temporary string to build subsequences

    subseq(s, 0, s.size(), ans, temp); // Generate all subsequences

    cout << "The power set is: " << endl;
    // Print all subsequences
    for (size_t i = 0; i < ans.size(); i++)
        cout << "{" << ans[i] << "} ";

    return 0;
}

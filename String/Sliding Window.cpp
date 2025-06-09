<<<<<<< HEAD
// GFG (Geeks for Geeks)
#include <bits/stdc++.h> // Include all standard libraries for simplicity
using namespace std;

// Solution class containing the logic for finding the smallest substring
class Solution {
    public:
        // Function to find the length of the smallest substring containing all unique characters of the input string
        int findSubString(string& s) 
        {
            // Vector to store the frequency of each character (ASCII range 0-255)
            vector<int> count(256, 0);

            // Pointers and variables for the sliding window
            int f = 0, sec = 0, len = s.size(); // f: start of window, sec: end of window, len: minimum length
            int dif = 0; // Total number of unique characters in the string

            // Step 1: Count the number of unique characters in the input string
            while (f < s.size())
            {
                if (count[s[f]] == 0) // If the character is encountered for the first time
                    dif++; // Increment the count of unique characters
                count[s[f]]++;
                f++;
            }

            // Step 2: Reset the count array and pointers for the sliding window
            fill(count.begin(), count.end(), 0); // Reset all character counts to 0
            f = 0; // Reset the start pointer
            sec = 0; // Reset the end pointer
            int currDif = 0; // Current number of unique characters in the window

            // Step 3: Use a sliding window to find the smallest substring
            while (sec < s.size())
            {
                // Expand the window until all unique characters are included
                while (currDif < dif && sec < s.size())
                {
                    if (count[s[sec]] == 0) // If a new unique character is added to the window
                        currDif++; // Increment the count of unique characters in the window

                    count[s[sec]]++; // Increment the frequency of the character
                    sec++; // Move the end pointer
                }

                // Shrink the window while it still contains all unique characters
                while (currDif == dif)
                {
                    // Update the minimum length of the substring
                    len = min(len, sec - f);

                    count[s[f]]--; // Decrement the frequency of the character at the start of the window

                    if (count[s[f]] == 0) // If a unique character is removed from the window
                        currDif--; // Decrement the count of unique characters in the window

                    f++; // Move the start pointer
                }
            }

            // Return the length of the smallest substring
            return len;
        }
};

// Driver code to test the solution
int main() {
    int t; // Number of test cases
    cin >> t; // Read the number of test cases
    while (t--) {
        string str; // Input string
        cin >> str; // Read the string
        Solution ob; // Create an object of the Solution class
        cout << ob.findSubString(str) << endl; // Print the length of the smallest substring

        cout << "~" << "\n"; // Separator for output
    }
    return 0; // End of the program
=======
//GFG
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        int findSubString(string& s) 
        {
                vector<int> count(256, 0);
                
                int f = 0, sec = 0, len = s.size();
                int dif = 0;

                // Count number of unique characters in the string
                while (f < s.size())
                {
                        if (count[s[f]] == 0)
                                dif++;
                        count[s[f]]++;
                        f++;
                }

                // Reset count array and pointers for sliding window
                fill(count.begin(), count.end(), 0);
                f = 0;
                sec = 0;
                int currDif = 0;

                while (sec < s.size())
                {
                        while (currDif < dif && sec < s.size())
                        {
                                if (count[s[sec]] == 0)
                                        currDif++;

                                count[s[sec]]++;
                                sec++;
                        }

                        while (currDif == dif)
                        {
                                len = min(len, sec - f);
                                count[s[f]]--;

                                if (count[s[f]] == 0)
                                        currDif--;

                                f++;
                        }
                }

                return len;
        }
};

//{ Driver Code Starts.
//   Driver code
int main() {
        int t;
        cin >> t;
        while (t--) {

                string str;
                cin >> str;
                Solution ob;
                cout << ob.findSubString(str) << endl;

                cout << "~"
                         << "\n";
        }
        return 0;
>>>>>>> 549b0d8 (file update)
}

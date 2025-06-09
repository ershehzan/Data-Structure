<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Solution class encapsulates the algorithm
class Solution {
public:
    // Helper function to compute the LPS (Longest Prefix Suffix) array used in KMP algorithm
    // lps[i] = length of the longest proper prefix which is also a suffix for substring s[0..i]
    void lpsfind(vector<int> &lps, string s) {
        int pre = 0, suf = 1;

        // Build the lps array
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                // Characters match, increment both pointers and update lps
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    // No prefix matches, set lps[suf] to 0 and move to next character
                    lps[suf] = 0;
                    suf++;
                } else {
                    // Fallback to the last prefix length
                    pre = lps[pre - 1];
                }
            }
        }
    }

    // Implementation of KMP (Knuth-Morris-Pratt) substring search algorithm
    // Returns 1 if 'needle' is a substring of 'haystack', else returns 0
    int kmp_match(string haystack, string needle) {
        if (needle.empty()) return 0; // Edge case: empty substring

        // Preprocess the needle to get lps array
        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);

        int first = 0, second = 0; // Pointers for haystack and needle

        // Scan through haystack to look for the needle
        while (first < haystack.size() && second < needle.size()) {
            if (haystack[first] == needle[second]) {
                // Characters match, move both pointers
                first++;
                second++;
            } else {
                if (second == 0)
                    // No partial match, move haystack pointer
                    first++;
                else
                    // Fallback in needle using lps array
                    second = lps[second - 1];
            }
        }

        // If we have matched the entire needle, return 1
        if (second == needle.size())
            return 1;
        else
            return 0;
    }

    // Main function to solve LeetCode 686: Repeated String Match
    // Returns the minimum number of times 'a' must be repeated such that 'b' is a substring
    // If impossible, returns -1
    int repeatedStringMatch(string a, string b) {
        if (a == b)
            return 1; // If both strings are already equal

        int repeat = 1; // At least one repetition
        string temp = a;

        // Repeat string 'a' until its length is at least that of 'b'
        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }

        // Check if 'b' is a substring in the current repeated string using KMP
        if (kmp_match(temp, b) == 1)
            return repeat;

        // Check one more repetition to cover cases where 'b' overlaps repeat boundaries
        if (kmp_match(temp + a, b) == 1)
            return repeat + 1;

        // If still not found, it's impossible
        return -1;
    }
};

int main() {
    Solution solution;
    string a, b;

    cout << "Enter string a: ";
    cin >> a;
    cout << "Enter string b: ";
    cin >> b;

    // Compute and print the result
    int result = solution.repeatedStringMatch(a, b);
    cout << "Result: " << result << endl;

    return 0;
}
=======
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void lpsfind(vector<int> &lps, string s) {
        int pre = 0, suf = 1;

        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }

    int kmp_match(string haystack, string needle) {
        if (needle.empty()) return 0;

        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);

        int first = 0, second = 0;

        while (first < haystack.size() && second < needle.size()) {
            if (haystack[first] == needle[second]) {
                first++;
                second++;
            } else {
                if (second == 0)
                    first++;
                else
                    second = lps[second - 1];
            }
        }

        if (second == needle.size())
            return 1;
        else
            return 0;
    }

    int repeatedStringMatch(string a, string b) {
        if (a == b)
            return 1;

        int repeat = 1;
        string temp = a;

        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }

        // KMP
        if (kmp_match(temp, b) == 1)
            return repeat;

        // temp += a for KMP
        if (kmp_match(temp + a, b) == 1)
            return repeat + 1;

        return -1;
    }
};

int main() {
    Solution solution;
    string a, b;

    cout << "Enter string a: ";
    cin >> a;
    cout << "Enter string b: ";
    cin >> b;

    int result = solution.repeatedStringMatch(a, b);
    cout << "Result: " << result << endl;

    return 0;
}
>>>>>>> 549b0d8 (file update)

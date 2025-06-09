#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    // Function to check if a string can be obtained by rotating
    // another string by exactly 2 places.
<<<<<<< HEAD

    // Helper function to perform an anti-clockwise rotation by 1 place.
=======
    
>>>>>>> 549b0d8 (file update)
    void racw(string &s) {
        char n = s[0]; // Store the first character
        int index = 1;

<<<<<<< HEAD
        // Shift all characters one position to the left
        while (index < s.size()) {
            s[index - 1] = s[index]; // Move current character to the previous position
=======
        while (index < s.size()) {
            s[index - 1] = s[index]; // Shift characters left
>>>>>>> 549b0d8 (file update)
            index++;
        }
        s[s.size() - 1] = n; // Move the first character to the last position
    }
    
<<<<<<< HEAD
    // Helper function to perform a clockwise rotation by 1 place.
    void rcw(string &s) {
        char n = s[s.size() - 1]; // Store the last character
        int index = s.size() - 2;

        // Shift all characters one position to the right
        while (index >= 0) {
            s[index + 1] = s[index]; // Move current character to the next position
            index--;
        }
        s[0] = n; // Move the last character to the first position
    }
    
    // Main function to check if `s2` is a rotated version of `s1` by exactly 2 places.
    bool isRotated(string& s1, string& s2) {
        // If the sizes of the strings are different, it is not possible for one to be a rotation of the other.
        if (s1.size() != s2.size())
            return false;

        string cw, acw; // Strings to store clockwise and anti-clockwise rotations.

        // Perform two clockwise rotations on `s1`.
        cw = s1;
        rcw(cw);
        rcw(cw);

        // Check if the clockwise rotated string matches `s2`.
        if (cw == s2)
            return true;

        // Perform two anti-clockwise rotations on `s1`.
        acw = s1;
        racw(acw);
        racw(acw);

        // Check if the anti-clockwise rotated string matches `s2`.
        if (acw == s2)
            return true;

        // If neither rotation matches, return false.
=======
    void rcw(string &s) {
        char n = s[s.size() - 1];
        int index = s.size() - 2;

        while (index >= 0) {
            s[index + 1] = s[index];
            index--;
        }
        s[0] = n;
    }
    
    bool isRotated(string& s1, string& s2) {
        if (s1.size() != s2.size())
            return false;

        string cw, acw;
        // clockwise
        cw = s1;

        rcw(cw);
        rcw(cw);

        if (cw == s2)
            return true;

        // Anticlockwise
        acw = s1;

        racw(acw);
        racw(acw);

        if (acw == s2)
            return true;

>>>>>>> 549b0d8 (file update)
        return false;
    }
};

int main() {
    Solution solution;

<<<<<<< HEAD
    // Input strings
    string s1 = "amazon"; // Original string
    string s2 = "azonam"; // Target string to check for rotation

    // Check if `s2` is a 2-place rotation of `s1`
=======
    string s1 = "amazon";
    string s2 = "azonam";

>>>>>>> 549b0d8 (file update)
    if (solution.isRotated(s1, s2)) {
        cout << s2 << " is a rotated version of " << s1 << " by 2 places." << endl;
    } else {
        cout << s2 << " is not a rotated version of " << s1 << " by 2 places." << endl;
    }

    return 0;
}

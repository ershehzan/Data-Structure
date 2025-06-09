<<<<<<< HEAD
#include <iostream>  // Include the input-output stream library
#include <string>    // Include the string library for handling string operations
#include <vector>    // Include the vector library for dynamic arrays
using namespace std;

// Function to sort a string in alphabetical order
// Parameters:
// s - the input string to be sorted
// Returns: the sorted string in ascending alphabetical order
string sort(string s) {
    vector<int> alpha(26, 0); // Vector to count the frequency of each letter (a-z), initialized to 0

    // Step 1: Count the occurrences of each character in the string
    for (int i = 0; i < s.size(); i++) {
        alpha[s[i] - 'a']++; // Increment the count for the character at position (s[i] - 'a')
    }

    string ans; // String to store the sorted result

    // Step 2: Construct the sorted string using the frequency array
    for (int i = 0; i < 26; i++) { // Loop through each letter from 'a' to 'z'
        char c = 'a' + i; // Convert the current index to the corresponding character

        while (alpha[i]) { // If the character appears in the input string
            ans += c;      // Append the character to the result string
            alpha[i]--;    // Decrement the count for the character
        }
    }

    return ans; // Return the sorted string
}

int main() {
    string input; // Variable to store the input string
    cout << "Enter a string: "; // Prompt the user for input
    cin >> input; // Read the input string from the user

    // Call the sort function to sort the input string
    string sortedString = sort(input);

    // Display the sorted string
    cout << "Sorted string: " << sortedString << endl;

    return 0; // End of the program
}
=======
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string sort(string s) {
    //complete the function here
    vector<int> alpha(26, 0);

    for (int i = 0; i < s.size(); i++) {
        alpha[s[i] - 'a']++;
    }

    string ans;

    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;

        while (alpha[i]) {
            ans += c;
            alpha[i]--;
        }
    }
    return ans;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string sortedString = sort(input);
    cout << "Sorted string: " << sortedString << endl;

    return 0;
}
>>>>>>> 549b0d8 (file update)

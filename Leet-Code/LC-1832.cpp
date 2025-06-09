<<<<<<< HEAD
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solution class containing the pangram checker function
class Solution
{
public:
    // Function to check if a string is a pangram (contains every letter a-z at least once)
    bool checkIfPangram(string sentence)
    {
        // Create a vector of size 26 (for each letter of the alphabet), initialized to 0 (false)
        vector<bool> alpha(26, 0);

        // Iterate over each character in the sentence
        for (int i = 0; i < sentence.size(); i++)
        {
            // Mark the corresponding letter as seen by setting its value to 1 (true)
            // 'a' maps to index 0, 'b' to 1, ..., 'z' to 25
            alpha[sentence[i] - 'a'] = 1;
        }

        // Check if any letter was not seen in the sentence
        for (int i = 0; i < 26; i++)
        {
            // If any letter is missing (still 0), the sentence is not a pangram
            if (alpha[i] == 0)
                return 0; // Return false
        }

        // All letters were present, so the sentence is a pangram
        return 1; // Return true
    }
};

int main()
{
    Solution solution;
    string sentence;

    // Prompt the user to enter a sentence
    cout << "Enter a sentence: ";
    getline(cin, sentence); // Read the full line including spaces

    // Call the pangram checker and display the result
    if (solution.checkIfPangram(sentence))
    {
        cout << "The sentence is a pangram." << endl;
    }
    else
    {
        cout << "The sentence is not a pangram." << endl;
    }

    return 0;
}
=======
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
// start here
        vector<bool> alpha(26, 0);

        for (int i = 0; i < sentence.size(); i++)
        {
            alpha[sentence[i] - 'a'] = 1;
        }

        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] == 0)
                return 0;
        }

        return 1;
        // end here
    }
};

int main()
{
    Solution solution;
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    if (solution.checkIfPangram(sentence))
    {
        cout << "The sentence is a pangram." << endl;
    }
    else
    {
        cout << "The sentence is not a pangram." << endl;
    }

    return 0;
}
>>>>>>> 549b0d8 (file update)

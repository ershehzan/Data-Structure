#include <iostream>
using namespace std;

// Solution class to provide the defanging functionality
class Solution
{
public:
    // Function to defang an IP address by replacing '.' with '[.]'
    string lc(string address)
    {
        // Initialize an empty string to build the answer
        string ans;
        size_t index = 0;

        // Iterate through each character in the input string
        while (index < address.size())
        {
            if (address[index] == '.')
            {
                // If the character is '.', append "[.]" to the answer
                ans += "[.]";
            }
            else
            {
                // Otherwise, append the character as-is
                ans += address[index];
            }
            index++; // Move to the next character
        }
        // Return the defanged IP address
        return ans;
    }
};

int main()
{
    Solution solution;
    string ipAddress;

    // Taking user input for the IP address
    cout << "Enter an IP address: ";
    cin >> ipAddress;

    // Call the defang function and display the result
    string lc = solution.lc(ipAddress);
    cout << "Defanged IP Address: " << lc << endl;

    return 0;
}

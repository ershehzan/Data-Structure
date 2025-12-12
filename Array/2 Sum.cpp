#include <iostream>
using namespace std;

int main() {

    // Initialize an array with some integers (sorted order)
    int arr[1000] = {3, 4, 6, 8, 11, 12, 34, 41}; // Array to store elements
    int n = 8, target; // n is the number of elements in the array
    // Prompt the user to enter the target sum value
    cout << "Enter the target: ";
    cin >> target; //target
    // Initialize two pointers: 'start' at the beginning and 'end' at the end of the array
    int start = 0, end = n - 1;

    // Two-pointer approach to find a pair of numbers that sum up to the target
    while (start < end) {
        int sum = arr[start] + arr[end]; // Calculate the sum of the two pointed elements

        if (sum == target) {
            // If the sum matches the target, output the pair and their indices
            cout << "Pair found: [" << arr[start] << "," << arr[end] << "]" << endl;
            cout << "Pair found at Index: [" << start << "," << end << "]" << endl;
            return 0; // Exit the program after finding the first matching pair
        } else if (sum > target) {
            // If the sum is greater than the target, move the 'end' pointer left to decrease the sum
            end--;
        } else {
            // If the sum is less than the target, move the 'start' pointer right to increase the sum
         
            start++;
        }
    }

    // If no pair is found after checking all possibilities, print a message
    cout << "No pairs found." << endl;
 
    return 0;//return 
}



















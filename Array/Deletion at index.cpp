#include <iostream>
using namespace std;

// Function to delete an element at a specific index from the array
// arr[]: The array from which an element will be deleted
// size: Reference to the current size of the array (will be updated)
// index: The position at which the element should be deleted
void deleteElement(int arr[], int &size, int index) {
    // Check if the provided index is within the valid range
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return; // Exit function if index is invalid
    }
    // Shift elements to the left from 'index' to 'size - 2'
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; // Reduce array size by 1 to reflect the deletion
}

int main() {
    // Initialize an array with 5 elements
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in arr
    int index; // Variable to store the index to be deleted

    // Prompt the user to enter the index of the element to delete
    cout << "Enter the index to delete: ";
    cin >> index;

    // Call the function to delete the element at the provided index
    deleteElement(arr, size, index);

    // Output the updated array after deletion
    cout << "Updated array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Print each element separated by a space
    }
    cout << endl;

    return 0; // End of the program
}

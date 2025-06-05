#include <iostream>
using namespace std;

int main() {
    int arr[10] = {2, 3, 4, 5, 6};  // Initial array with 5 elements, capacity for up to 10
    int n = 5;  // Current number of elements in the array
    int newElement; // Variable to store the new element to be inserted

    // Prompt the user to enter the element to insert at the beginning
    cout << "Enter the element to insert at the beginning: ";
    cin >> newElement;

    int previous = arr[0]; // Store the current first element to shift it right
    arr[0] = newElement;   // Insert the new element at the first position

    // Shift the remaining elements one position to the right
    for (int i = 1; i <= n; i++) {
        int temp = arr[i];    // Store the current element before overwriting
        arr[i] = previous;    // Place the previous element at current position
        previous = temp;      // Update previous for the next iteration
    }

    n++; // Increment the element count after insertion

    // Output the updated array
    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

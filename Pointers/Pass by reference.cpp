#include <iostream>
using namespace std;

// Function to swap the values of two integers using pass by reference
void swap(int &p1, int &p2) // pass by reference
{
    int temp = p1; // Store the value of p1 in a temporary variable
    p1 = p2;       // Assign the value of p2 to p1
    p2 = temp;     // Assign the temporary value to p2
}

int main()
{
    int a = 10, b = 20; // Initialize two integers a and b

    // Call the swap function by passing the variables directly
    swap(a, b);

    // Print the swapped values of a and b
    cout << "a = " << a << endl; // a = 20
    cout << "b = " << b << endl; // b = 10

    return 0; // Indicate that the program ended successfully
}

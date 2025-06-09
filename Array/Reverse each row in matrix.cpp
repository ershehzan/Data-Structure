<<<<<<< HEAD
#include <iostream>
using namespace std;

int main()
{
    // Declare and initialize a 4x4 matrix
    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    // Loop over each row of the matrix
    for (int i = 0; i < 4; i++)
    {
        // Set up two pointers for the start and end of the row
        int start = 0, end = 3;

        // Swap elements from both ends of the row moving towards the center
        while (start < end)
        {
            swap(arr[i][start], arr[i][end]); // Swap the elements at 'start' and 'end'
            start++;  // Move 'start' pointer forward
            end--;    // Move 'end' pointer backward
        }
    }

    // Output the matrix after reversing each row
    cout << "Reversed matrix: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " "; // Print each element in the row
        }
        cout << endl; // Move to the next line after printing each row
    }

    return 0;
}
=======
#include <iostream>
using namespace std;

int main()
{

    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};

    for (int i = 0; i < 4; i++)
    {
        int start = 0, end = 3;

        while (start < end)
        {
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }
    cout << "Reversed matrix: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
>>>>>>> 549b0d8 (file update)

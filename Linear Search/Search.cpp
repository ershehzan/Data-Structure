#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {20, 54, 32, 6, 7, 84, 91, 8, 9, 10};
    int x = -1; // Default to -1 to indicate "not found"
    int target;

    cout << "Enter the target value: ";
    cin >> target;

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == target)
        {
            x = i; // Store the index where the target is found
            break; // Exit the loop once the target is found
        }
    }

    if (x != -1)
    {
        cout << "Target found at index: " << x << endl;
    }
    else
    {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}

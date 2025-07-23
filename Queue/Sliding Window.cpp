#include <iostream>
#include <queue>
using namespace std;

// Function to display the contents of the queue (current sliding window)
void display(queue<int> q)
{
    cout << "Sliding Window: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    int arr[100];
    int n, k;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the size of the sliding window: ";
    cin >> k;

    // Edge case check
    if (k > n || k <= 0)
    {
        cout << "Invalid window size!" << endl;
        return 0;
    }

    queue<int> q;

    // Initialize the first window (k - 1 elements)
    for (int i = 0; i < k - 1; i++)
    {
        q.push(arr[i]);
    }

    // Slide the window through the array
    for (int i = k - 1; i < n; i++)
    {
        q.push(arr[i]);    // Add the next element to the window
        display(q);        // Display current window
        q.pop();           // Remove the element that is sliding out
    }

    return 0;
}

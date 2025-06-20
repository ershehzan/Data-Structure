// First come first serve (FCFS) disk scheduling algorithm: 
// The FCFS disk scheduling algorithm is a simple and straightforward approach to managing disk requests.
// It processes requests in the order they arrive, without reordering or optimization.

#include <algorithm> // Not used in this program, but included by default
#include <iostream>  // Required for input and output operations
#include <cmath>     // Required for abs() function to calculate absolute difference

using namespace std;

int main()
{
    int arr[100];   // Array to store the disk request queue (maximum 100 requests)
    int n, head;    // 'n' holds the number of disk requests, 'head' is the initial position of the disk head

    // Prompt the user to enter the number of disk requests
    cout << "Enter the number of requests: ";
    cin >> n;

    // Prompt the user to enter each disk request (track numbers)
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Store each request in the array
    }

    // Prompt the user to enter the initial head (current disk position)
    cout << "Enter the head position: ";
    cin >> head;

    int SeekTime = 0; // Variable to store the total seek time (total head movement)

    // Process each request in the order received (FCFS)
    for (int i = 0; i < n; i++)
    {
        // Calculate the distance between the current head and the requested track
        SeekTime += abs(arr[i] - head);

        // Update the head position to the current requested track
        head = arr[i];
    }

    // Output the total seek time after processing all requests
    cout << "Total seek time (FCFS): " << SeekTime << endl;

    return 0; // Indicate successful program termination
}

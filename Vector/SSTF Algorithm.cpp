// SSTF (Shortest Seek Time First) Disk Scheduling Algorithm
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int arr[100];    // Array to store disk requests
    int n, head;     // n = number of requests, head = initial head position

    // Input: number of requests
    cout << "Enter the number of requests: ";
    cin >> n;

    // Input: disk requests
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Input: initial head position
    cout << "Enter the head position: ";
    cin >> head;

    // Sort the requests in ascending order
    sort(begin(arr), begin(arr) + n);

    int Seek_time = 0; // Stores the total seek time

    // Calculate total seek time:
    // - Move from head to the smallest request (arr[0])
    // - Then from smallest to largest request (arr[n-1])
    Seek_time += head - arr[0] + arr[n - 1] - arr[0];

    cout << "Total seek time (SSTF): " << Seek_time << endl;

    return 0;
}

// Book Allocation Problem
// This program attempts to allocate books to students such that the maximum number of pages assigned to a student is minimized.

#include <iostream> // Include the iostream library for input and output operations
using namespace std;

int main()
{
    int n; // Variable to store the number of students
    cout << "Enter a number: ";
    cin >> n;

    // Array representing the number of pages in each book
    int arr[1000] = {12, 36, 67, 90}; // Example book pages

    // Initialize the binary search range
    int start = 0, end = 3, mid, ans;

    // Perform binary search to find the optimal allocation
    while (start <= end)
    {
        mid = start + (end - start) / 2; // Calculate the mid-point to avoid overflow
        int page = 0, count = 1; // Variables to track the current page sum and student count

        // Check the allocation for the current mid value
        for (int i = 0; i < n; i++)
        {
            if (start < arr[i]) // Ensure the start value is at least the maximum book pages
            {
                start = arr[i];
                end += arr[i];
            }

            page += arr[i]; // Add book pages to the current allocation

            if (page > mid) // If the current allocation exceeds the mid value
            {
                count++; // Assign the book to the next student
                page = arr[i]; // Start a new allocation
            }
        }

        // Check if the current allocation is valid
        if (count <= n)
        {
            ans = mid;      // Update the answer with the current mid value
            end = mid - 1;  // Narrow the search space to the left
        }
        else
        {
            start = mid + 1; // Narrow the search space to the right
        }
    }

    // Output the result
    cout << " " << ans;

    return 0; // Indicate successful program execution
}

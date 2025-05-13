#include <iostream> // Include the iostream library for input and output operations
#include <climits>  // Include the climits library for using INT_MAX
using namespace std;

// Function to check if it's possible to allocate books among 'students' such that 
// no student reads more than 'maxPages'
bool isPossible(int arr[], int n, int students, int maxPages) {
    int studentCount = 1, pagesSum = 0; // Initialize student count and current page sum

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages, allocation is not possible
        if (arr[i] > maxPages)  
            return false;

        // If adding this book exceeds maxPages, allocate to the next student
        if (pagesSum + arr[i] > maxPages) { 
            studentCount++;         // Increment student count
            pagesSum = arr[i];      // Start allocation for the next student
            
            // If more students are required than available, allocation is not possible
            if (studentCount > students) 
                return false;
        } else {
            pagesSum += arr[i]; // Add book pages to the current student's total allocation
        }
    }

    // If allocation is possible within the given constraints, return true
    return true; 
}

// Function to find the minimum possible maximum pages allocated to a student
int findPages(int arr[], int n, int students) {
    // If there are more students than books, allocation is impossible
    if (students > n) 
        return -1;

    // Initialize the binary search range
    int start = INT_MAX, end = 0; 
    for (int i = 0; i < n; i++) {
        start = min(start, arr[i]); // The starting point is the maximum pages in a single book
        end += arr[i]; // The endpoint is the total sum of pages across all books
    }

    int ans = -1; // Variable to store the result
    while (start <= end) {
        int mid = start + (end - start) / 2; // Calculate the mid-point

        // Check if it's possible to allocate books with the current 'mid' as maxPages
        if (isPossible(arr, n, students, mid)) { 
            ans = mid;       // Store the potential answer
            end = mid - 1;   // Try for a better (smaller) answer
        } else {
            start = mid + 1; // Increase maxPages to search again
        }
    }

    return ans; // Return the minimum maximum pages allocated
}

int main() {
    int n, students; // Variables for the number of books and students
    
    // Input the number of books
    cout << "Enter number of books: ";
    cin >> n;
    
    int arr[n]; // Array to store the number of pages in each book
    cout << "Enter number of pages in each book: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Input the number of students
    cout << "Enter number of students: ";
    cin >> students;

    // Find the minimum maximum pages allocated
    int result = findPages(arr, n, students);

    // Output the result
    if (result == -1)
        cout << "Book allocation is not possible!" << endl; // Allocation is not possible
    else
        cout << "Minimum maximum pages allocated: " << result << endl; // Display the result

    return 0; // Indicate successful program execution
}

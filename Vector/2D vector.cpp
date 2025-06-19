#include<iostream>      // Include input/output stream for cin and cout
#include<vector>        // Include the vector container from STL
#include<algorithm>     // Include algorithm library (not used in current code)
using namespace std;

int main(){
    int n, m; // Variables to store number of rows (n) and columns (m) for the 2D vector

    // Prompt the user to enter the size of the matrix
    cout << "Enter the number of rows and columns";
    cin >> n >> m; // Read user input for rows and columns

    // Initialize a 2D vector (matrix) with n rows and m columns, filled with value 1
    vector<vector<int>> matrix(n, vector<int>(m, 1));

    // --- (Commented) Example code to print the matrix and its dimensions ---
    // for(int i = 0; i < 3; i++){
    //     for(int j = 0; j < 3; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    // }
    // cout << "Rows" << matrix.size();
    // cout << "col" << matrix[0].size();
    // ----------------------------------------------------------------------

    // Input the elements of the matrix from the user
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j]; // Store input in matrix at position (i, j)
        }
    }

    // Output the elements of the matrix row by row
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " "; // Print each element followed by a space
        }
    }
    cout << endl; // Print a newline at the end

    // End of program
}

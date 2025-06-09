<<<<<<< HEAD
// Program demonstrating the usage of a 2D vector in C++
#include <iostream>  // Include library for input-output operations
#include <vector>    // Include library for using the vector container
#include <algorithm> // Optionally include for algorithms (not used in this code)
using namespace std; // Use the standard namespace to simplify code

int main() {
    // Declare variables to store the dimensions of the 2D vector
    int n, m;

    // Prompt the user to enter the number of rows and columns for the 2D vector
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m; // Take input for rows (n) and columns (m)

    /*
     * Initialize a 2D vector named `matrix` with dimensions `n` x `m`.
     * Each element is initialized to 1 as the default value.
     */
    vector<vector<int>> matrix(n, vector<int>(m, 1));

    /*
     * Uncommented Section: This block of code can be used to display the size of the 2D vector
     * and the initialized elements (all set to 1 by default).
     * 
     * for(int i = 0; i < 3; i++) {
     *     for(int j = 0; j < 3; j++) {
     *         cout << matrix[i][j] << " "; // Display each element in the 2D vector
     *     }
     * }
     * cout << "Rows: " << matrix.size();  // Output the number of rows in the matrix
     * cout << "Columns: " << matrix[0].size(); // Output the number of columns in the matrix
     */

    // Input section: Populate the 2D vector with user-provided values
    for (int i = 0; i < n; i++) { // Iterate through each row
        for (int j = 0; j < m; j++) { // Iterate through each column
            cin >> matrix[i][j]; // Take input for each element of the 2D vector
        }
    }

    // Output section: Display the elements of the 2D vector
    for (int i = 0; i < n; i++) { // Iterate through each row
        for (int j = 0; j < m; j++) { // Iterate through each column
            cout << matrix[i][j] << " "; // Output each element separated by a space
        }
    }
    cout << endl; // End the output with a newline for better formatting

    return 0; // Indicate successful program termination
}
=======
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of rows and columns";
    cin>>n>>m;

    vector<vector<int>>matrix(n,vector<int>(m,1));


// for(int i=0;i<3;i++){
//     for(int j=0;j<3;j++){
//         cout<<matrix[i][j]<<" ";
//     }
// }
// cout<<"Rows"<<matrix.size();

// cout<<"col"<<matrix[0].size();

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>matrix[i][j];
    }
}


for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cout<<matrix[i][j]<<" ";
    }
}
cout<<endl;
}
>>>>>>> 549b0d8 (file update)

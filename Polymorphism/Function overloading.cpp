<<<<<<< HEAD
#include <iostream>  // Include the input-output stream library for cout and endl
using namespace std; // Use the standard namespace

// Function to add two integers
int add(int a, int b)
{
    return a + b; // Return the sum of two integers
}

// Function to add two double values (overloaded function)
double add(double a, double b)
{
    return a + b; // Return the sum of two doubles
=======
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
>>>>>>> 549b0d8 (file update)
}

int main()
{
<<<<<<< HEAD
    cout << "Function overloading: " << endl; // Print a heading

    cout << "Integer addition: ";             // Print label for integer addition
    cout << add(1, 2) << endl;                // Call add(int, int) and print result

    cout << "Double addition: ";              // Print label for double addition
    cout << add(1.1, 2.2) << endl;            // Call add(double, double) and print result

    // The compiler automatically selects the correct function based on argument types
}
=======
    cout<<"Function overloading: "<<endl;
    cout<<"Integer addition: ";
    cout << add(1, 2) << endl;
    cout<<"Double addition: ";
    cout << add(1.1, 2.2) << endl;
}
>>>>>>> 549b0d8 (file update)

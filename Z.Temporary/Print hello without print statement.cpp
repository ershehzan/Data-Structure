#include <iostream>   // for standard input/output streams like cerr
#include <sstream>    // for string stream classes like ostringstream

using namespace std;

int main() {
    // Create an output string stream object 'oss'.
    // This behaves like an output stream but stores the output in a string buffer.
    ostringstream out;

    // Use the insertion operator '<<' to write "Hello\n" into the string stream buffer.
    // The characters are not printed yet; they are stored inside 'oss'.
   out << "HELLO!!!";

    // Retrieve the string stored inside 'oss' using the str() method.
    // This returns a std::string containing "Hello\n".
    // Then send this string to the standard error stream 'cerr'.
    // 'cerr' is typically used for error messages, and it outputs immediately.
    cerr << out.str();

    // Return 0 to indicate successful execution of the program.
    return 0;
}

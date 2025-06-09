#include <fstream>
using namespace std;
int main() {
   ofstream print("output.txt");
    print << "Hello\n";
    return 0;
}

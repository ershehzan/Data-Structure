#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[8] = {10, 8, 15, 11, 14, 19, 27, 44};
    int n = 8;

    int start = 0, end = n - 1;

    while (start < end) {

        // Move largest to the right
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
        end--;

        // Move smallest to the left
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
            }
        }
        start++;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}

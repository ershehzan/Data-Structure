#include <iostream>
#include <vector>
using namespace std;

// Solution class that handles heap operations
class Solution {
  public:

  // Function to heapify a subtree rooted at index in a vector 'ans' of size 'n'
  void heapify(vector<int>& ans, int index, int n) {
      int largest = index;

      while (index < n) {
          int left = 2 * index + 1;   // Left child index
          int right = 2 * index + 2;  // Right child index
          
          // If left child exists and is greater than the current largest
          if (left < n && ans[left] > ans[largest]) {
              largest = left;
          }

          // If right child exists and is greater than the current largest
          if (right < n && ans[right] > ans[largest]) {
              largest = right;
          }

          // If either child is greater, swap and continue heapifying
          if (largest != index) {
              swap(ans[largest], ans[index]);
              index = largest;  // Move index to where swap happened and continue
          } 
          else {
              break;  // Heap property is satisfied, stop
          }
      }
  }

  // Function to merge two max heaps and return the resulting max heap
  vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
      vector<int> ans;

      // Step 1: Combine elements of both heaps into a single array
      for (int i = 0; i < n; i++)
          ans.push_back(a[i]);
      for (int i = 0; i < m; i++)
          ans.push_back(b[i]);

      // Step 2: Convert the merged array into a max heap
      // Start heapifying from the last non-leaf node down to the root
      int size = ans.size();
      for (int i = size / 2 - 1; i >= 0; i--) {
          heapify(ans, i, size);
      }

      return ans;  // Return the final merged max heap
  }
};

int main() {
    // Sample input max heaps (represented as arrays)
    vector<int> heap1 = {10, 5, 6};  // Valid max heap
    vector<int> heap2 = {7, 9};      // Valid max heap
    int n = heap1.size();
    int m = heap2.size();

    Solution obj;

    // Merge the two heaps
    vector<int> mergedHeap = obj.mergeHeaps(heap1, heap2, n, m);

    // Print the result
    cout << "Merged Max Heap: ";
    for (int val : mergedHeap) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Unordered Set does not allow duplicate elements
// It is implemented as a hash table
// It does not store elements in sorted order
// It provides average constant time complexity for insertion, deletion, and search operations
// O(1) for average case, O(n) for worst case for all operations

int main()
{
unordered_set<int>us;

us.insert(1);
us.insert(2);
us.insert(3);
us.insert(4);
us.insert(5);


cout << "Unordered Set elements: ";
for (auto i = us.begin(); i != us.end(); ++i) {
    cout << *i << " ";
}
cout << endl;
   
    
}
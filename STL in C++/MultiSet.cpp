#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Multiset allows duplicate elements
// It is implemented as a balanced binary search tree
// It stores elements in sorted order
// It provides logarithmic time complexity for insertion, deletion, and search operations
// Implement using AVL or Red-Black tree

int main()
{

    multiset<int> ms;

    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);
    ms.insert(5);
    ms.insert(5); // Duplicate element

    ms.insert(6);
    ms.insert(7);
    ms.insert(8);

    cout << "Multiset elements: ";
    for (auto i = ms.begin(); i != ms.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}
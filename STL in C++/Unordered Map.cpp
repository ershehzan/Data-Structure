#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Unordered Map does not allow duplicate keys
// It is implemented as a hash table
// It does not store elements in sorted order
// It provides average constant time complexity for insertion, deletion, and search operations
// O(1) for average case, O(n) for worst case for all operations

int main()
{
    unordered_map<string, int> um;

    um["apple"] = 10;
    um["banana"] = 20;
    um["cherry"] = 30;
    um["date"] = 40;
    um["elderberry"] = 50;
    cout << "Unordered Map elements: " << endl;
    for (auto i = um.begin(); i != um.end(); ++i)
    {

        cout << "Key: " << i->first << ", Value: " << i->second << endl;
    }
}
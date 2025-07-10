#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // pair<string, int> p;
    // // Two ways to initialize a pair
    // p = make_pair("Hello", 1);
    // p.first = "World";
    // p.second = 2;

    // cout << p.first << endl;
    // cout << p.second << endl;
    // to Store 3 pairs
    pair<string, pair<int, int>> p2;
    p2 = make_pair("Hello", make_pair(1, 2));
    cout << p2.first << endl;
    cout << p2.second.first << endl;
    cout << p2.second.second << endl;
    // to Store 3 pairs
    
}
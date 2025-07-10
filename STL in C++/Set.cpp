#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    set<int> s;

//TO store data in Decending order, use greater<int>()
set<int,greater<int>>s1;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    cout << "Set elements: ";
    for (auto i = s.begin(); i != s.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
    
    if(s.find(6)!=s.end())
    cout << "6 is present in the set" << endl;
    else
    cout << "6 is not present in the set" << endl;

}
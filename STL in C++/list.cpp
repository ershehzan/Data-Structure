#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<int>l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);

    cout << "List elements: ";
    cout<<l1.front()<<" ";
    cout<<l1.back()<<" ";
    for(auto i = l1.begin(); i != l1.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
    l1.pop_back();
    l1.pop_front();
    

    
}
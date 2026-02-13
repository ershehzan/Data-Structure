// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     // pair<string, int> p;
//     // // Two ways to initialize a pair
//     // p = make_pair("Hello", 1);
//     // p.first = "World";
//     // p.second = 2;

//     // cout << p.first << endl;
//     // cout << p.second << endl;
//     // to Store 3 pairs
//     pair<string, pair<int, int>> p2;
//     p2 = make_pair("Hello", make_pair(1, 2));
//     cout << p2.first << endl;
//     cout << p2.second.first << endl;
//     cout << p2.second.second << endl;
//     // to Store 3 pairs
    

    
// }
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    
    // pair<int,pair<int,int>>p{10,{20,60}};
    // cout<<p.first<<" "<<p.second.first<< " "<<p.second.second;
    
    pair<int,int>arr[100];
    int n;
    cout<<"Enter a number:";
    cin>>n;
    cout<<"Enter elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    
   for(int i=0;i<n;i++)
   {
       cout<<"{"<<arr[i].first<<","<<arr[i].second<<"}"<<endl;
   }
   
   cout<<"Size of array :"<<n;

    return 0;
}
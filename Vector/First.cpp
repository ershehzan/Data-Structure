#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{

    // vector<int>v={1,2,3,4,5};
    // vector<int> v = {0, 2, 3, 4, 5, 8};
    // // v.push_back(4);
    // // v.push_back(3);
    // // v.push_back(40);
    // // v.push_back(31);
    // // v.push_back(41);
    // // v.push_back(34);
    // // v.push_back(0);
    // // v.push_back(1);
    // // v.pop_back();

    // //v.erase(v.begin() + 1);
    // v.insert(v.begin() + 1, 4);
    // for (i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // v.clear();//remove all the elements
    // cout << "\nSize of v: " << v.size();
    // cout << "\ncapacity of v: " << v.capacity();

    // vector<int>arr;

    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(4);

    // // cout<<arr[0]<<endl;
    // // cout<<arr.size()-1<<endl;

    // // cout<<arr.front()<<endl;
    // // cout<<arr.back()<<endl;

    // // vector<int>a;

    // //Copy Value of 1 to other
    // // a=arr;
    // // cout<<a.size();
    // // cout<<endl;

    // for(auto it=arr.begin();it!=arr.end();it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    // for(auto i:arr){
    //     cout<<i<<" ";
    // }

    vector<int> ans;

    ans.push_back(10);
    ans.push_back(23);
    ans.push_back(3);
    ans.push_back(14);
    ans.push_back(0);
    ans.push_back(2);
    ans.push_back(32);
    ans.push_back(4);

    // sort in increasing order
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size() - 1; i++)
    {

        cout << ans[i] << " ";
    }

    cout << endl;

    // sort in decreasing order
    // sort(ans.begin(), ans.end(), greater<int>());

    // cout << "Sorted : " << endl;
    // for (int i = 0; i < ans.size() - 1; i++)
    // {

    //     cout << ans[i] << " ";
    // }

    // Binary search
    cout << binary_search(ans.begin(), ans.end(), 2);


    cout<<endl;

    // for index
    cout<<find(ans.begin(), ans.end(),4 )-ans.begin();

    return 0;
}
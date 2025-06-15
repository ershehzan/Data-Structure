#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int display(queue<int> q)
{

    while (!q.empty())
    {
        if (q.front() < 0)
        {
            return q.front();
        }

        q.pop();
    }
    return 0; // Return 0 if no negative number is found
};

int main()
{
    int arr[100];
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the size of the sliding window: ";
    cin >> k;

    queue<int> q;

    for (int i = 0; i < k - 1; i++)
    {
        q.push(arr[i]);
    }
    vector<int> ans;
    for (int i = k - 1; i < n; i++)
    {
        q.push(arr[i]);
        ans.push_back(display(q));
        q.pop();
    }

    cout << "First negative number in each sliding window: ";
    for (size_t i = 0; i < ans.size(); i++)
    {
        if (ans[i] != 0)
        {
            cout << ans[i] << " ";
        }
        else
        {
            cout << "No negative number in this window ";
        }
    }
    return 0;
}
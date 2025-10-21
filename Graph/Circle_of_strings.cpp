#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    void DFS(int node, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        for (int j = 0; j < adj[node].size(); j++)
        {
            if (!vis[adj[node][j]])
                DFS(adj[node][j], adj, vis);
        }
    }

    int isCircle(vector<string> &arr)   {
        int n = arr.size();
        vector<int> adj[26];
        vector<int> Indeg(26, 0), Outdeg(26, 0), vis(26, 0);

        for (int i = 0; i < n; i++)
        {
            string temp = arr[i];
            int u = temp[0] - 'a';
            int v = temp[temp.size() - 1] - 'a';
            adj[u].push_back(v);
            Indeg[v]++;
            Outdeg[u]++;
        }

        for (int i = 0; i < 26; i++)  {
            if (Indeg[i] != Outdeg[i])
                return 0;
        }

        int node = -1;
        for (int i = 0; i < 26; i++)
        {
            if (Outdeg[i] > 0)
            {
                node = i;
                break;
            }
        }

        if (node == -1)
            return 1;

        DFS(node, adj, vis);

        for (int i = 0; i < 26; i++)
        {
            if (Indeg[i] && !vis[i])
                return 0;
        }

        return 1;
    }
};

int main(){
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    vector<string> arr(n);
    cout << "Enter the strings:\n";
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    Solution sol;
    int result = sol.isCircle(arr);
    if (result)
        cout << "Yes, the strings can be chained to form a circle.\n";
    else
        cout << "No, the strings cannot be chained to form a circle.\n";
    return 0;
}

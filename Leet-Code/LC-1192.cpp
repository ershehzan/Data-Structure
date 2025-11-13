#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void DFS(int node, int parent, vector<vector<int>> &adj, vector<vector<int>> &bridges,
             vector<int> &disc, vector<int> &low, vector<bool> &vis, int &count){
        
           disc[node] = low[node] = count;
           vis[node] = 1;
           for (int j = 0; j < adj[node].size(); j++)
             {
            int neigh = adj[node][j];
            if (neigh == parent)
                continue;
            else if (vis[neigh])
            {
                low[node] = min(low[node], disc[neigh]);
            }
            else  {
                count++;
                DFS(neigh, node, adj, bridges, disc, low, vis, count);
                if (disc[node] < low[neigh])
                {
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(neigh);
                    bridges.push_back(temp);
                }
                low[node] = min(low[node], low[neigh]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections){
        vector<vector<int>> adj(n);
        for (auto &c : connections)
        {
            int u = c[0], v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> bridges;
        vector<int> disc(n);
        vector<int> low(n);
        vector<bool> vis(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                DFS(i, -1, adj, bridges, disc, low, vis, count);
        }
        return bridges;
    }
};

int main(){
    
    int n = 5;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};

    Solution sol;
    vector<vector<int>> bridges = sol.criticalConnections(n, connections);

    cout << "Critical Connections (Bridges):" << endl;
    for (const auto &bridge : bridges)
    {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void DFS(int node, int parent, vector<int> adj[], vector<bool> &vis, vector<bool> &A, vector<int> &disc, vector<int> &low, int &timer)
    {
        vis[node] = 1;
        low[node] = disc[node] = timer;
        int child = 0;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neigh = adj[node][j];

            if (neigh == parent)
                continue;

            else if (vis[neigh])
            {
                low[node] = min(low[node], disc[neigh]);
            }
            else
            {
                child++;
                timer++;
                DFS(neigh, node, adj, vis, A, disc, low, timer);

                if (disc[node] <= low[neigh] && parent != -1)
                {
                    A[node] = 1;
                }
                low[node] = min(low[node], low[neigh]);
            }
        }
        if (child > 1 && parent == -1)
        {
            A[node] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<bool> A(V, 0);
        vector<int> disc(V);
        vector<int> low(V);
        vector<bool> vis(V, 0);
        int timer = 0;

        DFS(0, -1, adj, vis, A, disc, low, timer);

        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (A[i])
                ans.push_back(i);
        }

        if (ans.size() == 0)
            ans.push_back(-1);

        return ans;
    }
};

int main(){
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<int> adj[V];
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }
    Solution obj;
    vector<int> res = obj.articulationPoints(V, adj);
    cout << "Articulation Points: ";
    for (int x : res)
        cout << x << " ";
    cout << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<bool> Ismst(V, 0);
        vector<int> parent(V, -1);
        int cost = 0;
        pq.push({0, {0, -1}});
        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int par = pq.top().second.second;
            pq.pop();
            if (Ismst[node])
                continue;
            Ismst[node] = 1;
            cost += wt;
            parent[node] = par;
            for (auto &j : adj[node])
            {
                int neigh = j.first;
                int w = j.second;
                if (!Ismst[neigh])
                {
                    pq.push({w, {neigh, node}});
                }
            }
        }
        return cost;
    }
};

int main()
{
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}};
    Solution sol;
    int mstCost = sol.spanningTree(V, edges);
    cout << "Minimum Spanning Tree Cost: " << mstCost << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    bool DFS(int node, vector<vector<int>>& adj, vector<int>& vis, int &count, int N) {
         vis[node] = 1;
         count++;
         if (count == N)
                 return 1;
         for (int j = 0; j < adj[node].size(); j++) {
                 if (!vis[adj[node][j]] && DFS(adj[node][j], adj, vis, count, N))
                         return 1;
         }
         vis[node] = 0;
         count--;
         return 0;
    }
    bool check(int n, int m, vector<vector<int>> edges) {
            vector<vector<int>> adj(n);
            for (int i = 0; i < m; i++) {
                    adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
                    adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
            }
            vector<int> vis(n, 0);
            int count = 0;
            for (int i = 0; i < n; i++) {
                    fill(vis.begin(), vis.end(), 0);
                    count = 0;
                    if (DFS(i, adj, vis, count, n))
                            return true;
            }
            return 0;
    }
};

int main() {
        int n, m;
        cout << "Enter number of nodes and edges: ";
        cin >> n >> m;
        vector<vector<int>> edges(m, vector<int>(2));
        cout << "Enter edges (u v) 1-based indexing:\n";
        for (int i = 0; i < m; ++i) {
                cin >> edges[i][0] >> edges[i][1];
        }
        Solution sol;
        if (sol.check(n, m, edges))
                cout << "Hamiltonian Path exists\n";
        else
                cout << "Hamiltonian Path does not exist\n";
        return 0;
}
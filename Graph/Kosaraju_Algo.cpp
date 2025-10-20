#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//Position this line where user code will be pasted.
class Solution {
    public:
        void topo_sort(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& s) {
            vis[node] = 1;
            for (int neigh : adj[node]) {
                    if (!vis[neigh])
                            topo_sort(neigh, adj, vis, s);
            }
            s.push(node);
        }
    
        void DFS(int node,vector<vector<int>>&adj,vector<bool>&vis)
        {
                vis[node]=1;
                for(int neigh:adj[node])
                {
                        if(!vis[neigh])
                        DFS(neigh,adj,vis);
                }
        }
        
        int kosaraju(vector<vector<int>> &adj) {
            int V=adj.size();
            //Topological sort 
            stack<int>s;
            vector<bool>vis(V,0);
            for(int i=0;i<V;i++)
            {
                    if(!vis[i])
                    topo_sort(i,adj,vis,s);
            }
            // Transpose the edges or revere it 
            vector<vector<int>>adj2(V);
            for(int i=0;i<V;i++)
            for(int j=0;j<adj[i].size();j++)
            {
                    int u=i;
                    int v=adj[i][j];
                    adj2[v].push_back(u);
            }
            //pop element from stack 
            //If the poped node is not visited
            //scc++
            //DFS Call
            for(int i=0;i<V;i++)
            vis[i]=0;
            int SCC=0;
            while(!s.empty())
            {
                    int node=s.top();
                    s.pop();
                    if(!vis[node])
                    {
                            SCC++;
                            DFS(node,adj2,vis);
                    }
            }
                 return SCC;
        }
};

int main() {
        int V, E;
        cout << "Enter number of vertices and edges: ";
        cin >> V >> E;
        vector<vector<int>> adj(V);
        cout << "Enter edges (u v) as 0-based indices:\n";
        for (int i = 0; i < E; ++i) {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
        }
        Solution sol;
        int scc = sol.kosaraju(adj);
        cout << "Number of strongly connected components: " << scc << endl;
        return 0;
}
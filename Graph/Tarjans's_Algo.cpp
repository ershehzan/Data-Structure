//Strongly connected component (Tarjans's Algo)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Paste the Solution class here

class Solution {
    public:
    void DFS(int node,vector<int>adj[],vector<int>&disc,vector<int>&low,
    vector<bool>&vis,stack<int>&s,vector<bool>&IsStack,vector<vector<int>>&ans,int &timer)
    {
            vis[node]=1;
            disc[node]=low[node]=timer;
            s.push(node);
            IsStack[node]=1;
             for(int j=0;j<adj[node].size();j++)
             {
                     int neigh=adj[node][j];
                     if(!vis[neigh])
                     {
                             timer++;
                             DFS(neigh,adj,disc,low,vis,s,IsStack,ans,timer);
                             low[node]=min(low[node],low[neigh]);
                     }
                     else{
                             if(IsStack[neigh])
                             low[node]=min(low[node],disc[neigh]);
                     }
             }
             if(disc[node]==low[node])
             {
                     vector<int>temp;
                     while(!s.empty()&&s.top()!=node)
                     {
                             temp.push_back(s.top());
                             IsStack[s.top()]=0;
                             s.pop();
                     }
                        temp.push_back(node);
                             IsStack[node]=0;
                             s.pop();
                             sort(temp.begin(),temp.end());
                             ans.push_back(temp);
             }
    }
        vector<vector<int>> tarjans(int V, vector<int> adj[]) {
                vector<vector<int>>ans;
                vector<int>disc(V);
                vector<int>low(V);
                vector<bool>vis(V,0);
                stack<int>s;
                vector<bool>IsStack(V,0);
                int timer=0;
                for(int i=0;i<V;i++)
                {
                        if(!vis[i])
                        {
                                 DFS(i,adj,disc,low,vis,s,IsStack,ans,timer);
                        }
                };
                sort(ans.begin(),ans.end());
                return ans;
        }
};

int main() {
        int V, E;
        cout << "Enter number of vertices and edges: ";
        cin >> V >> E;
        vector<int> adj[V];
        cout << "Enter edges (u v) for directed graph (0-based indexing):\n";
        for(int i = 0; i < E; ++i) {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
        }
        Solution obj;
        vector<vector<int>> scc = obj.tarjans(V, adj);
        cout << "Strongly Connected Components:\n";
        for(const auto& comp : scc) {
                for(int node : comp) {
                        cout << node << " ";
                }
                cout << endl;
        }
        return 0;
}
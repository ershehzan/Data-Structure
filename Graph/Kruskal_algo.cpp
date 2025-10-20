#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
  
  // Function to find the parent of a node in DSU
  // Uses path compression for optimization
  int findparent(int u, vector<int>& parent) {
      if (u == parent[u]) 
          return u;
      return parent[u] = findparent(parent[u], parent); // Path compression
  }
  
  // Function to perform union by rank
  // Always attaches smaller rank tree under larger rank tree
  void unionbyrank(int u, int v, vector<int>& parent, vector<int>& rank) {
      int pu = findparent(u, parent); // Find parent of u
      int pv = findparent(v, parent); // Find parent of v
      
      // Merge by rank
      if (rank[pu] > rank[pv]) {
          parent[pv] = pu;  // attach v’s parent to u’s parent
      }
      else if (rank[pu] < rank[pv]) {
          parent[pu] = pv;  // attach u’s parent to v’s parent
      }
      else {
          // If ranks are same, choose any as parent and increase rank
          parent[pv] = pu;
          rank[pu]++;
      }
  }
  
  // Function to return cost of Minimum Spanning Tree (MST)
  int spanningTree(int V, vector<vector<int>>& edges) {
        
        // Initialize parent and rank arrays for DSU
        vector<int> parent(V);
        vector<int> rank(V, 0);
        for (int i = 0; i < V; i++) 
            parent[i] = i;
        
        // Min-heap priority queue to store edges in sorted order of weight
        // Format: {weight, {u, v}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        
        // Push all edges into the priority queue
        for (auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            pq.push({wt, {u, v}});
        }
        
        int cost = 0;  // total cost of MST
        
        // Process edges one by one (Kruskal’s Algorithm)
        while (!pq.empty()) {
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            
            // If u and v belong to different sets, include this edge in MST
            if (findparent(u, parent) != findparent(v, parent)) {
                cost += wt;                     // add edge weight to cost
                unionbyrank(u, v, parent, rank); // merge the sets
            }
        }
        
        return cost; // return final MST cost
    }
};


/*

This code is Kruskal’s MST implementation using Disjoint Set Union (DSU)
with Path Compression + Union by Rank.

Time Complexity: O(E log E + E α(V)) (due to sorting edges + DSU operations, 
where α is inverse Ackermann function ≈ constant).

Space Complexity: O(V + E)

*/

int main()
{
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    Solution sol;
    int mst_cost = sol.spanningTree(V, edges);
    cout << "Minimum Spanning Tree cost: " << mst_cost << endl;
    return 0;
}
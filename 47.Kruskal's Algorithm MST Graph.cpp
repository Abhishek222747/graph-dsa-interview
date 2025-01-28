//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    // Constructor to initialize sets
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0); // Initial rank is 0 for all elements
        for (int i = 1; i <= n; i++) {
            parent[i] = i; // Each element is its own parent initially
        }
    }

    // Function to find the ultimate parent (with path compression)
    int findUPar(int x) {
        if (parent[x] != x) {
            parent[x] = findUPar(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Function to union two sets (Union by Rank)
    void unionSet(int x, int y) {
        int rootX = findUPar(x);
        int rootY = findUPar(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++; // Increase rank of new root
            }
        }
    }

    // Function to check if two elements are in the same set
    bool isConnected(int x, int y) {
        return findUPar(x) == findUPar(y);
    }

    // Function to print the parent array (for debugging)
    void printParent() {
        for (int i = 1; i < parent.size(); i++) {
            cout << "Element: " << i << " | Parent: " << parent[i] << endl;
        }
    }
};
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        //adjacency list given and no. of vertices is also givn
        vector<pair<int,pair<int,int>>> edges;//{wt,{u,v}}
        //{wt,{u,v}}
        
        for(int i=0;i<V;i++){
            for( auto it:adj[i] ){
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjNode}});
                
            }
        }
        
        sort(edges.begin(),edges.end());
        
        int mstwt=0;
        DisjointSet ds(V);
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mstwt+=wt;
                ds.unionSet(u,v);
            }
        }
        return mstwt;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
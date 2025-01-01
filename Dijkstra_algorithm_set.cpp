Q.33) Given a weighted, undirected and connected graph where you have given adjacency list adj. 
You have to find the shortest distance of all the vertices from the source vertex src, and 
return a list of integers denoting the shortest distance between each node and source vertex src.

Note: The Graph doesn't contain any negative weight edge.

This solution is using set that uses erase technique and save some iteration though no mazor changes 
in tc comparing to priority queue as erase itself takes log n 


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int S) {
        // Code here
        int V= adj.size();
        set<pair<int,int>> st;
        vector<int> distTo(V, INT_MAX);
        distTo[S] = 0;
        st.insert({0,S});
        while(!st.empty()){
           auto it= *(st.begin());
           int node= it.second;
           int dis= it.first;
           st.erase(it);
           for(auto it: adj[node]){
               int adjnode= it.first;
               int edgw= it.second;
               if(dis+edgw<distTo[adjnode]){
                   if(distTo[adjnode]!=INT_MAX){
                       st.erase({distTo[adjnode],adjnode});
                   }
                   distTo[adjnode]= dis+edgw;
                   st.insert({distTo[adjnode], adjnode});
               }
           }
        }
        return distTo;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends

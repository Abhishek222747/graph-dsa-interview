Given an undirected graph with V vertices. We say two vertices u and v belong to a single province
if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    void bfs(int start,vector<int> adjls[],int vis[]){
        queue<int> q;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto it: adjls[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjls[V];
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        
        int vis[V]={0};
        int ans=0;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                ans++;
                bfs(i,adjls,vis);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends

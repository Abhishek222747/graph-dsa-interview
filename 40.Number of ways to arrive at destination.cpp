//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,long long>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<int> dist(n,INT_MAX), ways(n,0);
        dist[0]=0;
        ways[0]=1;
        int m= (int)1e9+7;
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            long long dis= it.first;
            int node= it.second;
            for(auto it: adj[node]){
                int adjnode= it.first;
                long long edgd= it.second;
                if(dis+edgd<dist[adjnode]){
                    dist[adjnode]= dis+edgd;
                    pq.push({dis+edgd,adjnode});
                    ways[adjnode]= ways[node];
                    
                }
                else if(dis+edgd==dist[adjnode]){
                    ways[adjnode]= (ways[adjnode]+ways[node])%m;
                }
            }
        }
        return ways[n-1]%m;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends
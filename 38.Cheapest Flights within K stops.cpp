There are n cities and m edges connected by some number of flights. You are given an array flights where 
flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.

Note: The price from city A to B may be different From the price from city B to A


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int, pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n, 1e9);
        dist[src]=0;
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int stops= it.first;
            int node= it.second.first;
            int dis= it.second.second;
            if(stops>k) continue;
            for(auto itr: adj[node]){
                int adjnode= itr.first;
                int edgw= itr.second;
                if(dis+edgw<dist[adjnode] && stops<=k){
                    dist[adjnode]= dis+edgw;
                    q.push({stops+1,{adjnode, dis+edgw}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends

You are given a n,m which means the row and column of the 2D matrix and an array of  size k 
denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. 
Originally, the 2D matrix is all 0 which means there is no land in the matrix. 
The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can 
change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the
matrix after each operation.You need to return an array of size k.
    
Note : An island means group of 1s such that they share a common side.





//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    bool valid(int newr, int newc, int n, int m){
        return newr>=0 & newr<n & newc>=0 & newc<m;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt=0;
        vector<int> ans;
        for(auto it: operators){
            int row= it[0];
            int col= it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            int dr[]={-1,0,+1,0};
            int dc[]={0,+1,0,-1};
            for(int i=0; i<4; i++){
              int newr= row+dr[i];
              int newc= col+dc[i];
              if(valid(newr,newc,n,m)){
                  if(vis[newr][newc]==1){
                      int nodeno= row*m+col;
                      int adjnodeno= newr*m+newc;
                      if(ds.findUPar(nodeno)!=ds.findUPar(adjnodeno)){
                          cnt--;
                          ds.unionBySize(nodeno,adjnodeno);
                      }
                  }
              }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends

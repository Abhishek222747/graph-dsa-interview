Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest
distance between a given source cell to a destination cell. The path can only be created out of a 
cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.
  
Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. 
Two cells are adjacent if they share a side. In other words, you can move in one of the four directions,
Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. 
The destination cell should be 1.




//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source.first==destination.first && source.second==destination.second) return 0;
    
        queue<pair<int, pair<int,int>>> q;
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        q.push({0,{source.first, source.second}});
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int dis= it.first;
            int r= it.second.first;
            int c= it.second.second;
            for(int i=0; i<4; i++){
                int newr= r+dr[i];
                int newc= c+dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 &&
                dis+1<dist[newr][newc]){
                    dist[newr][newc]= dis+1;
                    if(newr==destination.first && newc==destination.second) return dis+1;
                    q.push({dist[newr][newc], {newr,newc}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends

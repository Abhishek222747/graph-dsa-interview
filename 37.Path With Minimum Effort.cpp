You are a hiker preparing for an upcoming hike. You are given heights[][], a 2D array of size
rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated
in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) 
(i.e., 0-indexed). You can move up, down, left, or right, and you wish to find the route with minimum effort.

Note: A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int n= heights.size();
        int m= heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int diff= it.first;
            int r= it.second.first;
            int c= it.second.second;
            if(r==n-1 && c==m-1) return diff;
            for(int i=0; i<4; i++){
                int newr= r+dr[i];
                int newc= c+dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int neweffort= max(abs(heights[r][c]-heights[newr][newc]), diff);
                    if(neweffort<dist[newr][newc]){
                        dist[newr][newc]= neweffort;
                        pq.push({neweffort,{newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends

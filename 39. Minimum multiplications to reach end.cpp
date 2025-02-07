Given start, end and an array arr of n numbers. At each step, start is multiplied with any number 
in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. 
If it is not possible to reach end, then return -1.


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end) return 0;
        queue<pair<int,int>> q;
        int mode= 100000;
        q.push({0,start});
        vector<int> dist(100000, 1e9);
        dist[start]=0;
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int steps= it.first;
            int node= it.second;
            for(auto it: arr){
                int adjnode= (node*it)%mode;
                if(steps+1<dist[adjnode]){
                    dist[adjnode]= steps+1;
                    if(adjnode==end) return steps+1;
                    q.push({steps+1,adjnode});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends

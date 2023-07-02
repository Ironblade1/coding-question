class Solution {
public:
    int ans = INT_MIN;
    void solve(int i, vector<vector<int>>& r, vector<int>& indegree, int n , int cnt){
        if(i==r.size()){
            for(int j=0;j<n;j++){
                if(indegree[j] != 0){
                    return ;
                }
            }
            ans = max(ans, cnt);
            return ;
        }

        // take 
        indegree[r[i][0]]--; 
        indegree[r[i][1]]++;
        solve(i+1, r, indegree, n, cnt+1);

        //not take 
         // backtracking
        indegree[r[i][0]]++;
        indegree[r[i][1]]--;
        solve(i+1,r, indegree, n, cnt);

       
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n,0);
        solve(0,requests,indegree,n, 0);
        return ans;
    }
};
class Solution {
public:

    int mod = 1000000007;
    vector<int> dr = {0,1,0,-1};
    vector<int> dc = {-1,0,1,0};

    bool isvalid(int r, int c, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size(); 
        if(r>=0 && r<m && c>=0 && c<n) return true;
        return false;
    }

    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int ans = 1;
        if(dp[r][c]!=-1) return dp[r][c];

        for(int i=0;i<4;i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(isvalid(nrow,ncol,grid) && grid[nrow][ncol]>grid[r][c])
                ans = (ans + dfs(nrow, ncol, grid,dp))%mod;
        }
        return dp[r][c] = ans%mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long cnt = 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cnt = (cnt + dfs(i,j,grid,dp))%mod;
            }
        }
        return (int)cnt%mod;
    }
};
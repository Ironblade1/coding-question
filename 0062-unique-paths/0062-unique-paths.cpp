class Solution {
public:
    
    int solve(int m, int n, int i, int j){
        if(i>m-1 || j>n-1 || i<0 || j<0){
            return 0;
        }
        if(i==m-1 && j==n-1) return 1;
        int ans =0;
        int right = solve(m,n,i,j+1);
        int down = solve(m,n,i+1,j);
        return ans = right+down;
    }
    
    int solveMem(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i>m-1 || j>n-1 || i<0 || j<0){
            return 0;
        }
        if(i==m-1 && j==n-1) return 1;
        
        if(dp[i][j]!= -1) return dp[i][j];

        int right = solveMem(m,n,i,j+1,dp);
        int down = solveMem(m,n,i+1,j,dp);
        return dp[i][j] = right+down;
    }
    
    int solveTab(int m, int n){
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        dp[m-1][n-1] =1;
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int right = dp[i][j+1];
                int down = dp[i+1][j];
                dp[i][j] = right+down;
            }
        }
        return dp[0][0];
    }
    
    int uniquePaths(int m, int n) {
        // return solve(m,n,0,0);
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solveMem(m,n,0,0,dp);
        
    }
};
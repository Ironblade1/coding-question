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
    
    
    
    int uniquePaths(int m, int n) {
        // return solve(m,n,0,0);
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solveMem(m,n,0,0,dp);
        
    }
};
class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j){
        if(i == triangle.size()) return 0;
        
        int ans1 = triangle[i][j] + solve(triangle, i+1, j);
        int ans2 = triangle[i][j] + solve(triangle, i+1, j+1);
        
        return min(ans1, ans2);
    }

    int solveMem(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
        if(i == triangle.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int ans1 = triangle[i][j] + solveMem(triangle, i+1, j,dp);
        int ans2 = triangle[i][j] + solveMem(triangle, i+1, j+1, dp);
        
        return dp[i][j] = min(ans1, ans2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        // return solve(triangle, 0, 0);  // recursive
        int n = triangle.size();
        vector<vector<int>> dp(triangle.size()+1, vector<int>(n+1,-1));
        return solveMem(triangle,0,0,dp);
    }
};
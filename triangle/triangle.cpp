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

    int solveTab(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <=i; j++){  
                int ans1 = triangle[i][j] + dp[i+1][j];
                int ans2 = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(ans1, ans2);
            }
        }
        return dp[0][0];
    }

    int solveOS(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <=i; j++){  
                int ans1 = triangle[i][j] + next[j];
                int ans2 = triangle[i][j] + next[j+1];
                curr[j] = min(ans1, ans2);
            }
            next = curr;
        }
        return next[0];
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        // return solve(triangle, 0, 0);  // recursive
        // int n = triangle.size();
        // vector<vector<int>> dp(triangle.size()+1, vector<int>(n+1,-1));
        // return solveMem(triangle,0,0,dp);

        // return solveTab(triangle);

        return solveOS(triangle);
    }
};
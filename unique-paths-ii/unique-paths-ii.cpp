class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();

        if(i==n-1 && j==m-1) return 1;
        int ans = 0;

        if(i+1<n && grid[i+1][j] != 1) 
            ans += solve(i+1,j,grid);
        if(j+1<m && grid[i][j+1]!=1)
            ans += solve(i,j+1,grid);
        return ans;
    }

    int solveMem(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int n = grid.size(), m = grid[0].size();
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;

        if(i+1<n && grid[i+1][j] != 1) 
            ans += solveMem(i+1,j,grid,dp);
        if(j+1<m && grid[i][j+1]!=1)
            ans += solveMem(i,j+1,grid, dp);
        return dp[i][j] = ans;
    }

    int solveTab(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[n-1][m-1] = (grid[n-1][m-1] == 0) ? 1 : 0;

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1) continue; // Skip the bottom-right corner

                if(grid[i][j] == 1) continue; // Skip if obstacle is present at current cell

                long long int ans = 0;
                if(i+1 < n && grid[i+1][j] != 1)
                    ans += dp[i+1][j];
                if(j+1 < m && grid[i][j+1] != 1)
                    ans += dp[i][j+1];
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        if(n==1 && m ==1 )
            return (obstacleGrid[0][0]==1) ? 0:1 ; // for single element grid

        // return solve(0,0,obstacleGrid);

        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return solveMem(0,0,obstacleGrid,dp);

        return solveTab(obstacleGrid);

    }
};
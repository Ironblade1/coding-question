class Solution {
public:
    int r,c;
    
    bool isSafe(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visi){
        if(i>=0 && i<r && j>=0 && j<c && visi[i][j]==0 ) return 1;
        else return 0;
    }
    
    void solve(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visi,int sum,int &ans){
        if(i==r-1 && j==c-1){
            ans = min(ans,sum + grid[i][j]);
            return ;
        }
        visi[i][j]=1;
        
        // move Right
        if(isSafe(i,j+1,grid,visi)){
            solve(i,j+1,grid,visi,sum+grid[i][j],ans);
        }
        // move Down
        if(isSafe(i+1,j,grid,visi)){
            solve(i+1,j,grid,visi,sum+grid[i][j],ans);
        }
        visi[i][j]=0;
    }
    
    int solveMem(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==r-1 && j==c-1){
            return grid[i][j];
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right =INT_MAX, down =INT_MAX;
        // move Right
        if(j<c-1){
            right = solveMem(i,j+1,grid,dp);
        }
        //move left
        if(i<r-1){
            down = solveMem(i+1,j,grid,dp);
        }
        int mini = min(right,down) + grid[i][j];
        dp[i][j] = mini;
        return mini;
        
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        r = grid.size();
        c = grid[0].size();
        
        // backtracking
        // int ans  = INT_MAX;
        // int sum=0;
//         vector<vector<bool>> visi(r,vector<bool>(c,0));
//         solve(0,0,grid,visi,sum,ans);
        
        vector<vector<int>> dp(r+1,vector<int>(c+1,-1));
        return solveMem(0,0,grid,dp);
    }
};
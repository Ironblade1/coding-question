class Solution {
public:

    int solve(vector<int>& obstacles, int currLane, int currpos){
        //base case --- if we travelled at the end point
        int n = obstacles.size();
        int ans = INT_MAX;
        if(currpos == n-1){
            return 0;
        }
        if(obstacles[currpos+1]!=currLane){
            return solve(obstacles,currLane,currpos+1);
        }
        else{
            for(int i=1;i<=3;i++){
                if(currLane != i && obstacles[currpos]!=i)
                    ans = min(ans, 1+ solve(obstacles,i,currpos));
            }
        }
        return ans;
    }

    int solveMem(vector<int> &obstacles, int currLane, int currpos,vector<vector<int>> &dp){
        int n = obstacles.size();
        int ans = INT_MAX;
        if(currpos== n-1)   return 0;

        if(dp[currLane][currpos]!=-1)   return dp[currLane][currpos];

        if(obstacles[currpos+1]!=currLane)  return solveMem(obstacles,currLane,currpos+1,dp);
        else{
            for(int i=1;i<=3;i++){
                if(currLane != i && obstacles[currpos]!=i) ans = min(ans, 1+ solveMem(obstacles,i,currpos, dp));
            }
        }
        dp[currLane][currpos] = ans;
        return dp[currLane][currpos];
    }
    
    int solveTab(vector<int> &obstacles){
        vector<vector<int>> dp(4,vector<int>(obstacles.size(),1e9));
        int n = obstacles.size()-1;
        dp[0][n]=0;
        dp[1][n]=0;
        dp[2][n]=0;
        dp[3][n]=0;
 
        for(int i=n-1;i>=0;i--){
            for(int lane =1;lane<=3;lane++){
                if(obstacles[i+1]!= lane) dp[lane][i] = dp[lane][i+1];
                else{
                    int ans = 1e9;
                    for(int j=1;j<=3;j++){
                        if(lane != j && obstacles[i]!=j){
                            ans = min(ans, 1+ dp[j][i+1]);
                        }
                    }
                    dp[lane][i] = ans;
                }
            }   
        }
        return min(dp[2][0], min(dp[1][0]+1, dp[3][0]+1));
    }


    int minSideJumps(vector<int>& obstacles) {
        // return solve(obstacles,2,0);

        // vector<vector<int>> dp(4,vector<int>(obstacles.size(),-1));
        // return solveMem(obstacles,2,0,dp);
        
        return solveTab(obstacles);
    }
};
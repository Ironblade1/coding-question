class Solution {
public:
    int solve(int i, int n, vector<int>& dp){
        if(i==n){
            return 1;
        }
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = solve(i+1,n,dp) + solve(i+2,n,dp);
    }

    int solveTab(int n){
        vector<int> dp(n+2,0);
        dp[n] = 1;

        for(int i=n-1;i>=0;i--){
            dp[i] = dp[i+1] + dp[i+2];
        }
        return dp[0];
    }

    int solveOpt(int n){
        int frwd = 1;
        int curr = 0;
        int frwd2 = 0;
        for(int i=n-1;i>=0;i--){
            curr = frwd + frwd2;
            frwd2 = frwd;
            frwd = curr;
        }
        return frwd;
    }

    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return solve(0,n, dp);

        return solveOpt(n);
    }
};
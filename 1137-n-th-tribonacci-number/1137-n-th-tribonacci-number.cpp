class Solution {
public:
    int solve(int n){
        if(n==0)    return 0;
        if(n==1 || n==2)    return 1;
        return solve(n-1)+solve(n-2)+solve(n-3);
    }

    int solveMem(int n,vector<int> &dp){
        if(n==0)    return 0;
        if(n==1 || n==2)    return 1;

        if(dp[n]!= -1)   return dp[n];
        return dp[n] = solveMem(n-1,dp)+solveMem(n-2,dp)+solveMem(n-3,dp);
    }

    int solvetab(int n){
        if(n==0)    return 0;
        if(n==1 || n==2) return 1;
        vector<int> dp(n+1,0);
        dp[1]=dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]= dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }

    int solveOpt(int n){
        if(n==0)    return 0;
        if(n==1 || n==2) return 1;
        int prev3 =0;
        int prev2 =1;
        int prev1 =1;
        for(int i=3;i<=n;i++){
            int curr = prev1+prev2+prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int tribonacci(int n) {
        // return solve(n);

        // vector<int> dp(n+1,-1);
        // return solveMem(n,dp);

        // return solvetab(n);

        return solveOpt(n);
    }
};
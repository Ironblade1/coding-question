class Solution {
public:
    
    int solve(int n){
        if(n<=0) return 1;
        
        int ans =0;
        for(int i=1;i<=n;i++){
            ans += solve(i-1)*solve(n-i); // if i is root node
        }
        return ans;
    }
    
    int solveMem(int n , vector<int> &dp){
        if(n<=0) return 1;
        
        if(dp[n]!=-1) return dp[n];
        
        int ans =0;
        for(int i=1;i<=n;i++){
            ans += solveMem(i-1,dp)*solveMem(n-i,dp);
        }
        return dp[n]=ans;
    }
    
    int solveTab(int n){
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){ // i is number of node
            
            for(int j=1;j<=i;j++){ // j is root node
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
    
    int numTrees(int n) {
        // return solve(n);
        
        // vector<int> dp(n+1,-1);
        // return solveMem(n,dp);
        
        return solveTab(n);
        
    }
};
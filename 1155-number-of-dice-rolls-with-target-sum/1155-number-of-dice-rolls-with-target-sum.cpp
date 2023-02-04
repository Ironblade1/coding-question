class Solution {
public:
    #define MOD 1000000007
    int solve(int dices, int faces, int target){
        if(target<0) return 0;
        if(dices==0 && target !=0) return 0;
        if(dices!=0 && target ==0) return 0;
        if(dices==0 && target ==0) return 1;
        
        int ans = 0;
        for(int i=1;i<=faces;i++){
            ans = (ans%MOD + solve(dices-1,faces,target-i)%MOD)%MOD;
        }
        return ans ;
    }
    
    
    int solveMem(int dices, int faces , int target, vector<vector<int>> &dp){
        if(target<0) return 0;
        if(dices==0 && target !=0) return 0;
        if(dices!=0 && target ==0) return 0;
        if(dices==0 && target ==0) return 1;
        
        if(dp[dices][target]!=-1) return dp[dices][target];
        
        int ans = 0;
        for(int i=1;i<=faces;i++){
            ans = (ans%MOD + solveMem(dices-1,faces,target-i,dp)%MOD)%MOD;
        }
        
        return dp[dices][target] = ans ;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        // return solve(n, k, target);
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solveMem(n,k,target,dp);
    }
};
class Solution {
public:
    
    bool solve(int ind, vector<int>& nums, int target){
        if(ind>=nums.size()) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        
        bool inc = solve(ind+1,nums,target-nums[ind]);
        bool exc = solve(ind+1,nums,target-0);
        
        return inc or exc;
    }
    
    bool solveMem(int ind, vector<int>& nums, int target,vector<vector<int>> &dp){
        if(ind>=nums.size()) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        
        if(dp[ind][target]!= -1) return dp[ind][target];
        
        bool inc = solveMem(ind+1,nums,target-nums[ind],dp);
        bool exc = solveMem(ind+1,nums,target-0,dp);
        
        return dp[ind][target] = inc or exc;
    }
    
    bool solveTab(vector<int> &nums,int total){
        int n = nums.size();
        int t = total/2;
        vector<vector<int>> dp(n+1,vector<int>(t+1,0));
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        
        for(int i=n-1;i>=0;i--){
            for(int target = 0;target<=t;target++){
                bool inc =0;
                if(target-nums[i]>=0)
                     inc = dp[i+1][target-nums[i]];
                bool exc = dp[i+1][target];
                dp[i][target] = inc or exc;
            }
        }
        return dp[0][t];
    }
    
    bool solveSo(vector<int> &nums, int target){
        int n = nums.size();
        int t = target/2;
        vector<int> curr(t+1,0);
        vector<int> next(t+1,0);
        
        curr[0]=1;
        next[0]=1;
        
        for(int i=n-1;i>=0;i--){
            for(int target =0;target<=t;target++){
                bool inc =0;
                if(target-nums[i]>=0)
                    inc = next[target-nums[i]];
                bool exc = next[target];
                curr[target] = inc or exc;
            }
            next = curr;
        }
        return next[t];
    }
    
    bool canPartition(vector<int>& nums) {
        int total =0;
        for(int i:nums){
            total += i;
        }
        if(total%2!=0)  return 0;
        int target = total/2;
        int n = nums.size();
        
        // return solve(0,nums,target);
        
        // vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        // return solveMem(0,nums,target,dp);
        
        // return solveTab(nums,total);
        
        return solveSo(nums,total);
    }
};
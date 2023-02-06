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
    
    bool canPartition(vector<int>& nums) {
        int total =0;
        for(int i:nums){
            total += i;
        }
        if(total%2!=0)  return 0;
        int target = total/2;
        int n = nums.size();
        
        // return solve(0,nums,target);
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solveMem(0,nums,target,dp);
    }
};
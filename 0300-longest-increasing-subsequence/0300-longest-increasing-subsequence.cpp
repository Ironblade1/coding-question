class Solution {
public:
    
    int solve(vector<int>& nums, int curr, int prev){
        int n = nums.size();
        if(curr == n)   return 0;
        
        //include
        int take =0;
        if(prev == -1 || nums[curr]>nums[prev]){
            take = 1+ solve(nums,curr+1,curr);
        }
        int notTake = 0 + solve(nums,curr+1,prev);
        return max(take,notTake);
    }
    
    
    int solveMem(vector<int>& nums, int curr, int prev, vector<vector<int>> &dp){
        int n = nums.size();
        if(curr == n)   return 0;
        
        if(dp[curr][prev+1]!= -1) return dp[curr][prev+1];
        
        int take =0;
        if(prev ==-1 || nums[curr]>nums[prev]){
            take = 1+ solveMem(nums,curr+1,curr,dp);
        }
        int notTake = 0+ solveMem(nums,curr+1,prev,dp);
        
        return dp[curr][prev+1] = max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // return solve(nums,0,-1);  // curr , prev both are index of nums
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector(n+1,-1));
        return solveMem(nums,0,-1,dp);
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};
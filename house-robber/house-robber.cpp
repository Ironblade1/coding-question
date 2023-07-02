class Solution {
public:
    int solve(vector<int>& nums, int i){
        if(i<0) return 0;
        if(i==0) return nums[0];
        return max(nums[i]+solve(nums,i-2), solve(nums,i-1));
    }

    int solveMem(vector<int>& nums, int i,vector<int>& dp){
        if(i<0) return 0;
        if(i==0) return nums[0];

        if(dp[i]!=-1) return dp[i];

        return dp[i]=max(nums[i]+solveMem(nums,i-2,dp), solveMem(nums,i-1,dp));
    }

    int solveTab(vector<int>& nums){
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n+1,0);
        dp[0]=nums[0];
        dp[1] = max(nums[0],nums[1]); // if their is only two houses
        for(int i=2;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[n-1];
        
    }

    int solveOpt(vector<int>& nums){
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        int curr =0, prev1 =max(nums[0],nums[1]), prev2 = nums[0];
        for(int i=2;i<n;i++){
            curr = max(nums[i]+prev2, prev1);
            prev2 = prev1 ;
            prev1 = curr;
        }
        return prev1 ;
    }

    int solve(int i,vector<int>& nums, vector<int>& dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i] + solve(i+2,nums,dp) , solve(i+1,nums, dp));

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // return solve(nums,n-1);

        vector<int> dp(n+1,-1);
        // return solveMem(nums,n-1,dp);
        
        // return solveTab(nums);

        // return solveOpt(nums);

        return solve(0,nums,dp);
    }
};
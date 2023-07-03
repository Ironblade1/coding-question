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
    
    int solveTab(vector<int> &nums, int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take =0;
                if(prev ==-1 || nums[curr]>nums[prev]){
                    take = 1+ dp[curr+1][curr+1];
                }
                int notTake = 0+ dp[curr+1][prev+1];
                dp[curr][prev+1] = max(take,notTake);
            }
       }
        return dp[0][0];
    }
    
    int solveSO(vector<int> &nums, int n ){
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take =0;
                if(prev ==-1 || nums[curr]>nums[prev]){
                    take = 1+ nextRow[curr+1];
                }
                int notTake = 0+ nextRow[prev+1];
                currRow[prev+1] = max(take,notTake);
            }
            nextRow = currRow;
       }
        return nextRow[0];
        
    }
  
    int solveOptm(vector<int> &nums,int n){
        if(n==0)    return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[ind] = nums[i];
            }
        }
        return ans.size();
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // return solve(nums,0,-1);  // curr , prev both are index of nums
        
        int n = nums.size();
//         vector<vector<int>> dp(n,vector(n+1,-1));
//         return solveMem(nums,0,-1,dp);

        // return solveTab(nums,n);

        // return solveSO(nums,n);

        return solveOptm(nums,n);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};
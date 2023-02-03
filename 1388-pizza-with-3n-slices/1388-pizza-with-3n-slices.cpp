class Solution {
public:
    
    int solve(int ind, int endInd, vector<int>& slices,int n){
        if(n==0 || ind> endInd) 
            return 0;
        int take = slices[ind] + solve(ind+2,endInd,slices,n-1);
        int notTake = 0 + solve(ind+1,endInd,slices,n);
        return max(take,notTake);
    }
    
    int solveMem(int ind, int endInd, vector<int>& slices,int n, vector<vector<int>> &dp){
        if(n==0 || ind> endInd) 
            return 0;
        
        if(dp[ind][n]!=-1) return dp[ind][n];
        
        int take = slices[ind] + solveMem(ind+2,endInd,slices,n-1,dp);
        int notTake = 0 + solveMem(ind+1,endInd,slices,n,dp);
        return dp[ind][n] = max(take,notTake);
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        // int case1 = solve(0,k-2,slices,k/3);
        // int case2 = solve(1,k-1,slices,k/3);
        // return max(case1,case2);
        
        vector<vector<int>> dp1(k,vector(k,-1));
        int case1 = solveMem(0,k-2,slices,k/3,dp1);
        vector<vector<int>> dp2(k,vector(k,-1));
        int case2 = solveMem(1,k-1,slices,k/3,dp2);
        return max(case1,case2);
    }
    
};
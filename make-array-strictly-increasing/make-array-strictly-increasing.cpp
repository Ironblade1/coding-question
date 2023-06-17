class Solution {
public:
    int solve(int i,int j, int prev, vector<int>& a1, vector<int>& a2){
        int n = a1.size(), m = a2.size();
        if(i==n) return 0;  // if we sort the whole array a1

        j = upper_bound(a2.begin()+j,a2.end(),prev) - a2.begin();  // find index j from j to m which index value is just greater than prev
        if(j==m && a1[i]<=prev) return n+1;  // if reach the at the end of arr2 and prev>= a1[i] , that's means there no way to sort arr1
        
        int take = n+1, notTake = n+1;
        
        if(j!=m)
            take = solve(i+1,j+1,a2[j],a1,a2) +1;  // replace a1[i] to a2[j] , prev chnges to ar[j]
        if(prev < a1[i])
            notTake = solve(i+1,j,a1[i],a1,a2);

        return min(take,notTake);

    }

    int solveMem(int i,int j,int prev,vector<vector<int>> &dp,vector<int> &a1,vector<int> &a2){
        int n = a1.size(), m = a2.size();
        if(i==n){
            return 0;
        }
        j = upper_bound(a2.begin()+j,a2.end(),prev)-a2.begin();
        if(dp[i][j] != -1)return dp[i][j];
        if(j==m && a1[i]<=prev)return 2001;
        int take = 2001,nottake = 2001;
        if(j!=m)
        take = solveMem(i+1,j+1,a2[j],dp,a1,a2)+1;
        if(a1[i]>prev)
        nottake = solveMem(i+1,j,a1[i],dp,a1,a2);
        return dp[i][j] = min(take,nottake);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        sort(arr2.begin(),arr2.end());
        // int ans = solve(0,0,-1,arr1,arr2); // i,j , prev = -1(initially)

        // by memoisation
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        int ans = solveMem(0,0,-1,dp,arr1,arr2);
        return (ans>arr1.size())? -1:ans;
    }
};
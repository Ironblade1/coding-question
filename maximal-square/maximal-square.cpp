class Solution {
public:

    int solve(int i,int j,vector<vector<char>> &mat,int &maxi){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        int left = solve(i,j+1,mat,maxi);
        int diagonal = solve(i+1,j+1,mat,maxi);
        int down = solve(i+1,j,mat,maxi);

        if(mat[i][j]=='1'){
            int ans = 1+ min(left,min(down,diagonal));
            maxi = max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
    }

    int solveMem(int i,int j,vector<vector<char>> &mat,int &maxi, vector<vector<int>> &dp){
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int left = solveMem(i,j+1,mat,maxi,dp);
        int diagonal = solveMem(i+1,j+1,mat,maxi,dp);
        int down = solveMem(i+1,j,mat,maxi,dp);

        if(mat[i][j]=='1'){
            dp[i][j] = 1+ min(left,min(down,diagonal));
            maxi = max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }

    int solveTab(vector<vector<char>> &matrix,int& maxi){
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int left = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];

                if(matrix[i][j]=='1'){
                    dp[i][j] = 1+min(left,min(diagonal,down));
                    maxi = max(maxi,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[0][0];

    }

    int solveSO(vector<vector<char>> &matrix,int& maxi){
        int n = matrix.size(),m = matrix[0].size();
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int left = curr[j+1];
                int diagonal = next[j+1];
                int down = next[j];

                if(matrix[i][j]=='1'){
                    curr[j] = 1+min(left,min(diagonal,down));
                    maxi = max(maxi,curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            next = curr;
        }
        return curr[0];

    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
    //    solve(0,0,matrix,maxi);
    //    return maxi*maxi;
        
        // int n = matrix.size();
        // int m = matrix[0].size();
        // int maxi =0;
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // solveMem(0,0,matrix,maxi,dp);
        // return maxi*maxi;

        // solveTab(matrix,maxi);
        // return maxi*maxi;

        solveSO(matrix,maxi);
        return maxi*maxi;



    }
};
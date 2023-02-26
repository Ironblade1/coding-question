class Solution {
public:
    int solve(string w1, string w2, int n,int m){
        if(n==0) return m;
        if(m==0) return n;

        if(w1[n-1] == w2[m-1]) return solve(w1,w2,n-1,m-1);
        
        int insert = 1+solve(w1,w2,n,m-1);
        int remove  = 1+ solve(w1,w2,n-1,m);
        int replace = 1+ solve(w1,w2,n-1,m-1);

        return min(insert,min(remove,replace));
    }

    int solveMem(string w1, string w2, int n, int m, vector<vector<int>> &dp){
        if(n==0) return m;
        if(m==0) return n;

        if(dp[n][m] != -1) return dp[n][m];

        if(w1[n-1] == w2[m-1]) return dp[n][m] = solveMem(w1,w2,n-1,m-1,dp);

        int insert = 1+solveMem(w1,w2,n,m-1,dp);
        int remove = 1+solveMem(w1,w2,n-1,m,dp);
        int replace = 1+solveMem(w1,w2,n-1,m-1,dp);

        return dp[n][m] = min(insert,min(remove,replace));
    }

    int solveTab(string w1, string w2){
        int m = w1.length(), n = w2.length();
    
        int dp[m+1][n+1];

        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (w1[i-1] == w2[j-1]) {
                    // Last characters match, no operation required
                    dp[i][j] = dp[i-1][j-1];
                } 
                else {
                    // Insert a character into w1
                    int insertOp = dp[i][j-1]; 
                    // Delete a character from w1
                    int deleteOp = dp[i-1][j]; 
                    // Replace a character in w1 with a character in w2
                    int replaceOp = dp[i-1][j-1]; 
                    // Take the minimum of the three operations and add 1
                    dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
                }
            }
        }
        // Return the minimum edit distance between the entire strings
        return dp[m][n];
    }

    int minDistance(string word1, string word2) {
        // int n = word1.length();
        // int m = word2.length();

        // return solve(word1,word2,n,m);

        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return solveMem(word1,word2,n,m,dp);

        return solveTab(word1,word2);
    }
};
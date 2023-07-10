class Solution {
public:
    bool solve(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& memo) {
        if (k == s3.length()) return true;
        if (i == s1.length() && j == s2.length()) return false;
        if (memo[i][j] != -1) return memo[i][j];
        
        bool match1 = (i < s1.length() && s1[i] == s3[k]);
        bool match2 = (j < s2.length() && s2[j] == s3[k]);
        
        if (match1 && match2) {
            memo[i][j] = (solve(i + 1, j, k + 1, s1, s2, s3, memo) || solve(i, j + 1, k + 1, s1, s2, s3, memo));
        } else if (match1) {
            memo[i][j] = solve(i + 1, j, k + 1, s1, s2, s3, memo);
        } else if (match2) {
            memo[i][j] = solve(i, j + 1, k + 1, s1, s2, s3, memo);
        } else {
            memo[i][j] = false;
        }
        
        return memo[i][j];
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        
        vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return solve(0, 0, 0, s1, s2, s3, memo);
    }
};

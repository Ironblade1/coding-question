class Solution {
public:
    
    bool solve(string& s,string& p,int i, int j){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        
        if(s[i]==p[j] || p[j]=='?'){
            return solve(s,p,i-1,j-1);
        }
        if(p[j]=='*'){
            return solve(s,p,i,j-1) || solve(s,p,i-1,j);
        }
        return false;
    }
    
    
    bool solveMem(string& s, string& p, int i, int j, vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==p[j] || p[j]=='?')
            return dp[i][j]= solveMem(s,p,i-1,j-1,dp);
        if(p[j]=='*') 
            return dp[i][j]= solveMem(s,p,i-1,j,dp) || solveMem(s,p,i,j-1,dp);
        return false;
    }
    
    bool isMatch(string s, string p) {
        // return solve(s,p,s.length()-1,p.length()-1);
        
        vector<vector<int>> dp(s.length()+1,vector<int> (p.length()+1,-1));
        return solveMem(s,p,s.length(),p.length(),dp);
    }
};
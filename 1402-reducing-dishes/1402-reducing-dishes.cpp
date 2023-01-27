class Solution {
public:
    
    int solve(vector<int>& sat, int index, int time){
        if(index == sat.size()) return 0;
        
        int inc = sat[index]*(time+1) + solve(sat,index+1,time+1);
        int exc = 0 + solve(sat,index+1,time);
        
        return max(inc,exc);
    }
    
    int solveMem(vector<int> &sat,int index,int time, vector<vector<int>> &dp){
        if(index == sat.size())  return 0;
        
        if(dp[index][time]!= -1)    return dp[index][time];
        
        int inc = sat[index]*(time+1) + solveMem(sat,index+1,time+1,dp);
        int exc = 0 + solveMem(sat,index+1,time,dp);
        
        return dp[index][time] = max(inc,exc);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        // return solve(satisfaction, 0, 0);
        
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveMem(satisfaction,0,0,dp);
    }
};
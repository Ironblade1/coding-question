class Solution {
public:
    bool solve(string s, unordered_set<string>& set){
        if(s.length()==0) return true;
        for(int i=0;i<s.length();i++){
            if(set.count(s.substr(0,i+1)) && solve(s.substr(i+1), set)) return true;
        }
        return false;
    }

    bool solveMem(string s, unordered_set<string>& set, unordered_map<string,bool>& dp){
        if(s.length()==0) return true;

        if(dp.count(s)) return dp[s];

        for(int i=0;i<s.length();i++){
            if(set.count(s.substr(0,i+1)) && solveMem(s.substr(i+1), set, dp)) return dp[s] = true;
        }
        return dp[s]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        // return solve(s,set);
        unordered_map<string, bool> dp;
        return solveMem(s,set, dp);
    }
};
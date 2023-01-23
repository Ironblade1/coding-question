class Solution {
public:

    bool isPalindrome(string s, int i, int j){
        while(i<=j){
            if(s[i++]!=s[j--])  return false;
        }
        return true;
    }

    void solve(int ind,string s, vector<string> &ans,vector<vector<string>> &res){
        if(ind == s.length()){
            res.push_back(ans);
            return ;
        }
        for(int i=ind;i<s.length();i++){
            if(isPalindrome(s,ind,i)){
                ans.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ans,res);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        solve(0,s,ans,res);
        return res;
    }
};
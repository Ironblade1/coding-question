class Solution {
public:
    void solve(int l, int r, string s, vector<string>& ans){
        if(r==0 && l==0){
            ans.push_back(s);
            return ;
        }
        if(l>0){
            solve(l-1,r,s+'(',ans);
        }
        if(r>l){
            solve(l,r-1,s+')',ans);
        }      
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s ;
        solve(n,n,s,ans);
        return ans;
    }
};
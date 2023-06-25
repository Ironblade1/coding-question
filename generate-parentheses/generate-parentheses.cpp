class Solution {
public:
    void solve(int ind, int l, int r, int n, string& s, vector<string>& ans){
        if(ind == n){
            ans.push_back(s);
            return ;
        }
        if(l>0 ){
            s.push_back('(');
            solve(ind+1,l-1,r,n,s,ans);
            s.pop_back();
        }
        if(r>l){
            s.push_back(')');
            solve(ind+1,l,r-1,n,s,ans);
            s.pop_back();
        }      
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s ="(" ;
        solve(1,n-1,n,2*n,s,ans);
        return ans;
    }
};
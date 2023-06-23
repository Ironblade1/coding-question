class Solution {
public:
    void solve(int i,int j, int n,int k, vector<int>& vec, vector<vector<int>>& ans){
        if(i>=k){
            ans.push_back(vec);
            return ;
        }

        for(j;j<=n;j++){
            vec.push_back(j);
            solve(i+1,j+1,n,k,vec,ans);
            vec.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> vec;
        solve(0,1,n,k,vec, ans);
        return ans;    
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    void solve(vector<int>& cand, int t,vector<vector<int>> &res, vector<int> &ans,int i){

        if(t==0) {
            res.push_back(ans);
            return ;
        }
        while(i<cand.size() && t-cand[i]>=0){
            ans.push_back(cand[i]);
            solve(cand,t-cand[i],res,ans,i);
            
            ans.pop_back();
            i++;
        }
        return ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> ans;
        solve(candidates,target,res,ans,0);
        return res; 
    }
};
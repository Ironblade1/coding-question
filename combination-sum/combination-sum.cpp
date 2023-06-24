class Solution {
public:
    void solve(int i, int t, vector<int>& c, vector<int>& temp, vector<vector<int>>& ans){
        if(t==0){
            ans.push_back(temp);
            return ;
        }
        if(t<0) return ;

        while(i<c.size() && t-c[i]>=0){
            temp.push_back(c[i]);
            solve(i,t-c[i],c,temp,ans);
            temp.pop_back();
            i++;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,temp,ans);
        return ans;
    }
};
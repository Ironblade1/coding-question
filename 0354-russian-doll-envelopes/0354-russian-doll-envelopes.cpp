class Solution {
public:

    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }

    

    int solve(vector<vector<int>>& env,int n){
        vector<int> ans;
        ans.push_back(env[0][1]);

        for(int i=1;i<n;i++){
            if(env[i][1]>ans.back()){
                ans.push_back(env[i][1]);
            }
            else{
                int ind = lower_bound(ans.begin(),ans.end(),env[i][1]) - ans.begin();
                ans[ind] = env[i][1];
            }
        }

        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // step -1 sort the envelopes by their width and whose env. width will equal then sort in descending order  of their height
        sort(envelopes.begin(),envelopes.end(),compare);
        int n = envelopes.size();

        // step-2  find the longest increasing subsequence 
        return solve(envelopes, n);
    }
};
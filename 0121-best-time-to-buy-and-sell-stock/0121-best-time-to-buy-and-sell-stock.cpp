class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int n = prices.size();
        int mini = INT_MAX;;
        for(int i=0;i<n;i++){
            ans = max(ans,prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return ans;
    }
};
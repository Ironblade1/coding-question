class Solution {
public:
    int solve(vector<int>& prices, int fee, int ind, bool buy){
        if(ind == prices.size()) return 0;
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + solve(prices,fee,ind+1,0), 0 + solve(prices,fee,ind+1,1));   // buy  ,, //not buy
        }
        else{
            profit = max(prices[ind] - fee + solve(prices,fee,ind+1,1), 0 + solve(prices,fee,ind+1,0));  // sell,  // not sell
        }
        return profit;
    }

    int solveMem(vector<int>& prices, int fee, int ind, bool buy, vector<vector<int>>& dp){
        if(ind == prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if(buy){
            profit = max(-prices[ind]+ solveMem(prices, fee, ind+1, 0, dp), solveMem(prices, fee, ind+1, 1, dp));
        }
        else{
            profit = max(prices[ind] - fee + solveMem(prices, fee, ind+1, 1, dp), solveMem(prices,fee, ind+1, 0, dp));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        // return solve(prices,fee, 0, 1); // recursive 

        vector<vector<int>> dp(prices.size()+1, vector<int>(3,-1));
        return solveMem(prices, fee, 0 , 1, dp);
    }
};
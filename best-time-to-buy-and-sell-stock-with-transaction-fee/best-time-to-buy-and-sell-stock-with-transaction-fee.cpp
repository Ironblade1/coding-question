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

    int solveTab(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    profit = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }


    int maxProfit(vector<int>& prices, int fee) {
        // return solve(prices,fee, 0, 1); // recursive 

        vector<vector<int>> dp(prices.size()+1, vector<int>(3,-1));
        // return solveMem(prices, fee, 0 , 1, dp);

        return solveTab(prices, fee);
    }
};
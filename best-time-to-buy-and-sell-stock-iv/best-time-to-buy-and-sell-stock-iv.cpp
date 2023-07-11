class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int limit){
        if(i==prices.size()) return 0;
        if(limit==0) return 0;
        int profit = 0;

        if(!buy){
            int buykro = -prices[i] + solve(prices,i+1,1,limit);
            int skipkro = 0 + solve(prices,i+1,0,limit);
            profit = max(buykro, skipkro);
        }
        else{
            int sellkro = prices[i] + solve(prices,i+1,0,limit-1);
            int skipkro = 0 + solve(prices,i+1,1,limit);
            profit = max(sellkro, skipkro);
        }
        return profit;
    }

    int solveMem(vector<int>& prices, int i, int buy, int limit,  vector<vector<vector<int>>>& dp){
        if(i==prices.size()) return 0;
        if(limit==0) return 0;
        int profit = 0;

        if(dp[i][buy][limit]!=-1) return dp[i][buy][limit];

        if(!buy){
            int buykro = -prices[i] + solveMem(prices,i+1,1,limit, dp);
            int skipkro = 0 + solveMem(prices,i+1,0,limit, dp);
            profit = max(buykro, skipkro);
        }
        else{
            int sellkro = prices[i] + solveMem(prices,i+1,0,limit-1, dp);
            int skipkro = 0 + solveMem(prices,i+1,1,limit, dp);
            profit = max(sellkro, skipkro);
        }
        return dp[i][buy][limit] = profit;
    }

     int solveTab(vector<int>& prices){

        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));   // 3D - DP

        for(int index = n-1; index>=0; index--){
            for(int buy = 0; buy<=1; buy++){
                for(int limit=1; limit<=2; limit++){

                    int profit = 0;

                    if(buy){

                        profit = max( (-prices[index] + dp[index+1][0][limit]), 
                                    ( 0 + dp[index+1][1][limit]) );
                    }

                    // buy == 0
                    else{
                        profit = max( (+prices[index] + dp[index+1][1][limit-1]), 
                                    ( 0 + dp[index+1][0][limit]) );
                    }

                    dp[index][buy][limit] = profit;
                }
            }
        }

        return dp[0][1][2];
    }




    int maxProfit(int k, vector<int>& prices) {
        // return solve(prices, 0, 0, 2);
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solveMem(prices,0,0,k,dp);

        // return solveTab(prices);
    }
};
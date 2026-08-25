class Solution {
public:
    int solve(vector<int>& prices, vector<vector<vector<int>>>& dp, int buy, int idx, int k) {
        if (idx >= prices.size() || k == 0) return 0;
        if (dp[idx][buy][k] != -1) return dp[idx][buy][k];

        int profit = 0;

        if (buy) {
            profit = max(-prices[idx] + solve(prices, dp, 0, idx + 1, k), 
                          0 + solve(prices, dp, 1, idx + 1, k));
        } else {
           
            profit = max(prices[idx] + solve(prices, dp, 1, idx + 1, k - 1), 
                         0 + solve(prices, dp, 0, idx + 1, k));
        }

        return dp[idx][buy][k] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
       
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices, dp, 1, 0, k);
    }
};
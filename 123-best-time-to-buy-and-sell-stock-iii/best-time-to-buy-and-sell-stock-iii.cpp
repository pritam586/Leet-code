class Solution {
public:
    int cal(vector<int>& prices, int idx, int buy, int n,
            vector<vector<vector<int>>>& dp, int cap) {
        
        if (idx == n || cap == 0) return 0;

        if (dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

        int profit = 0;

        if (buy) {
            profit = max(
                -prices[idx] + cal(prices, idx + 1, 0, n, dp, cap),
                cal(prices, idx + 1, 1, n, dp, cap)
            );
        } else {
            profit = max(
                prices[idx] + cal(prices, idx + 1, 1, n, dp, cap - 1),
                cal(prices, idx + 1, 0, n, dp, cap)
            );
        }

        return dp[idx][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return cal(prices, 0, 1, n, dp, 2);
    }
};
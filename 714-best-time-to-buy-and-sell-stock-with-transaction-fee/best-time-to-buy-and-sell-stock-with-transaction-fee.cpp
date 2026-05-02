class Solution {
public:
    int cal(vector<int>& prices ,  vector<vector<int>> &dp ,int n, int fee , int i , int buy ){
        
        if(i==n) return 0;
        int profit = 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            profit = max(
                -prices[i]+cal(prices , dp , n , fee , i+1 , 0),
                cal(prices , dp , n , fee , i+1 , 1)
                );
        }else{
            profit = max(
                -fee+prices[i]+cal(prices , dp , n , fee , i+1 , 1),
                cal(prices , dp , n , fee , i+1 , 0)
                );
        }
        return dp[i][buy] = profit;
    } 
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector(2 , -1));
        return cal(prices , dp ,n, fee , 0 ,1);
    }
};
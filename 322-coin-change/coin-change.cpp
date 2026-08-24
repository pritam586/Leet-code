class Solution {
public:
    int cal(vector<int>& coins, int amount , vector<int> & dp){
         if (amount == 0)
            return 0;

        if (amount < 0)
            return INT_MAX;

              if (dp[amount] != -1)
            return dp[amount];

        int mini = INT_MAX;

       for(auto coin:coins){
         int value = cal(coins , amount-coin , dp);
         if(value!=INT_MAX){
            mini = min(mini , 1+value);
         }
       }
       return dp[amount] =  mini;
    }
    int coinChange(vector<int>& coins, int amount) {
         vector<int> dp(amount + 1, -1);

        int ans = cal(coins, amount, dp);

        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};
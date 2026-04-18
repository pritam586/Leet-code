class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1) return 0;

        vector<int> minCoinDP(amount+1);

        for(int i = 1; i <= amount ; i++){
            minCoinDP[i] = INT_MAX;
            for(auto coin : coins){
                if(coin<=i && minCoinDP[i-coin]!=INT_MAX){
                    minCoinDP[i] = min(minCoinDP[i] ,  1+minCoinDP[i-coin]);
                }
            }
        }

        if(minCoinDP[amount]==INT_MAX) return -1;

        return minCoinDP[amount];
    }
};
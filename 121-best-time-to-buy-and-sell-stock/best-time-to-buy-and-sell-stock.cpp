class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0 , bestBuy = prices[0];
        for(int i=0 ; i< size(prices) ; i++){
            int profix = prices[i] - bestBuy;
            maxProfit = max(maxProfit , prices[i] - bestBuy);
           
            bestBuy = min(bestBuy , prices[i]);
        }
        return maxProfit;
    }
};
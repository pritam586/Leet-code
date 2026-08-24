class Solution {
public:
    int cal(int n , vector<int>& dp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
         if (dp[n] != -1) return dp[n];
        int first = cal(n-1 , dp);
        int second = cal(n-2 , dp);
       
        return dp[n] = first + second;

    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        int ans = cal(n , dp);
        return ans;
    }
};
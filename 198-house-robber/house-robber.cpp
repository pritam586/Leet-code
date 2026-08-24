class Solution {
public:
    int cal(vector<int>& nums , int sum , vector<int>& dp , int idx , int n){
        if(idx>=n) return 0;

        if(dp[idx]!=-1) return dp[idx];
        int take = nums[idx]+cal(nums , sum , dp , idx+2 , n);
        int nottake = cal(nums , sum , dp , idx+1 , n);
        return dp[idx] = max(take , nottake);
    }
    int rob(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        vector<int> dp(n , -1);

        return cal(nums , sum , dp , 0 , n);
    }
};
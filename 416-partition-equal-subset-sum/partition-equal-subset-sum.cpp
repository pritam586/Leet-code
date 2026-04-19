class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }

        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};

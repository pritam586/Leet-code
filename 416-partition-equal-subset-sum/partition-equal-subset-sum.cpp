class Solution {
public:
    bool solve(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        // target achieved
        if(sum == 0) return true;

        // no elements left
        if(idx == nums.size()) return false;

        // memo
        if(dp[idx][sum] != -1) return dp[idx][sum];

        bool take = false;
        if(nums[idx] <= sum){
            take = solve(idx + 1, sum - nums[idx], nums, dp);
        }

        bool skip = solve(idx + 1, sum, nums, dp);

        return dp[idx][sum] = take || skip;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int x : nums) total += x;

        if(total % 2 != 0) return false;

        int target = total / 2;

        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return solve(0, target, nums, dp);
    }
};
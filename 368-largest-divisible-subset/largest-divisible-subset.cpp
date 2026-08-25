class Solution {
public:

    int solve(vector<int>& nums, int idx, int prevIdx,
              vector<vector<int>>& dp) {

        // Base case
        if (idx == nums.size()) {
            return 0;
        }

        if (dp[idx][prevIdx + 1] != -1)
            return dp[idx][prevIdx + 1];

        // Skip
        int skip = solve(nums, idx + 1, prevIdx, dp);

        // Take
        int take = 0;

        if (prevIdx == -1 || nums[idx] % nums[prevIdx] == 0) {
            take = 1 + solve(nums, idx + 1, idx, dp);
        }

        return dp[idx][prevIdx + 1] = max(take, skip);
    }


    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        solve(nums, 0, -1, dp);

        // Reconstruct answer
        vector<int> ans;

        int idx = 0;
        int prevIdx = -1;

        while (idx < n) {

            int skip = solve(nums, idx + 1, prevIdx, dp);

            int take = -1;

            if (prevIdx == -1 || nums[idx] % nums[prevIdx] == 0) {
                take = 1 + solve(nums, idx + 1, idx, dp);
            }

            if (take >= skip) {
                ans.push_back(nums[idx]);
                prevIdx = idx;
            }

            idx++;
        }

        return ans;
    }
};
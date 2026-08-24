class Solution {
public:
    int cal(int m, int n, vector<vector<int>>& dp, int row, int col) {
        // Out of boundary
        if (row >= m || col >= n)
            return 0;

        // Reached destination
        if (row == m - 1 && col == n - 1)
            return 1;

        if (dp[row][col] != -1)
            return dp[row][col];

        int down = cal(m, n, dp, row + 1, col);
        int right = cal(m, n, dp, row, col + 1);

        return dp[row][col] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return cal(m, n, dp, 0, 0);
    }
};
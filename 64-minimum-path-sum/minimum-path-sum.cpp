class Solution {
public:
    int cal(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp, int row, int col) {
        if (row >= m || col >= n) return 1e9; // Out-of-bounds check returns a large value to prevent overflow
        if (row == m - 1 && col == n - 1) return grid[row][col];
        if (dp[row][col] != -1) return dp[row][col];

        int left = grid[row][col] + cal(grid, m, n, dp, row + 1, col);
        int bottom = grid[row][col] + cal(grid, m, n, dp, row, col + 1);

        return dp[row][col] = min(left, bottom);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return cal(grid, m, n, dp, 0, 0);
    }
};
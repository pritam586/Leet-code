class Solution {
public:
    int cal(vector<vector<int>>& obstacleGrid , int m, int n, vector<vector<int>>& dp, int row, int col) {
        // Out of boundary
        if (row >= m || col >= n || obstacleGrid[row][col] ==1)
            return 0;

        // Reached destination
        if (row == m - 1 && col == n - 1)
            return 1;
     

        if (dp[row][col] != -1)
            return dp[row][col];

        int down = cal(obstacleGrid,m, n, dp, row + 1, col);
        int right = cal(obstacleGrid,m, n, dp, row, col + 1);

        return dp[row][col] = down + right;
    }

   
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n=obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return cal(obstacleGrid , m , n , dp , 0 , 0 );
    }
};
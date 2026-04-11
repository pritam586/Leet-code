class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // boundary check + water check
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
            return;

        // mark visited
        grid[i][j] = '0';

        // explore 4 directions
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;        // found new island
                    dfs(grid, i, j); // mark whole island
                }
            }
        }

        return count;
    }
};
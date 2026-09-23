class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<pair<int, int>, int>> q;

        // Put all rotten oranges into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {   // ❌ you had i < n

                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});   // ❌ syntax
                    vis[i][j] = 2;
                }
            }
        }

        int tm = 0;

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();

            tm = max(tm, t);

            for(int i = 0; i < 4; i++) {

                int nr = r + delr[i];      // ❌ you had i + r
                int nc = c + delc[i];      // ❌ you had i + c

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   vis[nr][nc] != 2 &&
                   grid[nr][nc] == 1) {

                    vis[nr][nc] = 2;

                    q.push({{nr, nc}, t + 1});
                }
            }
        }

        // Check if any fresh orange remains
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1 && vis[i][j] != 2)
                    return -1;
            }
        }

        return tm;
    }
};
class Solution {
public:

    vector<int> parent, sz;

    int findParent(int u) {
        if (u == parent[u])
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void unionSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u == v)
            return;

        // Union by size
        if (sz[u] < sz[v])
            swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        parent.resize(n * n);
        sz.assign(n * n, 1);

        // Initially every cell is its own parent
        for (int i = 0; i < n * n; i++) {
            parent[i] = i;
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // ------------------------------------------------
        // STEP 1: Build connected components of 1s
        // ------------------------------------------------

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0)
                    continue;

                int current = i * n + j;

                for (int k = 0; k < 4; k++) {

                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < n &&
                        nj >= 0 && nj < n &&
                        grid[ni][nj] == 1) {

                        int neighbor = ni * n + nj;

                        unionSet(current, neighbor);
                    }
                }
            }
        }

        // ------------------------------------------------
        // STEP 2: Try converting every 0 into 1
        // ------------------------------------------------

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1)
                    continue;

                // Store unique island parents
                set<int> uniqueIslands;

                for (int k = 0; k < 4; k++) {

                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && ni < n &&
                        nj >= 0 && nj < n &&
                        grid[ni][nj] == 1) {

                        int parentIsland = findParent(ni * n + nj);

                        uniqueIslands.insert(parentIsland);
                    }
                }

                int newSize = 1;

                for (int island : uniqueIslands) {
                    newSize += sz[island];
                }

                ans = max(ans, newSize);
            }
        }

        // ------------------------------------------------
        // Special case:
        // grid contains no 0
        // ------------------------------------------------

        if (ans == 0) {
            for (int i = 0; i < n * n; i++) {
                if (grid[i / n][i % n] == 1) {
                    ans = max(ans, sz[findParent(i)]);
                }
            }
        }

        return ans;
    }
};
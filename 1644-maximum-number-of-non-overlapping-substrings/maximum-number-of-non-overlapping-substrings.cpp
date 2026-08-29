class Solution {
public:
    vector<string> maxNumOfSubstrings(string S) {
        vector<int> mins(26, INT_MAX);
        vector<int> maxs(26, -1);
        vector<bool> exists(26, false);
        int n = S.length();
        
        // prefixSum[i][j]: count of character j in prefix S[0...i-1]
        vector<vector<int>> prefixSum(n + 1, vector<int>(26, 0));
        
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i];
            int charIdx = S[i] - 'a';
            prefixSum[i + 1][charIdx]++;
            mins[charIdx] = min(mins[charIdx], i);
            maxs[charIdx] = max(maxs[charIdx], i);
            exists[charIdx] = true;
        }

        // Build graph using adjacency matrix
        vector<vector<bool>> graph(26, vector<bool>(26, false));
        for (int i = 0; i < 26; i++) {
            if (exists[i]) {
                for (int j = 0; j < 26; j++) {
                    if (prefixSum[maxs[i] + 1][j] - prefixSum[mins[i]][j] > 0) {
                        graph[i][j] = true;
                    }
                }
            }
        }

        // Step 1 of Kosaraju: Fill stack based on finish times
        stack<int> st;
        vector<bool> visited(26, false);
        for (int i = 0; i < 26; i++) {
            if (exists[i] && !visited[i]) {
                dfs1(i, graph, st, visited);
            }
        }

        // Step 2 of Kosaraju: Process nodes in order defined by stack on transposed graph
        int batch = 0;
        vector<int> batches(26, -1);
        vector<int> degree(26, 0);

        while (!st.empty()) {
            int v = st.top();
            st.pop();
            if (batches[v] < 0) {
                dfs2(v, graph, batches, batch, degree);
                batch++;
            }
        }

        // Collect substrings for valid SCCs with 0 out-degree
        vector<string> res;
        for (int i = batch - 1; i >= 0; i--) {
            if (degree[i] == 0) {
                int mn = INT_MAX, mx = -1;
                for (int j = 0; j < 26; j++) {
                    if (batches[j] == i) {
                        mn = min(mn, mins[j]);
                        mx = max(mx, maxs[j]);
                    }
                }
                res.push_back(S.substr(mn, mx - mn + 1));
            }
        }

        return res;
    }

private:
    void dfs1(int v, const vector<vector<bool>>& graph, stack<int>& st, vector<bool>& visited) {
        if (!visited[v]) {
            visited[v] = true;
            for (int i = 0; i < 26; i++) {
                if (graph[v][i] && !visited[i]) {
                    dfs1(i, graph, st, visited);
                }
            }
            st.push(v);
        }
    }

    void dfs2(int v, const vector<vector<bool>>& graph, vector<int>& batches, int batch, vector<int>& degree) {
        if (batches[v] < 0) {
            batches[v] = batch;
            for (int i = 0; i < 26; i++) {
                if (graph[i][v]) { // Reverse edge lookup
                    dfs2(i, graph, batches, batch, degree);
                }
            }
        } else {
            if (batches[v] != batch) {
                degree[batches[v]]++;
            }
        }
    }
};
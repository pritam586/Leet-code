class Solution {
public:
    void traverse(int st, vector<vector<int>>& adj, vector<bool>& isVisited) {
        queue<int> q;
        q.push(st);
        isVisited[st] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (!isVisited[it]) {
                    isVisited[it] = true;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> isVisited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!isVisited[i]) {
                traverse(i, adj, isVisited);
                count++;
            }
        }

        return count;
    }
};
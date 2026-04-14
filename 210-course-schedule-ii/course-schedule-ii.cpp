class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
          vector<vector<int>> adj(v);

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // Step 2: Indegree array
        vector<int> indegree(v, 0);

        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Step 3: Queue for BFS
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 4: Topological sort
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Step 5: Check if valid topo sort
        if (topo.size() == v) return topo;

        return {}; // cycle exists
    }
};
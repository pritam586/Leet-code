class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<pair<int, int>> adj[n];

        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;

        vector<int> dist(n, 1e9);

        dist[src] = 0;
        q.push({0, {src, 0}});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stop > k)
                continue;

            for (auto x : adj[node]) {

                int adjNode = x.first;
                int edgeWt = x.second;

                if (cost + edgeWt < dist[adjNode]) {

                    dist[adjNode] = cost + edgeWt;
                    q.push({stop + 1, {adjNode, cost + edgeWt}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};
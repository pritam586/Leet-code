class Solution {
public:

    vector<int> parent, size;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (size[a] < size[b])
            swap(a, b);

        parent[b] = a;
        size[a] += size[b];
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        // Not enough cables
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Connect computers using existing cables
        for (auto &edge : connections) {
            unite(edge[0], edge[1]);
        }

        // Count separate components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        // Need components - 1 cables to connect them
        return components - 1;
    }
};
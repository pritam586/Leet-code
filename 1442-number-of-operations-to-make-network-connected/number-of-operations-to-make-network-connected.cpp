class Solution {
public:
    int ultParnt(int u, vector<int>& parent) {
        if (u == parent[u]) {
            return u;
        }
        return ultParnt(parent[u], parent);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> siz, parent;

        siz.resize(n, 1);
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int count = 0;

        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];

            int ultp_u = ultParnt(u, parent);
            int ultp_v = ultParnt(v, parent);

            int sizu = siz[ultp_u];
            int sizv = siz[ultp_v];

            if (ultp_u == ultp_v) {
                count++;
            }
            else if (sizu < sizv) {
                parent[ultp_u] = ultp_v;
                siz[ultp_v] += siz[ultp_u];
            }
            else {
                parent[ultp_v] = ultp_u;
                siz[ultp_u] += siz[ultp_v];
            }
        }

        int components = 0;

        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                components++;
            }
        }

        if (count >= components - 1) {
            return components - 1;
        }

        return -1;
    }
};
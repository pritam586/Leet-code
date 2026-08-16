class Solution {
public:

    int findParent(int u, vector<int>& parent) {
        if (u == parent[u])
            return u;

        return parent[u] = findParent(parent[u], parent);
    }

    void unionSet(int u, int v, vector<int>& parent) {
        u = findParent(u, parent);
        v = findParent(v, parent);

        if (u != v) {
            parent[v] = u;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        vector<int> parent(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // email -> account index
        map<string, int> mp;

        // Step 1: connect accounts having common emails
        for (int i = 0; i < n; i++) {

            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (mp.find(email) == mp.end()) {

                    mp[email] = i;

                } else {

                    unionSet(i, mp[email], parent);
                }
            }
        }

        // Step 2: parent -> sorted emails
        map<int, set<string>> merged;

        for (auto it : mp) {

            string email = it.first;
            int accountIndex = it.second;

            int parentIndex = findParent(accountIndex, parent);

            merged[parentIndex].insert(email);
        }

        // Step 3: construct answer
        vector<vector<string>> ans;

        for (auto it : merged) {

            int accountIndex = it.first;

            vector<string> temp;

            // Name
            temp.push_back(accounts[accountIndex][0]);

            // Emails are already sorted because of set
            for (auto email : it.second) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};